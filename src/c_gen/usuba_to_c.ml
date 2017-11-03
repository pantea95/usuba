open Usuba_AST
open Utils
       
let prog_to_c (orig:prog) (prog:prog) (conf:config) : string =
  assert (Assert_lang.Usuba_norm.is_usuba_normalized prog);

  if conf.openmp > 1 then
    if conf.bench then
      GenC_omp_bench.gen_runtime orig prog conf
    else
      GenC_omp_std.gen_runtime orig prog conf      
  else
    if conf.runtime then
      if conf.rand_input then
        GenC_rand_bench.gen_runtime orig prog conf
      else
        if conf.bench then
          GenC_bench.gen_runtime orig prog conf
        else
          GenC_std.gen_runtime orig prog conf
    else
      GenC_standalone.gen_runtime orig prog conf

  