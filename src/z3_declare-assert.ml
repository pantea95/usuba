open Usuba_AST
open Utils
open Printf

let make_int_list (n:int) : int list =
  let rec aux i acc =
    if i = 0 then acc
    else aux (i-1) (i :: acc) in
  aux n []

let p_to_int_list (p:p) : int list =
  List.flatten @@
    List.map (fun (_,typ,_) -> match typ with
                               | Bool -> [1]
                               | Int n -> make_int_list n
                               | _ -> raise (Not_implemented "")) p

module Shared = struct
  let get_vars (def:def) : p =
    match def.node with
    | Single(vars,_) -> vars
    | _ -> raise (Error "Non-single node")
  let get_body (def:def) : deq list =
    match def.node with
    | Single(_,body) -> body
    | _ -> raise (Error "Non-single node")
                 
  let rec e_to_z3 clean_name rename (e:expr) : string =
    let e_to_z3 = e_to_z3 clean_name rename in
    match e with
    | Const b -> sprintf "%b" (b = 1)
    | ExpVar(Var v) -> sprintf "%s" (clean_name v)
    | Not(e) -> sprintf "(not %s )" (e_to_z3 e)
    | Log(And,x,y)  -> sprintf "(and %s %s)" (e_to_z3 x) (e_to_z3 y)
    | Log(Or,x,y)   -> sprintf "(or %s %s)" (e_to_z3 x) (e_to_z3 y)
    | Log(Xor,x,y)  -> sprintf "(xor %s %s)" (e_to_z3 x) (e_to_z3 y)
    | Log(Andn,x,y) -> sprintf "(and (not %s) %s)" (e_to_z3 x) (e_to_z3 y)
    | Fun(f,l)    -> sprintf "(%s-%s %s)" (rename f) "0" (join " "
                                                               (List.map e_to_z3 l))
    | _ -> raise (Not_implemented (Usuba_print.expr_to_str e))
                 
  let asgn_to_z3 (p:var list) (e:expr) clean_name rename get_var_id : string =
    match p with
    (* A single variable (=> the expr is "simple" *)
    | [ Var v ] -> sprintf "(= %s %s)" (clean_name v) (e_to_z3 clean_name rename e)
    (* Several variables (=> the expr is a function call *)
    | _ -> match e with
           | Fun(f,l) ->
              sprintf "(and %s)"
                      (join " "
                            (List.mapi
                               (fun i v ->
                                sprintf "(= %s (%s-%d %s))" (get_var_id v)
                                        (rename f) i
                                        (join " "
                                              (List.map
                                                 (e_to_z3 clean_name rename) l))) p))
           | _ -> unreached ()
                            
  let z3_node (def:def) clean_name rename get_var_id : string =
    let f_id     = rename def.id in
    let in_list  = List.map (fun (id,_,_) -> clean_name id) def.p_in in
    let out_list = List.map (fun (id,_,_) -> clean_name id) def.p_out in
    let bool_in  = join " " (List.map (fun _ -> "Bool") in_list) in
    let var_list = List.map (fun (id,_,_) -> clean_name id) (get_vars def) in
    let body     = get_body def in
    
    (* declaring functions *)
    (join "\n"
          (List.mapi (fun i _ ->
                      sprintf "(declare-fun %s-%d (%s) Bool)"
                              f_id i bool_in) out_list)) ^
      "\n" ^ 
        (* The body *)
        (sprintf
"(assert (forall (%s %s)
            (= (and %s)
                %s)))"
(join " " (List.map (fun id -> sprintf "(%s Bool)" id) out_list))
(join " " (List.map (fun id -> sprintf "(%s Bool)" id) in_list))
(join "\n                    "
      (List.mapi (fun i x -> sprintf "(= (%s-%d %s) %s)"
                                     f_id i (join " " in_list) x) out_list))
(if is_empty var_list then
   sprintf "(and %s)" (join "\n                            "
                            (List.map (function
                                        | Norec(p,e) -> asgn_to_z3 p e
                                                                   clean_name
                                                                   rename
                                                                   get_var_id
                                        | _ -> unreached ()) body))
 else
   sprintf "(exists (%s)
            (and %s))"
           (join " " (List.map (fun id -> sprintf "(%s Bool)" id) var_list))
           (join "\n                         "
                 (List.map (function
                             | Norec(p,e) -> asgn_to_z3 p e clean_name rename get_var_id
                             | _ -> unreached ()) body)))
        )
end
                  
module Usuba0 = struct
  let clean_name (name:string) : string =
    Str.global_replace (Str.regexp "'") "__" name
  let rename (id:ident) : ident = "ua0-" ^ (clean_name id)


  let get_var_id (v:var) : string =
    match v with
    | Var id -> clean_name id
    | _ -> raise (Error "Non-var")
           
  let z3_node (def:def) : string =
    Shared.z3_node def clean_name rename get_var_id
                                             
                                             
  let rec z3_def (def:def) : string =
    match def.node with
    | Single(vars,body) -> z3_node def
    | _ -> unreached ()
        
  let gen_z3 (prog:prog) : string =
    join "\n" (List.map z3_def prog.nodes)
         
end 
                  
module Usuba = struct

  let clean_name (name:string) : string =
    Str.global_replace (Str.regexp "'") "__" name
  let rename (id:ident) : ident = "std-" ^ (clean_name id)

  let get_var_id (v:var) : string =
    match v with
    | Var id -> clean_name id
    | _ -> raise (Error "Non-var")

  let z3_node (def:def) : string =
    Shared.z3_node def clean_name rename get_var_id    

          
                                             
  let z3_table (def:def) (l:int list) : string =
    let id = rename def.id in
    let int_to_idx (n:int) (size:int): bool list =
      let res = ref [] in
      for i = size-1 downto 0 do
        res := (n lsr i land 1 = 1) :: !res
      done;
      !res in
    let int_l_in = p_to_int_list def.p_in in
    let int_l_out = p_to_int_list def.p_out in
    let size_in = List.length int_l_in in
    let size_out = List.length int_l_out in
    (join "\n" (List.mapi (fun i _ -> sprintf
"(declare-fun %s-%d (%s) Bool)" id i
(join " " (List.map (fun _ -> "Bool") int_l_in)))
                          int_l_out)) ^
      "\n" ^
        (join "\n"
              (List.mapi
                 (fun i x ->
                  let booleans = join " " (List.map
                                             (sprintf "%B")
                                             (List.rev (int_to_idx i size_in))) in
                  join "\n"
                       (List.mapi
                          (fun i x -> sprintf "(assert (= (%s-%d %s) %B))"
                                              id i booleans x)
                                              (List.rev (int_to_idx x size_out)))) l))

        
  let z3_perm (def:def) (l:int list) : string =
    let id = rename def.id in
    let int_l = p_to_int_list def.p_in in
    let param_l = join " " (List.map (fun _ -> "Bool") int_l) in
    let args = join " " (List.mapi (fun i _ -> sprintf "i-%d" i) int_l) in
    (join "\n" (List.mapi (fun i x -> sprintf "(declare-fun %s-%d (%s) Bool)"
                                              id i param_l) l))
    ^
      (sprintf "\n(assert (forall (%s)\n         (and\n"
               (join " " (List.mapi (fun i _ -> sprintf "(i-%d Bool)" i) int_l)))
    ^
      (join "\n" (List.mapi (fun i x -> sprintf "           (= (%s-%d %s) i-%d)"
                                                id i args (x-1)) l))
    ^ ")))\n"
                                          
  let rec z3_def env_fun (def:def) : string =
    let converted = 
      match def.node with
      | Single(vars,body) -> z3_node def
      | Multiple l ->
         join "\n" (List.mapi
                    (fun i (v,b) ->
                     z3_def env_fun { def with id = def.id ^ (string_of_int i);
                                               node = Single(v,b) }) l)
      | Perm l -> z3_perm def l
      | MultiplePerm l ->
         join "\n" (List.mapi
                    (fun i l' ->
                     z3_def env_fun { def with id = def.id ^ (string_of_int i);
                                               node = Perm l'}) l)
      | Table l -> z3_table def l
      | MultipleTable l ->
         join "\n" (List.mapi
                    (fun i l' ->
                     z3_def env_fun { def with id = def.id ^ (string_of_int i);
                                               node = Table l'}) l)
    in
    converted

  let norm_def env_fun (def:def) : def =
    (* remove tuples of 1 elt *)
    Norm_tuples.Simplify_tuples.simpl_tuples_def @@
      (* explode tuples *)
      Norm_tuples.Split_tuples.split_tuples_def @@
        (* apply shifts *)
        Bitslice_shift.shift_def @@
          (* remove tuples of 1 elt *)
          Norm_tuples.Simplify_tuples.simpl_tuples_def @@
            (* explode tuples *)
            Norm_tuples.Split_tuples.split_tuples_def @@
              (* remove nested function calls *)
              Norm_bitslice.norm_def_z3 env_fun @@
                (* remove uintn *)
                Norm_uintn.norm_def @@
                  (* expand constants *)
                  Expand_const.expand_def @@
                    (* remove arrays *)
                    Expand_array.expand_def def
                                          
  let gen_z3 (prog:prog) : string =
    let env_fun = Hashtbl.create 100 in
    let nodes = List.map (norm_def env_fun) prog.nodes in
    let env_fun = Hashtbl.create 100 in
    join "\n" (List.map (z3_def env_fun) nodes)
    
    
end


let gen_z3 (prog:prog) : string =
  let normed = Normalize.norm_prog prog in
  let ua0 = Usuba0.gen_z3 normed in
  let ua  = Usuba.gen_z3 prog in

  let p_in  = (last normed.nodes).p_in in
  let p_out = (last normed.nodes).p_out in
  let std_id = Usuba.rename (last prog.nodes).id in
  let ua0_id = Usuba0.rename (last normed.nodes).id in
  let arg_list = join " " (List.mapi (fun i _ -> sprintf "i-%d" i) p_in) in
  
  sprintf
"%s

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

%s

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(assert (forall (%s)
          (and %s)))

(check-sat)
"
ua0 ua
(join " " (List.mapi (fun i _ -> sprintf "(i-%d Bool)" i) p_in))
(join "\n               "
      (List.mapi (fun i _ -> sprintf "(= (%s-%d %s) (%s-%d %s))"
                                     std_id i arg_list
                                     ua0_id i arg_list) p_out))