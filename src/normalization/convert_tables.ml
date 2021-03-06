(***************************************************************************** )
                              convert_tables.ml                                 

   This module converts lookup tables into circuits. In Usuba, this means 
   converting "table" into "node". 
   This is done using Binary Decision Diagrams (BDD). This is hardly optimized
   for now, and a lot of useless redondancy is present. In a near future, we
   should improve this.
    
    After this module has ran, there souldn't be any "Table" nor "MultipleTable"
    left.

( *****************************************************************************)


open Usuba_AST
open Basic_utils
open Utils
open Printf
       
let rewrite_p (p:p) : var list =
  List.map (fun vd -> Var vd.vid) (Expand_array.expand_p p)

let get_bits (l:int list) (i:int) : int list =
  List.rev @@ List.map (fun x -> x lsr i land 1) l

let tmp_var i j k =
  fresh_ident ("tmp_" ^ (string_of_int i) ^ "_" ^ (string_of_int j) ^ "_" ^ (string_of_int k))

let mux c a b = Log(Or,Log(Andn,c,ExpVar(Var a)),Log(And,c,ExpVar(Var b)))
(* let mux c a b = Log(Xor,ExpVar(Var a),Log(And,c,Log(Xor,ExpVar(Var a),ExpVar(Var b)))) *)

                   
let rewrite_table (id:ident) (p_in:p) (p_out:p)
                  (opt:def_opt list) (l:int list) : def =
  let exp_p_in  = Array.of_list @@ rewrite_p p_in in
  let exp_p_out = Array.of_list @@ rewrite_p p_out in
  let size_in = Array.length exp_p_in in
  let size_out = Array.length exp_p_out in
  let body = ref [] in
  let vars = ref [] in
  for i = 1 to size_out do (* for each bit ou the output *)

    (* get the bits of the output the current rank *)
    let bits = Array.of_list (List.rev (get_bits l (size_out-i))) in

    (* initialise rank 0 *)
    for j = 1 to List.length l do
      let var = tmp_var i 0 (j-1) in
      vars := (simple_var_d var) :: !vars;
      body := Eqn ([Var var],Const bits.(j-1),false) :: !body
    done;

    (* for each depth *)
    for j = 1 to size_in do
      
      for k = 1 to pow 2 (size_in-j) do
        let var_l  = tmp_var i j (k-1) in
        let var_r1 = tmp_var i (j-1) ((k-1)*2) in
        let var_r2 = tmp_var i (j-1) ((k-1)*2+1) in
        vars := (simple_var_d var_l) ::
                  (simple_var_d var_r1) ::
                    (simple_var_d var_r2) :: !vars;
        body := Eqn ([Var var_l],
                       mux (ExpVar exp_p_in.(size_in-j)) var_r1 var_r2, false)
                :: !body
      done
    done;
    
    (* set output *)
    let var = tmp_var i size_in 0 in
    vars := (simple_var_d var) :: !vars;
    body := Eqn ([exp_p_out.(i-1)], ExpVar(Var var), false) :: !body
      
  done;
  { id = id; p_in = p_in; p_out = p_out; opt = opt;
    node = Single(!vars,List.rev !body) }
    
(* A bit hacky: should convert types as needed.
   (for instance: bool[4] to u16[4] (rectangle)) *)
let fix_p (old_p:p) (new_p:p) : p =
  let t = get_base_type (List.hd old_p).vtyp in
  List.map (fun x -> { x with vtyp =
                                match x.vtyp with
                                | Array(_,n) -> Array(t,n)
                                | Uint(_,_,n) -> ( match t with
                                                   | Uint(dir,m,1) -> Uint(dir,m,n)
                                                   | _ -> assert false)
                                | _ -> t }) new_p
    
let rewrite_single_table (id:ident) (p_in:p) (p_out:p)
                         (opt:def_opt list) (l:int list)
                         (conf:config) : def =
  if conf.precal_tbl then
    try
      let (found,_) = List.find (fun (a,b) -> b = l) Sbox_index.sboxes in
      let file_name = "data/sboxes/" ^ found ^ ".ua" in
      let new_node = List.nth (Parse_file.parse_file file_name).nodes 0 in
      { new_node with id = id;
                      p_in = fix_p p_in new_node.p_in;
                      p_out = fix_p p_out new_node.p_out;                      
                      opt = new_node.opt @ opt }
    with Not_found -> rewrite_table id p_in p_out opt l
  else rewrite_table id p_in p_out opt l

let rec rewrite_def (def: def) (conf:config) : def =
  let id    = def.id in
  let p_in  = def.p_in in
  let p_out = def.p_out in
  let opt   = def.opt in
  match def.node with
  | Table l -> rewrite_single_table id p_in p_out opt l conf
  | _ -> def
           
                       
let convert_tables (p: prog) (conf:config): prog =
  { nodes = List.map (fun x -> rewrite_def x conf) p.nodes }
