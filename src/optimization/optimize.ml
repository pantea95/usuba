open Basic_utils
open Utils
open Usuba_AST
open Usuba_print

(* Clean.clean_vars_decl removes unused variables from variable declarations of nodes 
   (unused variables will likely be variables that have been optimized out) *)
module Clean = struct

  let rec clean_var env (var:var) : unit =
    match var with
    | Var id -> Hashtbl.replace env id 1
    | Index(v,_)
    | Range(v,_,_) | Slice(v,_) -> clean_var env v

  let rec clean_expr env (e:expr) : unit =
    match e with
    | ExpVar(v) -> clean_var env v
    | Tuple l -> List.iter (clean_expr env) l
    | Not e -> clean_expr env e
    | Shift(_,x,_) -> clean_expr env x
    | Log(_,x,y) -> clean_expr env x; clean_expr env y
    | Arith(_,x,y) -> clean_expr env x; clean_expr env y
    | Fun(_,l) -> List.iter (clean_expr env) l
    | Fun_v(_,_,l) -> List.iter (clean_expr env) l
    | Fby(ei,ef,_) -> clean_expr env ei; clean_expr env ef
    | _ -> ()
  
  let clean_in_deqs (vars:p) (deqs:deq list) : p =
    let env = Hashtbl.create 100 in
    let rec aux = function
      | Eqn(l,e,_) -> List.iter (clean_var env) l;
                      clean_expr env e
      | Loop(_,_,_,d,_) -> List.iter aux d in
    List.iter aux deqs;
    List.sort_uniq (fun a b -> compare a b)
                   ( List.filter (fun vd -> match Hashtbl.find_opt env vd.vid with
                                            | Some _ -> true
                                            | None -> false) vars)

  let clean_def (def:def) : def =
    match def.node with
    | Single(vars,body) ->
       let vars = clean_in_deqs vars body in
       { def with node = Single(vars,body) }
    | _ -> def
  
  let clean_vars_decl (prog:prog) : prog =
    { nodes = List.map clean_def prog.nodes }
end
          
let print title body conf =
  if conf.verbose >= 5 then
    begin
      Printf.fprintf stderr "%s\n" title;
      if conf.verbose >= 100 then Printf.fprintf stderr "%s\n" (Usuba_print.prog_to_str body)
    end
      
let opt_prog (prog: Usuba_AST.prog) (conf:config) : Usuba_AST.prog =

  (* Interleaving *)
  let interleaved = if conf.interleave > 0 then Interleave.interleave prog conf else prog in
  
  (* CSE - CP *)
  (* CSE - CP is already done in the normalization *)
  let optimized = if conf.cse_cp then CSE_CF_CP.opt_prog interleaved conf else interleaved in
  print "CSE-CP:" optimized conf;
  
  (* if conf.scheduling then Pre_schedule.schedule cleaned else cleaned *)
  let scheduled =  if conf.scheduling then Scheduler.schedule optimized conf else optimized in
  print "SCHEDULED:" scheduled conf;

  (* Reusing variables *)
  let vars_shared = Share_var.share_prog scheduled conf in
  print "VARS SHARED:" vars_shared conf;

  (* Removing unused variables *)
  let cleaned = Clean.clean_vars_decl vars_shared in
  print "CLEANED:" cleaned conf;

  cleaned
