open Usuba_AST
open Sol_AST
open Utils

let rec c_to_str_ml (c: c) : string =
  match c with
  | Var v    -> v
  | Const n  -> (match n with
                 | 0 -> "false"
                 | 1 -> "true"
                 | _ -> unreached ())
  | Tuple l  -> "(" ^ (join "," (List.map c_to_str_ml l)) ^ ")"
  | Log(Xor,a::b::[]) ->  c_to_str_ml (Log(Or,[Log(And,[a;Log(Not,[b])]);
                                             Log(And,[Log(Not,[a]);b])]))
  | Log(op,a::b::[])  -> "(" ^ (c_to_str_ml a) ^  ")" ^
                          ( match op with
                            | And -> " && "
                            | Or  -> " || "
                            | _ -> unreached () )
                          ^ "(" ^ (c_to_str_ml b) ^ ")"
  | Log(Not,x::[]) -> "not (" ^ (c_to_str_ml x) ^ ")"
  | _ -> raise (Not_implemented "state var to ocaml")
               
      
let s_to_str_ml (s: s) : string =
  match s with
  | Asgn(l,c) -> "let (" ^ (join "," l)  ^ ") = " ^ (c_to_str_ml c) ^ " in"
  | Skip -> ""
  | Step(ll,o,lr) -> "let (" ^ (join "," ll) ^ ") = " ^ o ^ " "
                     ^ (join " " (List.map
                                    (fun x -> "(" ^ (c_to_str_ml x) ^ ")")
                                    lr)) ^ " in"
  | _ -> raise (Not_implemented "state_asgn or reset to ocaml")
       
let machine_to_str_ml ((id,memory,instances,reset,p_in,p_out,vars,body):machine)
    : string =
  "let " ^ id ^ " () = \n"
  ^ (join "\n"
          (List.map (fun x -> "  " ^ x)
                    (List.map
                       (fun (x,y) -> "let " ^ x ^ " = " ^ y ^ " () in")
                       instances)))
  ^ "\n  fun " ^ (join " " (List.map fst p_in)) ^ " ->\n"
  ^ (join "\n"
          (List.map (fun x -> "    " ^ x)
                    (List.map s_to_str_ml body)))
  ^ "\n    (" ^ (join "," (List.map fst p_out)) ^ ")"
                    
       
let prog_to_str_ml (prog: Sol_AST.prog) : string =
  join "\n\n" (List.map machine_to_str_ml prog)
