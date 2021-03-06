open Usuba_AST
open Basic_utils
       
exception Invalid_AST of string
exception Error of string
exception Syntax_error
exception Not_implemented of string
exception Empty_list
exception Undeclared of ident
exception Invalid_param_size
exception Invalid_operator_call
exception Break
            
let default_conf : config =
  { block_size   = 64;
    key_size     = 64;
    warnings     = true;
    verbose      = 1;
    verif        = false;
    type_check   = true;
    clock_check  = true;
    check_tbl    = false;
    inlining     = true;
    inline_all   = false;
    cse_cp       = true;
    scheduling   = true;
    schedule_n   = 10;
    share_var    = false;
    precal_tbl   = true;
    runtime      = true;
    archi        = Std;
    bits_per_reg = 64;
    bench        = false;
    rand_input   = false;
    ortho        = true;
    openmp       = 1;
    no_arr       = false;
    no_arr_tmp   = false;
    arr_entry    = true;
    unroll       = false;
    interleave   = 1;
    fd           = false;
    ti           = 1;
    fdti         = "";
    lazylift     = false;
    slicing_set  = false;
    slicing_type = B;
    secure_loops = false;
  }

let default_dir = Varslice { uid = -1; name = "D" }
let default_m   = Mvar     { uid = -1; name = "m" }

let bool = Uint(Bslice, Mint 1, 1)
    
let make_env () = Hashtbl.create 100
let env_add env v e = Hashtbl.replace env v e
let env_update env v e = Hashtbl.replace env v e
let env_remove env v = Hashtbl.remove env v
let env_fetch env v = try Hashtbl.find env v
                      with Not_found -> raise (Error (__LOC__ ^ ":Not found: " ^ v.name))

      
let rec eval_arith env (e:Usuba_AST.arith_expr) : int =
  match e with
  | Const_e n -> n
  | Var_e id  -> Hashtbl.find env id
  | Op_e(op,x,y) -> let x' = eval_arith env x in
                    let y' = eval_arith env y in
                    match op with
                    | Add -> x' + y'
                    | Mul -> x' * y'
                    | Sub -> x' - y'
                    | Div -> x' / y'
                    | Mod -> if x' >= 0 then x' mod y' else y' + (x' mod y')

let eval_arith_ne (e:Usuba_AST.arith_expr) : int =
  eval_arith (Hashtbl.create 100) e
             
(* Evaluates the arithmetic expression as much as possible: if the variables are
in the environment, then replaces them by their values, otherwise let them as is. *)
let rec simpl_arith (env:(ident,int) Hashtbl.t) (e: arith_expr) : arith_expr =
  match e with
  | Const_e n -> e
  | Var_e id  -> (try Const_e (Hashtbl.find env id)
                  with Not_found -> Var_e id)
  | Op_e(op,x,y) -> let x' = simpl_arith env x in
                    let y' = simpl_arith env y in
                    match x', y' with
                    | Const_e n1, Const_e n2 ->
                       Const_e (match op with
                                | Add -> n1 + n2
                                | Mul -> n1 * n2
                                | Sub -> n1 - n2
                                | Div -> n1 / n2
                                | Mod -> if n1 >= 0 then n1 mod n2 else n2 + (n1 mod n2))
                    | _ -> Op_e(op,x',y')
let simpl_arith_ne (e:arith_expr) : arith_expr =
  simpl_arith (Hashtbl.create 100) e
                               

let fresh_ident (name: string): ident =
  (* XXX: glue code, not actually maintaining a freshness of uid *)
  { uid = -1 ; name = name }

let fresh_suffix (id: ident)(suff: string): ident =
  fresh_ident (id.name ^ suff)

let fresh_prefix (pref: string)(id: ident): ident =
  fresh_ident (pref ^ id.name)

let fresh_concat (x: ident)(y: ident): ident =
  fresh_ident (x.name ^ y.name)

let gen_list (id: string) (n: int) : string list =
  let rec aux n acc =
    if n <= 0 then acc
    else aux (n-1) ((id ^ (string_of_int n))::acc) 
  in aux n []
let gen_list0 (id: string) (n: int) : string list =
  let rec aux n acc =
    if n <= 0 then acc
    else aux (n-1) ((id ^ (string_of_int (n-1)))::acc) 
  in aux n []

let gen_list_0 (id: ident) (n: int) : ident list =
  let rec aux n acc =
    if n <= 0 then acc
    else aux (n-1) (fresh_suffix id (string_of_int (n-1))::acc)
  in aux n []

let gen_list_int (n: int) : int list =
  let rec aux n acc =
    if n <= 0 then acc
    else aux (n-1) (n :: acc)
  in aux n []
         
let gen_list_0_int (n: int) : int list =
  let rec aux n acc =
    if n <= 0 then acc
    else aux (n-1) ((n-1) :: acc)
  in aux n []

let make_var_d (id:ident) (typ:typ) (ck:clock) (opts:var_d_opt list) =
  { vid   = id;
    vtyp  = typ;
    vck   = ck;
    vopts = opts }

let simple_var_d (id:ident) = make_var_d id bool Defclock []
         
let env_fetch env v =
  (* try *)
    Hashtbl.find env v
  (* with Not_found -> Printf.fprintf stderr "Not found: %s.\n" v.name; *)
  (*                   assert false *)


(* Constructs a map { fun : def } *)
let build_env_fun (nodes:def list) : (ident,def) Hashtbl.t =
  let env_fun = Hashtbl.create 20 in
  List.iter (fun d -> Hashtbl.add env_fun d.id d) nodes;
  env_fun
  
                          
(* Constructs a map { variables : types } *)
let build_env_var (p_in:p) (p_out:p) (vars:p) : (ident, typ) Hashtbl.t =
  let env = make_env () in

  let add_to_env (vd:var_d) : unit =
    env_add env vd.vid vd.vtyp in
  
  List.iter add_to_env p_in;
  List.iter add_to_env p_out;
  List.iter add_to_env vars;

  env
                          
let rec typ_size (t:typ) : int =
  match t with
  | Uint(_,_,n) -> n
  | Array(t',s) -> (typ_size t') * s
  | Nat -> 1
             
let rec reg_size (t:typ) : int =
  match t with
  | Uint(_,Mint i,1) -> i
  | _ -> Printf.fprintf stderr "Non linear type `%s', can't get reg_size.\n"
                        (Usuba_print.typ_to_str t);
         assert false
                        
                        
let elem_size (t:typ) : int =
  match t with
  | Array(t',_) -> typ_size t'
  | _ -> assert false
                 
let rec get_var_type env (v:var) : typ =
  match v with
  | Var x -> env_fetch env x
  | Index(v',_) -> (match get_var_type env v' with
                    | Array(t,_) -> t
                    | Uint(dir,m,n) -> Uint(dir,m,1)
                    | _ -> assert false)
  | _ -> Printf.fprintf stderr "Error: get_var_type(%s)\n" (Usuba_print.var_to_str v);
         assert false

let get_var_size env (v:var) : int =
  typ_size @@ get_var_type env v

let rec get_expr_size env (e:expr) : int =
  match e with
  | Const _ -> 1
  | ExpVar v -> get_var_size env v
  | Tuple l -> List.fold_left (+) 0 (List.map (get_expr_size env) l)
  | Not e -> get_expr_size env e
  | Shift(_,e,_) -> get_expr_size env e
  | Log(_,e,_) -> get_expr_size env e
  | Shuffle(v,_) -> get_var_size env v
  | Arith(_,e,_) -> get_expr_size env e
  | Fun _ -> Printf.fprintf stderr "Not implemented yet, get_expr_size(Fun...).\n";
             assert false
  | _ -> assert false
              

let get_reg_size env (v:var) : int =
  reg_size @@ get_var_type env v
                           
let rec get_expr_reg_size env (e:expr) : int =
  match e with
  | Const n -> Printf.fprintf stderr "Unsafe inference of `Const %d' size.\n" n;
               1
  | ExpVar v -> get_reg_size env v
  | Not e -> get_expr_reg_size env e
  | Shift(_,e,_) -> get_expr_reg_size env e
  | Log(_,e,_) -> get_expr_reg_size env e
  | Shuffle(v,_) -> get_reg_size env v
  | Arith(_,e,_) -> get_expr_reg_size env e
  | Fun _ -> Printf.fprintf stderr "Not implemented yet, get_reg_size(Fun...).\n";
             assert false
  | Tuple l -> Printf.fprintf stderr "Non linear expression Tuple(%s), can't get reg_size.\n"
                              (Usuba_print.expr_to_str_l l);
               assert false
               
  | _ -> assert false

let rec get_expr_type env_fun env_var (e:expr) : typ list =
  match e with
  | Const n -> Printf.fprintf stderr "Unsafe inference of `Const %d' type.\n" n;
               [ Nat ]
  | ExpVar v -> [ get_var_type env_var v ]
  | Tuple l -> flat_map (get_expr_type env_fun env_var) l
  | Not e -> get_expr_type env_fun env_var e
  | Shift(_,e,_) -> get_expr_type env_fun env_var e
  | Log(_,e,_) -> get_expr_type env_fun env_var e
  | Shuffle(v,_) -> [ get_var_type env_var v ]
  | Arith(_,e,_) -> get_expr_type env_fun env_var e
  | Fun(f,_) ->
     if f.name = "rand" then [ Uint(default_dir,Mint 1,1) ]
     else
       let def = Hashtbl.find env_fun f in
       List.map (fun vd -> vd.vtyp) def.p_out
  | _ -> assert false
  
                           
let rec expand_var env_var ?(env_it=Hashtbl.create 100) ?(partial=false) (v:var) : var list =
  let typ = get_var_type env_var v in
  match typ with
  | Nat -> [ v ]
  | Uint(_,_,1) -> [ v ]
  | Uint(_,_,n) -> List.map (fun i -> Index(v,Const_e i)) (gen_list_0_int n)
  | Array(_,s)  -> if partial then
                     List.map (fun i -> Index(v,Const_e i))
                              (gen_list_0_int s)
                   else
                     flat_map (fun i -> expand_var env_var ~env_it:env_it (Index(v,Const_e i)))
                              (gen_list_0_int s)

let rec expand_var_partial env_var ?(env_it=Hashtbl.create 100) (v:var) : var list =
  expand_var env_var ~env_it:env_it ~partial:true v

let rec get_var_base (v:var) : var =
  match v with
  | Var _ -> v
  | Index(v,_) | Slice(v,_) | Range(v,_,_) -> get_var_base v

let rec get_base_name (v:var) : ident =
  match v with
  | Var x -> x
  | Index(v,_) | Slice(v,_) | Range(v,_,_) -> get_base_name v
                                                           
let rec get_base_type (typ:typ) : typ =
  match typ with
  | Uint(dir,m,_) -> Uint(dir,m,1)
  | Array(t,_) -> get_base_type t
  | _ -> assert false

let get_type_dir (typ:typ) : dir =
  match get_base_type typ with
  | Uint(dir,_,_) -> dir
  | _ -> assert false
let get_type_m (typ:typ) : mtyp =
  match get_base_type typ with
  | Uint(_,m,_) -> m
  | _ -> assert false
let get_type_n (typ:typ) : int =
  match get_base_type typ with
  | Uint(_,_,n) -> n
  | _ -> assert false

                
let get_var_dir env_var (v:var) : dir =
  get_type_dir (get_var_type env_var v)
let get_var_m env_var (v:var) : mtyp =
  get_type_m (get_var_type env_var v)

let rec update_type_dir (typ:typ) (dir:dir) : typ =
  match typ with
  | Uint(_,m,n) -> Uint(dir,m,n)
  | Array(t,n)  -> Array(update_type_dir t dir,n)
  | _ -> assert false
let rec update_type_m (typ:typ) (m:mtyp) : typ =
  match typ with
  | Uint(dir,_,n) -> Uint(dir,m,n)
  | Array(t,n)  -> Array(update_type_m t m,n)
  | _ -> assert false

let vd_to_var (vd:var_d) : var =
  Var vd.vid

let p_to_vars (p:p) : var list =
  List.map vd_to_var p
                
let env_fetch (env: ('b, 'a) Hashtbl.t) (id: ident) : 'a option =
  try
    let v = Hashtbl.find env id.name in Some v
  with Not_found -> None

let env_contains env key : bool =
  match env_fetch env key with
  | Some _ -> true
  | None -> false
    
(* XXX: keys should be ident, using [uid] as a perfect hash *)
type 'a env = (string, 'a) Hashtbl.t

let env_add (env: 'a env) (id: ident) (value: 'a) : unit =
  Hashtbl.add env id.name value

(* converts an uint_n to n bools (with types and clock) *)
let expand_intn_typed (id: ident) (n: int) (ck: clock) =
  let rec aux i =
    if i > n then []
    else ((fresh_suffix id (string_of_int i), bool), ck) :: (aux (i+1))
  in aux 1

(* converts an uint_n to n bools (in the format of pat) *)
let expand_intn_pat (id: ident) (n: int) : var list =
  let rec aux i =
    if i > n then []
    else (Var (fresh_suffix id (string_of_int i))) :: (aux (i+1))
  in aux 1

(* converts an uint_n to n bools (in the format of expr) *)
let rec expand_intn_expr (id: ident) (n: int) : expr list =
  let rec aux i =
    if i > n then []
    else ExpVar (Var (fresh_suffix id (string_of_int i))) :: (aux (i+1))
  in aux 1

let rec expand_intn_list (id: ident) (n: int) : ident list =
  let rec aux i =
    if i > n then []
    else (fresh_suffix id (string_of_int i)) :: (aux (i+1))
  in aux 1


(* x[5] will say x[5] is used, when it should say x is used as well *)
let rec get_used_vars (e:expr) : var list =
  match e with
  | Const _ -> []
  | ExpVar v -> [ v ]
  | Shuffle(v,_) -> [ v ]
  | Tuple l -> List.flatten @@ List.map get_used_vars l
  | Not e -> get_used_vars e
  | Shift(_,e,_) -> get_used_vars e
  | Log(_,x,y) | Arith(_,x,y) -> (get_used_vars x) @ (get_used_vars y)
  | Fun(_,l) -> List.flatten @@ List.map get_used_vars l
  | _ -> assert false  

let rec get_var_name (v:var) : ident =
  match v with
  | Var id -> id
  | Index(v,_)
  | Range(v,_,_) | Slice(v,_) -> get_var_name v


let is_unroll (opts:stmt_opt list) : bool =
  List.mem Unroll opts

let is_nounroll (opts:stmt_opt list) : bool =
  List.mem No_unroll opts

let is_inline (def:def) : bool =
  List.mem Inline def.opt
           
let is_noinline (def:def) : bool =
  List.mem No_inline def.opt

let is_noopt (def:def) : bool =
  List.mem No_opt def.opt

let is_perm (def:def) : bool =
  match def.node with
  | Perm _ -> true
  | _ -> false

let is_const (var:var_d) : bool =
  List.mem Pconst var.vopts
           
let is_lazyLift (var:var_d) : bool =
  List.mem PlazyLift var.vopts

let default_bits_per_reg (arch:arch) : int =
  match arch with
  | Std     -> 64 
  | MMX     -> 64
  | SSE     -> 128
  | AVX     -> 256
  | AVX512  -> 512
  | Neon    -> 128
  | AltiVec -> 128


let p_size (p:p) : int =
  List.fold_left (fun sum vd -> sum + (typ_size vd.vtyp)) 0 p
