Usuba
===
 
Usuba is a programming language to write bitsliced code. It compiles
optimized to C code (+ intrinsics).

---

## References

Paper about Usuba, published at WPMVP'18: [Usuba.pdf](http://dariusmercadier.com/files/Usuba.pdf).  
Some slides about Usuba from a recent talk: [Slides.pdf](http://dariusmercadier.com/files/slides_usuba_07-18.pdf).  

## A few examples

A few examples of Usuba codes:
 * [bitslice DES](samples/usuba/des.ua) (and the generated [C code](samples/C/des.c)),
 * [bitslice AES](samples/usuba/aes.ua) (and the generated [C code](samples/C/aes.c)),
 * [n-slice AES](samples/usuba/aes_kasper.ua) (and the generated [C code](samples/C/aes_kasper.c)),
 * [32-slice Serpent](samples/usuba/serpent.ua) (and the generated [C code](samples/C/serpent.c)),
 * [32-slice Chacha20](samples/usuba/chacha20.ua) (and the
   generated [C code](samples/C/chacha20.c)).


If you are familiar with Perl, an easy way to see the compiler an
action is to look at the scripts in the
directory [checks/correctness](checks/correctness) that compile a few
Usuba codes, run them and make sure they produce the expected results.


## Installation

The whole thing isn't really packaged yet, so you'll have to get started manually.  
You'll have to install `opam`, `ocaml` (>= 4.05), `coq` (maybe
with opam?) and then `opam install menhir`.  
Then, you should be able to just do `make` inside Usuba directory.


## Compiling

To compile an Usuba file (`.ua`), you need to be in usuba directory
(due to poor design, but it won't be the case anymore once I'll have
packaged Usuba), and then invoke `./usubac <options> <source.ua>` (the 
Usuba source file must be the last argument).  
I strongly recommand always using the flags `-no-sched -no-share
-no-arr -no-runtime` when doing pure bitslicing (it disables a few
experimental options, and reduces the amount of code loaded). The
option `-no-arr-entry` might also be usefull for small functions
(combined with `-no-arr`).
The list of flags can be obtained by running `./usubac -help`.  
For instance, to compile a bitslice AES:  
`./usubac -o aes.c -no-sched -no-arr -no-sched -no-runtime samples/usuba/aes.c`

The C code generated by Usuba uses macros to achieve genericity. This
macros are loaded with the instruction `#include "XXX.h"` at the
begining of the C files generated, where `XXX` is one of `STD`, `SSE`,
`AVX` (which should be `AVX2`), `AVX512`, `Neon`, `AltiVec`. Those
headers are located in the directory [arch](arch).


## Fault Detection / Threshold Implementation

Usuba can generate code with Fault Detection (by complementary
redundancy) and secure the code with Threshold Implementation. This is
controlled by the flags `-fd`, `-ti <2|3|4|8>` (only `-ti 3` works for
now however!), `-fdti <fdti|tifd>` (to be used when both `-fd` and `-ti`
are active, to specify if FD or TI should be done first). When generating
TI code, the default `L_ROTATE` will be wrong. You'll have to update it 
manually (as explained [here](experimentations/FDTI/README.md).  
The directories [experimentations/TI](experimentations/TI)
and [experimentations/FD](experimentations/FD) might share some light
about how TI and FD work in Usuba. The
script [check\_fd.pl](checks/correctness/check_fd.pl)
and [check\_ti.pl](checks/correctness/check_ti.pl) contain the command
lines used to generates the files `sbox.c` and `sbox_fd.c`.  
Briefly, to compile AES's sbox:  
* with FD: `./usubac -o sbox.c -fd -no-arr -no-arr-entry -no-share samples/usuba/sbox_aes_kasper.ua`
* with TI (3 shares): `./usubac -o sbox.c -ti 3 -no-sched -no-arr -no-arr-entry -no-share samples/usuba/sbox_aes_kasper.ua`

(Note that the Usuba file [sbox\_aes\_kasper.ua](samples/usuba/sbox\_aes\_kasper.ua) contain the lookup table version of the Sbox, which Usuba converts to circuit based on its internal [database](data/sboxes) (for AES, it should be Canright's circuit).
