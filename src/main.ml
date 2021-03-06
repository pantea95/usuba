
open Usuba_AST
open Printf
open Basic_utils
open Utils

let block_size  = ref 64
let key_size    = ref 64
let warnings    = ref false
let verbose     = ref 1
let verif       = ref false
let type_check  = ref true
let clock_check = ref true
let check_tbl   = ref false
                     
let inlining     = ref true
let inline_all   = ref false
let cse_cp       = ref true
let scheduling   = ref true
let schedule_n   = ref 10
let share_var    = ref false
let precal_tbl   = ref true
let no_arr       = ref false
let no_arr_tmp   = ref false
let arr_entry    = ref true
let unroll       = ref false
let interleave   = ref 0
                      
let runtime      = ref false
let arch         = ref Std
let bits_per_reg = ref 64
let bench        = ref false
let rand_input   = ref false
let ortho        = ref true
let openmp       = ref 1
let output       = ref ""
let fd           = ref false
let ti           = ref 1
let fdti         = ref ""
let lazylift     = ref false
let secure_loops = ref false

let slicing_type = ref B
let slicing_set  = ref false

let str_to_arch = function
  | "std"     -> Std
  | "mmx"     -> MMX
  | "sse"     -> SSE
  | "avx"     -> AVX
  | "avx512"  -> AVX512
  | "neon"    -> Neon
  | "altivec" -> AltiVec
  | x -> raise (Error ("Invalid archi: " ^ x))

let bits_in_arch = function
  | Std      -> 64
  | MMX      -> 64
  | SSE      -> 128
  | AVX      -> 256
  | AVX512   -> 512
  | Neon     -> 128
  | AltiVec  -> 128

let gen_output_filename (file_in: string) : string =
  let full_name = List.hd (String.split_on_char '.' file_in) in
  let out_name = last (String.split_on_char '/' full_name) in
  out_name ^ ".c"
               
let print_c (file_in: string) (prog: Usuba_AST.prog) (conf:config) : unit =
  (* Generating C code *)
  let out = match !output with
    | ""  -> open_out (gen_output_filename file_in)
    | str -> open_out str in

  let normalized = Normalize.compile prog conf in

  let c_prog = Usuba_to_c.prog_to_c prog normalized conf file_in in
  
  fprintf out "%s" c_prog;
  close_out out

            
let main () =
  Printexc.record_backtrace true;

  let speclist = 
    [ "-w", Arg.Set warnings, "Activate warnings";
      "-v", Arg.Set_int verbose, "Set verbosity level";
      "-bsize", Arg.Int (fun n -> block_size := n), "Specify the block size";
      "-ksize", Arg.Int (fun n -> key_size   := n), "Specify the key size";
      "-verif", Arg.Set verif, "Activate verification";
      "-check-tbl", Arg.Set check_tbl, "Activate verification of tables";
      "-no-type-check", Arg.Clear type_check, "Deactivate type checking";
      "-no-clock-check", Arg.Clear clock_check, "Deactivate clock checking";
      "-no-checks", Arg.Unit (fun () -> type_check := false;
                                        clock_check := false),
                    "Deactivate both type and clock checking";
      "-no-inline", Arg.Clear inlining, "Deactivate inlining opti";
      "-inline-all", Arg.Set inline_all, "Force inlining of every node";
      "-no-CSE-CP", Arg.Clear cse_cp, "Deactive CSE and CP opti";
      "-no-sched", Arg.Clear scheduling, "Deactivate scheduling opti";
      "-sched-n", Arg.Int (fun n -> schedule_n := n), "Set scheduling param";
      "-no-share", Arg.Clear share_var, "Deactivate variable sharing";
      "-no-precalc-tbl", Arg.Clear precal_tbl, "Don't use pre-computed tables";
      "-no-arr-tmp", Arg.Set no_arr, "Don't use arrays for temporaries";
      "-no-arr", Arg.Set no_arr, "Don't keep any array";
      "-no-arr-entry", Arg.Clear arr_entry, "Don't keep any arrays in the entry point";
      "-unroll", Arg.Set unroll, "Unroll all loops";
      "-interleave", Arg.Int (fun n -> interleave := n), "Interleave encryptions";
      "-arch", Arg.String (fun s -> arch := str_to_arch s), "Set architecture";
      "-bits-per-reg", Arg.Set_int bits_per_reg, "Set number of bits to use in the registers (with -arch std only, needs to be a multiple of 2)";
      "-runtime", Arg.Set runtime, "Use bitslice runtime";
      "-no-runtime", Arg.Clear runtime, "Do not generate a runtime";
      "-bench", Arg.Set bench, "Generate benchmark runtime";
      "-rand-input", Arg.Set rand_input, "Bench on random inputs rather than on a file (implies -bench)";
      "-ortho", Arg.Set ortho, "Perform data orthogonalization";
      "-no-ortho", Arg.Clear ortho, "Don't perform data orthogonalization";
      "-openmp", Arg.Set_int openmp, "Set the number of core to use";
      "-fd", Arg.Set fd, "Generate complementary redudant code";
      "-ti", Arg.Set_int ti, "Set the number of shares to use for Threshold Implemenation (1, 2, 4, 8)";
      "-fdti",Arg.Set_string fdti, "Specify the order of ti and fd (tifd or fdti)";
      "-secure-loops", Arg.Set secure_loops, "Secure loops with intra-redundancy in the counter";
      "-lf", Arg.Set lazylift, "Enable lazy lifting";
      "-o", Arg.Set_string output, "Set the output filename";
      "-H", Arg.Unit (fun () -> slicing_set := true; slicing_type := H), "Horizontal slicing.";
      "-V", Arg.Unit (fun () -> slicing_set := true; slicing_type := V), "Vertical slicing.";
      "-B", Arg.Unit (fun () -> slicing_set := true; slicing_type := B), "Bit slicing.";
    ] in
  let usage_msg = "Usage: usuba [switches] [files]" in
  
  let compile s =
    let prog = Parse_file.parse_file s in
    let bits_per_reg = if !bits_per_reg <> 64 then !bits_per_reg
                       else bits_in_arch !arch in
    let no_arr = if !slicing_set then match !slicing_type with
                                      | B -> true
                                      | _ -> !no_arr
                 else !no_arr in
    let conf = { block_size     =   !block_size;
                 key_size       =   !key_size;
                 warnings       =   !warnings;
                 verbose        =   !verbose;
                 verif          =   !verif;
                 type_check     =   !type_check;
                 clock_check    =   !clock_check;
                 check_tbl      =   !check_tbl;
                 inlining       =   !inlining;
                 inline_all     =   !inline_all;
                 cse_cp         =   !cse_cp;
                 scheduling     =   !scheduling;
                 schedule_n     =   !schedule_n;
                 share_var      =   !share_var;
                 precal_tbl     =   !precal_tbl;
                 archi          =   !arch;
                 bits_per_reg   =   bits_per_reg; (* local var! *)
                 runtime        =   !runtime;
                 bench          =   !bench || !rand_input;
                 rand_input     =   !rand_input;
                 ortho          =   !ortho;
                 openmp         =   !openmp;
                 no_arr         =   no_arr; (* local var! *)
                 no_arr_tmp     =   !no_arr_tmp;
                 arr_entry      =   !arr_entry;
                 unroll         =   !unroll;
                 interleave     =   !interleave;
                 fd             =   !fd;
                 ti             =   !ti;
                 fdti           =   !fdti;
                 lazylift       =   !lazylift;
                 slicing_set    =   !slicing_set;
                 slicing_type   =   !slicing_type;
                 secure_loops   =   !secure_loops;
               } in

    if conf.archi = Std && conf.bits_per_reg mod 2 <> 0 then
      raise (Error ("Invalid -fix-size " ^ (string_of_int conf.bits_per_reg)));

    if !type_check then
      if false (*not (Type_checker.is_typed prog)*) then
       raise (Error "Unsound program: bad types");
    if !clock_check then
      if not (Clock_checker.is_clocked prog) then
        raise (Error "Unsound program: bad clocks");
    print_c s prog conf in
      
  
  Arg.parse speclist compile usage_msg
    

let () = main ()
