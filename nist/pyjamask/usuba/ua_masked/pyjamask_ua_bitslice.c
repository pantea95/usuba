/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba.
   From the file "nist/pyjamask/usuba/ua_masked/pyjamask_bitslice.ua" (included below). */

#include <stdint.h>

/* Do NOT change the order of those define/include */

#ifndef BITS_PER_REG
#define BITS_PER_REG 64
#endif
/* including the architecture specific .h */
#include "MASKED.h"

/* auxiliary functions */
void SubBytes__B1 (/*inputs*/ DATATYPE s0[MASKING_ORDER],DATATYPE s1[MASKING_ORDER],DATATYPE s2[MASKING_ORDER],DATATYPE s3[MASKING_ORDER], /*outputs*/ DATATYPE ret0__[MASKING_ORDER],DATATYPE ret1__[MASKING_ORDER],DATATYPE ret2__[MASKING_ORDER],DATATYPE ret3__[MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _shadow_s01_[MASKING_ORDER];
  DATATYPE _shadow_s03_[MASKING_ORDER];
  DATATYPE _shadow_s14_[MASKING_ORDER];
  DATATYPE _shadow_s17_[MASKING_ORDER];
  DATATYPE _shadow_s25_[MASKING_ORDER];
  DATATYPE _shadow_s26_[MASKING_ORDER];
  DATATYPE _shadow_s32_[MASKING_ORDER];
  DATATYPE _shadow_s38_[MASKING_ORDER];
  DATATYPE _tmp1_[MASKING_ORDER];
  DATATYPE _tmp2_[MASKING_ORDER];
  DATATYPE _tmp3_[MASKING_ORDER];
  DATATYPE _tmp4_[MASKING_ORDER];

  // Instructions (body)
  XOR(_shadow_s01_,s0,s3);
  AND(_tmp1_,_shadow_s01_,s1);
  XOR(_shadow_s32_,s3,_tmp1_);
  AND(_tmp2_,s1,s2);
  XOR(_shadow_s03_,_shadow_s01_,_tmp2_);
  AND(_tmp3_,s2,_shadow_s32_);
  XOR(_shadow_s14_,s1,_tmp3_);
  AND(_tmp4_,_shadow_s03_,_shadow_s32_);
  XOR(_shadow_s25_,s2,_tmp4_);
  XOR(_shadow_s26_,_shadow_s25_,_shadow_s14_);
  XOR(_shadow_s17_,_shadow_s14_,_shadow_s03_);
  NOT(_shadow_s38_,_shadow_s32_);
  ASGN(ret0__,_shadow_s03_);
  ASGN(ret1__,_shadow_s17_);
  ASGN(ret2__,_shadow_s38_);
  ASGN(ret3__,_shadow_s26_);

}

void AddRoundKey__B1 (/*inputs*/ DATATYPE i__[128][MASKING_ORDER],DATATYPE k__[128][MASKING_ORDER], /*outputs*/ DATATYPE o__[128][MASKING_ORDER]) {

  // Variables declaration
  ;

  // Instructions (body)
  XOR(o__[0],i__[0],k__[0]);
  XOR(o__[1],i__[1],k__[1]);
  XOR(o__[2],i__[2],k__[2]);
  XOR(o__[3],i__[3],k__[3]);
  XOR(o__[4],i__[4],k__[4]);
  XOR(o__[5],i__[5],k__[5]);
  XOR(o__[6],i__[6],k__[6]);
  XOR(o__[7],i__[7],k__[7]);
  XOR(o__[8],i__[8],k__[8]);
  XOR(o__[9],i__[9],k__[9]);
  XOR(o__[10],i__[10],k__[10]);
  XOR(o__[11],i__[11],k__[11]);
  XOR(o__[12],i__[12],k__[12]);
  XOR(o__[13],i__[13],k__[13]);
  XOR(o__[14],i__[14],k__[14]);
  XOR(o__[15],i__[15],k__[15]);
  XOR(o__[16],i__[16],k__[16]);
  XOR(o__[17],i__[17],k__[17]);
  XOR(o__[18],i__[18],k__[18]);
  XOR(o__[19],i__[19],k__[19]);
  XOR(o__[20],i__[20],k__[20]);
  XOR(o__[21],i__[21],k__[21]);
  XOR(o__[22],i__[22],k__[22]);
  XOR(o__[23],i__[23],k__[23]);
  XOR(o__[24],i__[24],k__[24]);
  XOR(o__[25],i__[25],k__[25]);
  XOR(o__[26],i__[26],k__[26]);
  XOR(o__[27],i__[27],k__[27]);
  XOR(o__[28],i__[28],k__[28]);
  XOR(o__[29],i__[29],k__[29]);
  XOR(o__[30],i__[30],k__[30]);
  XOR(o__[31],i__[31],k__[31]);
  XOR(o__[32],i__[32],k__[32]);
  XOR(o__[33],i__[33],k__[33]);
  XOR(o__[34],i__[34],k__[34]);
  XOR(o__[35],i__[35],k__[35]);
  XOR(o__[36],i__[36],k__[36]);
  XOR(o__[37],i__[37],k__[37]);
  XOR(o__[38],i__[38],k__[38]);
  XOR(o__[39],i__[39],k__[39]);
  XOR(o__[40],i__[40],k__[40]);
  XOR(o__[41],i__[41],k__[41]);
  XOR(o__[42],i__[42],k__[42]);
  XOR(o__[43],i__[43],k__[43]);
  XOR(o__[44],i__[44],k__[44]);
  XOR(o__[45],i__[45],k__[45]);
  XOR(o__[46],i__[46],k__[46]);
  XOR(o__[47],i__[47],k__[47]);
  XOR(o__[48],i__[48],k__[48]);
  XOR(o__[49],i__[49],k__[49]);
  XOR(o__[50],i__[50],k__[50]);
  XOR(o__[51],i__[51],k__[51]);
  XOR(o__[52],i__[52],k__[52]);
  XOR(o__[53],i__[53],k__[53]);
  XOR(o__[54],i__[54],k__[54]);
  XOR(o__[55],i__[55],k__[55]);
  XOR(o__[56],i__[56],k__[56]);
  XOR(o__[57],i__[57],k__[57]);
  XOR(o__[58],i__[58],k__[58]);
  XOR(o__[59],i__[59],k__[59]);
  XOR(o__[60],i__[60],k__[60]);
  XOR(o__[61],i__[61],k__[61]);
  XOR(o__[62],i__[62],k__[62]);
  XOR(o__[63],i__[63],k__[63]);
  XOR(o__[64],i__[64],k__[64]);
  XOR(o__[65],i__[65],k__[65]);
  XOR(o__[66],i__[66],k__[66]);
  XOR(o__[67],i__[67],k__[67]);
  XOR(o__[68],i__[68],k__[68]);
  XOR(o__[69],i__[69],k__[69]);
  XOR(o__[70],i__[70],k__[70]);
  XOR(o__[71],i__[71],k__[71]);
  XOR(o__[72],i__[72],k__[72]);
  XOR(o__[73],i__[73],k__[73]);
  XOR(o__[74],i__[74],k__[74]);
  XOR(o__[75],i__[75],k__[75]);
  XOR(o__[76],i__[76],k__[76]);
  XOR(o__[77],i__[77],k__[77]);
  XOR(o__[78],i__[78],k__[78]);
  XOR(o__[79],i__[79],k__[79]);
  XOR(o__[80],i__[80],k__[80]);
  XOR(o__[81],i__[81],k__[81]);
  XOR(o__[82],i__[82],k__[82]);
  XOR(o__[83],i__[83],k__[83]);
  XOR(o__[84],i__[84],k__[84]);
  XOR(o__[85],i__[85],k__[85]);
  XOR(o__[86],i__[86],k__[86]);
  XOR(o__[87],i__[87],k__[87]);
  XOR(o__[88],i__[88],k__[88]);
  XOR(o__[89],i__[89],k__[89]);
  XOR(o__[90],i__[90],k__[90]);
  XOR(o__[91],i__[91],k__[91]);
  XOR(o__[92],i__[92],k__[92]);
  XOR(o__[93],i__[93],k__[93]);
  XOR(o__[94],i__[94],k__[94]);
  XOR(o__[95],i__[95],k__[95]);
  XOR(o__[96],i__[96],k__[96]);
  XOR(o__[97],i__[97],k__[97]);
  XOR(o__[98],i__[98],k__[98]);
  XOR(o__[99],i__[99],k__[99]);
  XOR(o__[100],i__[100],k__[100]);
  XOR(o__[101],i__[101],k__[101]);
  XOR(o__[102],i__[102],k__[102]);
  XOR(o__[103],i__[103],k__[103]);
  XOR(o__[104],i__[104],k__[104]);
  XOR(o__[105],i__[105],k__[105]);
  XOR(o__[106],i__[106],k__[106]);
  XOR(o__[107],i__[107],k__[107]);
  XOR(o__[108],i__[108],k__[108]);
  XOR(o__[109],i__[109],k__[109]);
  XOR(o__[110],i__[110],k__[110]);
  XOR(o__[111],i__[111],k__[111]);
  XOR(o__[112],i__[112],k__[112]);
  XOR(o__[113],i__[113],k__[113]);
  XOR(o__[114],i__[114],k__[114]);
  XOR(o__[115],i__[115],k__[115]);
  XOR(o__[116],i__[116],k__[116]);
  XOR(o__[117],i__[117],k__[117]);
  XOR(o__[118],i__[118],k__[118]);
  XOR(o__[119],i__[119],k__[119]);
  XOR(o__[120],i__[120],k__[120]);
  XOR(o__[121],i__[121],k__[121]);
  XOR(o__[122],i__[122],k__[122]);
  XOR(o__[123],i__[123],k__[123]);
  XOR(o__[124],i__[124],k__[124]);
  XOR(o__[125],i__[125],k__[125]);
  XOR(o__[126],i__[126],k__[126]);
  XOR(o__[127],i__[127],k__[127]);

}

void SubBytesAll__B1 (/*inputs*/ DATATYPE input__[128][MASKING_ORDER], /*outputs*/ DATATYPE output__[128][MASKING_ORDER]) {

  // Variables declaration
  ;

  // Instructions (body)
  for (int i__ = 0; i__ <= 31; i__++) {
    SubBytes__B1(input__[i__],input__[(32 + i__)],input__[(64 + i__)],input__[(96 + i__)],output__[i__],output__[(32 + i__)],output__[(64 + i__)],output__[(96 + i__)]);
  }

}

void col_mult__B1 (/*inputs*/ DATATYPE a__0__[MASKING_ORDER],DATATYPE a__1__[MASKING_ORDER],DATATYPE a__2__[MASKING_ORDER],DATATYPE a__3__[MASKING_ORDER],DATATYPE a__4__[MASKING_ORDER],DATATYPE a__5__[MASKING_ORDER],DATATYPE a__6__[MASKING_ORDER],DATATYPE a__7__[MASKING_ORDER],DATATYPE a__8__[MASKING_ORDER],DATATYPE a__9__[MASKING_ORDER],DATATYPE a__10__[MASKING_ORDER],DATATYPE a__11__[MASKING_ORDER],DATATYPE a__12__[MASKING_ORDER],DATATYPE a__13__[MASKING_ORDER],DATATYPE a__14__[MASKING_ORDER],DATATYPE a__15__[MASKING_ORDER],DATATYPE a__16__[MASKING_ORDER],DATATYPE a__17__[MASKING_ORDER],DATATYPE a__18__[MASKING_ORDER],DATATYPE a__19__[MASKING_ORDER],DATATYPE a__20__[MASKING_ORDER],DATATYPE a__21__[MASKING_ORDER],DATATYPE a__22__[MASKING_ORDER],DATATYPE a__23__[MASKING_ORDER],DATATYPE a__24__[MASKING_ORDER],DATATYPE a__25__[MASKING_ORDER],DATATYPE a__26__[MASKING_ORDER],DATATYPE a__27__[MASKING_ORDER],DATATYPE a__28__[MASKING_ORDER],DATATYPE a__29__[MASKING_ORDER],DATATYPE a__30__[MASKING_ORDER],DATATYPE a__31__[MASKING_ORDER],DATATYPE b__[32][MASKING_ORDER], /*outputs*/ DATATYPE r__[MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp5_[MASKING_ORDER];
  DATATYPE acc__[MASKING_ORDER];

  // Instructions (body)
  AND_CST(acc__,a__0__,b__[0]);
  AND_CST(_tmp5_,a__1__,b__[1]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__2__,b__[2]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__3__,b__[3]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__4__,b__[4]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__5__,b__[5]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__6__,b__[6]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__7__,b__[7]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__8__,b__[8]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__9__,b__[9]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__10__,b__[10]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__11__,b__[11]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__12__,b__[12]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__13__,b__[13]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__14__,b__[14]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__15__,b__[15]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__16__,b__[16]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__17__,b__[17]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__18__,b__[18]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__19__,b__[19]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__20__,b__[20]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__21__,b__[21]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__22__,b__[22]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__23__,b__[23]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__24__,b__[24]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__25__,b__[25]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__26__,b__[26]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__27__,b__[27]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__28__,b__[28]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__29__,b__[29]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__30__,b__[30]);
  XOR(acc__,acc__,_tmp5_);
  AND_CST(_tmp5_,a__31__,b__[31]);
  XOR(acc__,acc__,_tmp5_);
  ASGN(r__,acc__);

}

void MixRows__B1 (/*inputs*/ DATATYPE input__[128][MASKING_ORDER], /*outputs*/ DATATYPE output__[128][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE M__[4][33][32][MASKING_ORDER];

  // Instructions (body)
  ASGN_CST(M__[0][0][0], SET_ALL_ONE());
  ASGN_CST(M__[0][0][1], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][2], SET_ALL_ONE());
  ASGN_CST(M__[0][0][3], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][4], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][5], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][6], SET_ALL_ONE());
  ASGN_CST(M__[0][0][7], SET_ALL_ONE());
  ASGN_CST(M__[0][0][8], SET_ALL_ONE());
  ASGN_CST(M__[0][0][9], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][10], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][11], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][12], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][13], SET_ALL_ONE());
  ASGN_CST(M__[0][0][14], SET_ALL_ONE());
  ASGN_CST(M__[0][0][15], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][16], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][17], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][18], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][19], SET_ALL_ONE());
  ASGN_CST(M__[0][0][20], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][21], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][22], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][23], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][24], SET_ALL_ONE());
  ASGN_CST(M__[0][0][25], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][26], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][27], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][28], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][29], SET_ALL_ONE());
  ASGN_CST(M__[0][0][30], SET_ALL_ZERO());
  ASGN_CST(M__[0][0][31], SET_ALL_ONE());
  ASGN_CST(M__[1][0][0], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][1], SET_ALL_ONE());
  ASGN_CST(M__[1][0][2], SET_ALL_ONE());
  ASGN_CST(M__[1][0][3], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][4], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][5], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][6], SET_ALL_ONE());
  ASGN_CST(M__[1][0][7], SET_ALL_ONE());
  ASGN_CST(M__[1][0][8], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][9], SET_ALL_ONE());
  ASGN_CST(M__[1][0][10], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][11], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][12], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][13], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][14], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][15], SET_ALL_ONE());
  ASGN_CST(M__[1][0][16], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][17], SET_ALL_ONE());
  ASGN_CST(M__[1][0][18], SET_ALL_ONE());
  ASGN_CST(M__[1][0][19], SET_ALL_ONE());
  ASGN_CST(M__[1][0][20], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][21], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][22], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][23], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][24], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][25], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][26], SET_ALL_ONE());
  ASGN_CST(M__[1][0][27], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][28], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][29], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][30], SET_ALL_ZERO());
  ASGN_CST(M__[1][0][31], SET_ALL_ONE());
  ASGN_CST(M__[2][0][0], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][1], SET_ALL_ONE());
  ASGN_CST(M__[2][0][2], SET_ALL_ONE());
  ASGN_CST(M__[2][0][3], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][4], SET_ALL_ONE());
  ASGN_CST(M__[2][0][5], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][6], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][7], SET_ALL_ONE());
  ASGN_CST(M__[2][0][8], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][9], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][10], SET_ALL_ONE());
  ASGN_CST(M__[2][0][11], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][12], SET_ALL_ONE());
  ASGN_CST(M__[2][0][13], SET_ALL_ONE());
  ASGN_CST(M__[2][0][14], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][15], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][16], SET_ALL_ONE());
  ASGN_CST(M__[2][0][17], SET_ALL_ONE());
  ASGN_CST(M__[2][0][18], SET_ALL_ONE());
  ASGN_CST(M__[2][0][19], SET_ALL_ONE());
  ASGN_CST(M__[2][0][20], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][21], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][22], SET_ALL_ONE());
  ASGN_CST(M__[2][0][23], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][24], SET_ALL_ONE());
  ASGN_CST(M__[2][0][25], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][26], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][27], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][28], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][29], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][30], SET_ALL_ZERO());
  ASGN_CST(M__[2][0][31], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][0], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][1], SET_ALL_ONE());
  ASGN_CST(M__[3][0][2], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][3], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][4], SET_ALL_ONE());
  ASGN_CST(M__[3][0][5], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][6], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][7], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][8], SET_ALL_ONE());
  ASGN_CST(M__[3][0][9], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][10], SET_ALL_ONE());
  ASGN_CST(M__[3][0][11], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][12], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][13], SET_ALL_ONE());
  ASGN_CST(M__[3][0][14], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][15], SET_ALL_ONE());
  ASGN_CST(M__[3][0][16], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][17], SET_ALL_ONE());
  ASGN_CST(M__[3][0][18], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][19], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][20], SET_ALL_ONE());
  ASGN_CST(M__[3][0][21], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][22], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][23], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][24], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][25], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][26], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][27], SET_ALL_ONE());
  ASGN_CST(M__[3][0][28], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][29], SET_ALL_ZERO());
  ASGN_CST(M__[3][0][30], SET_ALL_ONE());
  ASGN_CST(M__[3][0][31], SET_ALL_ONE());
  for (int idx__ = 0; idx__ <= 31; idx__++) {
    col_mult__B1(input__[0],input__[1],input__[2],input__[3],input__[4],input__[5],input__[6],input__[7],input__[8],input__[9],input__[10],input__[11],input__[12],input__[13],input__[14],input__[15],input__[16],input__[17],input__[18],input__[19],input__[20],input__[21],input__[22],input__[23],input__[24],input__[25],input__[26],input__[27],input__[28],input__[29],input__[30],input__[31],M__[0][idx__],output__[(0 + idx__)]);
    ASGN(M__[0][(idx__ + 1)][0],M__[0][idx__][31]);
    ASGN(M__[0][(idx__ + 1)][1],M__[0][idx__][0]);
    ASGN(M__[0][(idx__ + 1)][2],M__[0][idx__][1]);
    ASGN(M__[0][(idx__ + 1)][3],M__[0][idx__][2]);
    ASGN(M__[0][(idx__ + 1)][4],M__[0][idx__][3]);
    ASGN(M__[0][(idx__ + 1)][5],M__[0][idx__][4]);
    ASGN(M__[0][(idx__ + 1)][6],M__[0][idx__][5]);
    ASGN(M__[0][(idx__ + 1)][7],M__[0][idx__][6]);
    ASGN(M__[0][(idx__ + 1)][8],M__[0][idx__][7]);
    ASGN(M__[0][(idx__ + 1)][9],M__[0][idx__][8]);
    ASGN(M__[0][(idx__ + 1)][10],M__[0][idx__][9]);
    ASGN(M__[0][(idx__ + 1)][11],M__[0][idx__][10]);
    ASGN(M__[0][(idx__ + 1)][12],M__[0][idx__][11]);
    ASGN(M__[0][(idx__ + 1)][13],M__[0][idx__][12]);
    ASGN(M__[0][(idx__ + 1)][14],M__[0][idx__][13]);
    ASGN(M__[0][(idx__ + 1)][15],M__[0][idx__][14]);
    ASGN(M__[0][(idx__ + 1)][16],M__[0][idx__][15]);
    ASGN(M__[0][(idx__ + 1)][17],M__[0][idx__][16]);
    ASGN(M__[0][(idx__ + 1)][18],M__[0][idx__][17]);
    ASGN(M__[0][(idx__ + 1)][19],M__[0][idx__][18]);
    ASGN(M__[0][(idx__ + 1)][20],M__[0][idx__][19]);
    ASGN(M__[0][(idx__ + 1)][21],M__[0][idx__][20]);
    ASGN(M__[0][(idx__ + 1)][22],M__[0][idx__][21]);
    ASGN(M__[0][(idx__ + 1)][23],M__[0][idx__][22]);
    ASGN(M__[0][(idx__ + 1)][24],M__[0][idx__][23]);
    ASGN(M__[0][(idx__ + 1)][25],M__[0][idx__][24]);
    ASGN(M__[0][(idx__ + 1)][26],M__[0][idx__][25]);
    ASGN(M__[0][(idx__ + 1)][27],M__[0][idx__][26]);
    ASGN(M__[0][(idx__ + 1)][28],M__[0][idx__][27]);
    ASGN(M__[0][(idx__ + 1)][29],M__[0][idx__][28]);
    ASGN(M__[0][(idx__ + 1)][30],M__[0][idx__][29]);
    ASGN(M__[0][(idx__ + 1)][31],M__[0][idx__][30]);
  }
  for (int idx__ = 0; idx__ <= 31; idx__++) {
    col_mult__B1(input__[32],input__[33],input__[34],input__[35],input__[36],input__[37],input__[38],input__[39],input__[40],input__[41],input__[42],input__[43],input__[44],input__[45],input__[46],input__[47],input__[48],input__[49],input__[50],input__[51],input__[52],input__[53],input__[54],input__[55],input__[56],input__[57],input__[58],input__[59],input__[60],input__[61],input__[62],input__[63],M__[1][idx__],output__[(32 + idx__)]);
    ASGN(M__[1][(idx__ + 1)][0],M__[1][idx__][31]);
    ASGN(M__[1][(idx__ + 1)][1],M__[1][idx__][0]);
    ASGN(M__[1][(idx__ + 1)][2],M__[1][idx__][1]);
    ASGN(M__[1][(idx__ + 1)][3],M__[1][idx__][2]);
    ASGN(M__[1][(idx__ + 1)][4],M__[1][idx__][3]);
    ASGN(M__[1][(idx__ + 1)][5],M__[1][idx__][4]);
    ASGN(M__[1][(idx__ + 1)][6],M__[1][idx__][5]);
    ASGN(M__[1][(idx__ + 1)][7],M__[1][idx__][6]);
    ASGN(M__[1][(idx__ + 1)][8],M__[1][idx__][7]);
    ASGN(M__[1][(idx__ + 1)][9],M__[1][idx__][8]);
    ASGN(M__[1][(idx__ + 1)][10],M__[1][idx__][9]);
    ASGN(M__[1][(idx__ + 1)][11],M__[1][idx__][10]);
    ASGN(M__[1][(idx__ + 1)][12],M__[1][idx__][11]);
    ASGN(M__[1][(idx__ + 1)][13],M__[1][idx__][12]);
    ASGN(M__[1][(idx__ + 1)][14],M__[1][idx__][13]);
    ASGN(M__[1][(idx__ + 1)][15],M__[1][idx__][14]);
    ASGN(M__[1][(idx__ + 1)][16],M__[1][idx__][15]);
    ASGN(M__[1][(idx__ + 1)][17],M__[1][idx__][16]);
    ASGN(M__[1][(idx__ + 1)][18],M__[1][idx__][17]);
    ASGN(M__[1][(idx__ + 1)][19],M__[1][idx__][18]);
    ASGN(M__[1][(idx__ + 1)][20],M__[1][idx__][19]);
    ASGN(M__[1][(idx__ + 1)][21],M__[1][idx__][20]);
    ASGN(M__[1][(idx__ + 1)][22],M__[1][idx__][21]);
    ASGN(M__[1][(idx__ + 1)][23],M__[1][idx__][22]);
    ASGN(M__[1][(idx__ + 1)][24],M__[1][idx__][23]);
    ASGN(M__[1][(idx__ + 1)][25],M__[1][idx__][24]);
    ASGN(M__[1][(idx__ + 1)][26],M__[1][idx__][25]);
    ASGN(M__[1][(idx__ + 1)][27],M__[1][idx__][26]);
    ASGN(M__[1][(idx__ + 1)][28],M__[1][idx__][27]);
    ASGN(M__[1][(idx__ + 1)][29],M__[1][idx__][28]);
    ASGN(M__[1][(idx__ + 1)][30],M__[1][idx__][29]);
    ASGN(M__[1][(idx__ + 1)][31],M__[1][idx__][30]);
  }
  for (int idx__ = 0; idx__ <= 31; idx__++) {
    col_mult__B1(input__[64],input__[65],input__[66],input__[67],input__[68],input__[69],input__[70],input__[71],input__[72],input__[73],input__[74],input__[75],input__[76],input__[77],input__[78],input__[79],input__[80],input__[81],input__[82],input__[83],input__[84],input__[85],input__[86],input__[87],input__[88],input__[89],input__[90],input__[91],input__[92],input__[93],input__[94],input__[95],M__[2][idx__],output__[(64 + idx__)]);
    ASGN(M__[2][(idx__ + 1)][0],M__[2][idx__][31]);
    ASGN(M__[2][(idx__ + 1)][1],M__[2][idx__][0]);
    ASGN(M__[2][(idx__ + 1)][2],M__[2][idx__][1]);
    ASGN(M__[2][(idx__ + 1)][3],M__[2][idx__][2]);
    ASGN(M__[2][(idx__ + 1)][4],M__[2][idx__][3]);
    ASGN(M__[2][(idx__ + 1)][5],M__[2][idx__][4]);
    ASGN(M__[2][(idx__ + 1)][6],M__[2][idx__][5]);
    ASGN(M__[2][(idx__ + 1)][7],M__[2][idx__][6]);
    ASGN(M__[2][(idx__ + 1)][8],M__[2][idx__][7]);
    ASGN(M__[2][(idx__ + 1)][9],M__[2][idx__][8]);
    ASGN(M__[2][(idx__ + 1)][10],M__[2][idx__][9]);
    ASGN(M__[2][(idx__ + 1)][11],M__[2][idx__][10]);
    ASGN(M__[2][(idx__ + 1)][12],M__[2][idx__][11]);
    ASGN(M__[2][(idx__ + 1)][13],M__[2][idx__][12]);
    ASGN(M__[2][(idx__ + 1)][14],M__[2][idx__][13]);
    ASGN(M__[2][(idx__ + 1)][15],M__[2][idx__][14]);
    ASGN(M__[2][(idx__ + 1)][16],M__[2][idx__][15]);
    ASGN(M__[2][(idx__ + 1)][17],M__[2][idx__][16]);
    ASGN(M__[2][(idx__ + 1)][18],M__[2][idx__][17]);
    ASGN(M__[2][(idx__ + 1)][19],M__[2][idx__][18]);
    ASGN(M__[2][(idx__ + 1)][20],M__[2][idx__][19]);
    ASGN(M__[2][(idx__ + 1)][21],M__[2][idx__][20]);
    ASGN(M__[2][(idx__ + 1)][22],M__[2][idx__][21]);
    ASGN(M__[2][(idx__ + 1)][23],M__[2][idx__][22]);
    ASGN(M__[2][(idx__ + 1)][24],M__[2][idx__][23]);
    ASGN(M__[2][(idx__ + 1)][25],M__[2][idx__][24]);
    ASGN(M__[2][(idx__ + 1)][26],M__[2][idx__][25]);
    ASGN(M__[2][(idx__ + 1)][27],M__[2][idx__][26]);
    ASGN(M__[2][(idx__ + 1)][28],M__[2][idx__][27]);
    ASGN(M__[2][(idx__ + 1)][29],M__[2][idx__][28]);
    ASGN(M__[2][(idx__ + 1)][30],M__[2][idx__][29]);
    ASGN(M__[2][(idx__ + 1)][31],M__[2][idx__][30]);
  }
  for (int idx__ = 0; idx__ <= 31; idx__++) {
    col_mult__B1(input__[96],input__[97],input__[98],input__[99],input__[100],input__[101],input__[102],input__[103],input__[104],input__[105],input__[106],input__[107],input__[108],input__[109],input__[110],input__[111],input__[112],input__[113],input__[114],input__[115],input__[116],input__[117],input__[118],input__[119],input__[120],input__[121],input__[122],input__[123],input__[124],input__[125],input__[126],input__[127],M__[3][idx__],output__[(96 + idx__)]);
    ASGN(M__[3][(idx__ + 1)][0],M__[3][idx__][31]);
    ASGN(M__[3][(idx__ + 1)][1],M__[3][idx__][0]);
    ASGN(M__[3][(idx__ + 1)][2],M__[3][idx__][1]);
    ASGN(M__[3][(idx__ + 1)][3],M__[3][idx__][2]);
    ASGN(M__[3][(idx__ + 1)][4],M__[3][idx__][3]);
    ASGN(M__[3][(idx__ + 1)][5],M__[3][idx__][4]);
    ASGN(M__[3][(idx__ + 1)][6],M__[3][idx__][5]);
    ASGN(M__[3][(idx__ + 1)][7],M__[3][idx__][6]);
    ASGN(M__[3][(idx__ + 1)][8],M__[3][idx__][7]);
    ASGN(M__[3][(idx__ + 1)][9],M__[3][idx__][8]);
    ASGN(M__[3][(idx__ + 1)][10],M__[3][idx__][9]);
    ASGN(M__[3][(idx__ + 1)][11],M__[3][idx__][10]);
    ASGN(M__[3][(idx__ + 1)][12],M__[3][idx__][11]);
    ASGN(M__[3][(idx__ + 1)][13],M__[3][idx__][12]);
    ASGN(M__[3][(idx__ + 1)][14],M__[3][idx__][13]);
    ASGN(M__[3][(idx__ + 1)][15],M__[3][idx__][14]);
    ASGN(M__[3][(idx__ + 1)][16],M__[3][idx__][15]);
    ASGN(M__[3][(idx__ + 1)][17],M__[3][idx__][16]);
    ASGN(M__[3][(idx__ + 1)][18],M__[3][idx__][17]);
    ASGN(M__[3][(idx__ + 1)][19],M__[3][idx__][18]);
    ASGN(M__[3][(idx__ + 1)][20],M__[3][idx__][19]);
    ASGN(M__[3][(idx__ + 1)][21],M__[3][idx__][20]);
    ASGN(M__[3][(idx__ + 1)][22],M__[3][idx__][21]);
    ASGN(M__[3][(idx__ + 1)][23],M__[3][idx__][22]);
    ASGN(M__[3][(idx__ + 1)][24],M__[3][idx__][23]);
    ASGN(M__[3][(idx__ + 1)][25],M__[3][idx__][24]);
    ASGN(M__[3][(idx__ + 1)][26],M__[3][idx__][25]);
    ASGN(M__[3][(idx__ + 1)][27],M__[3][idx__][26]);
    ASGN(M__[3][(idx__ + 1)][28],M__[3][idx__][27]);
    ASGN(M__[3][(idx__ + 1)][29],M__[3][idx__][28]);
    ASGN(M__[3][(idx__ + 1)][30],M__[3][idx__][29]);
    ASGN(M__[3][(idx__ + 1)][31],M__[3][idx__][30]);
  }

}

/* main function */
void pyjamask__ (/*inputs*/ DATATYPE plaintext__[128][MASKING_ORDER],DATATYPE key__[15][128][MASKING_ORDER], /*outputs*/ DATATYPE ciphertext__[128][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp134_[128][MASKING_ORDER];
  DATATYPE _tmp135_[128][MASKING_ORDER];
  DATATYPE round__[128][MASKING_ORDER];

  // Instructions (body)
  ASGN(round__[0],plaintext__[0]);
  ASGN(round__[1],plaintext__[1]);
  ASGN(round__[2],plaintext__[2]);
  ASGN(round__[3],plaintext__[3]);
  ASGN(round__[4],plaintext__[4]);
  ASGN(round__[5],plaintext__[5]);
  ASGN(round__[6],plaintext__[6]);
  ASGN(round__[7],plaintext__[7]);
  ASGN(round__[8],plaintext__[8]);
  ASGN(round__[9],plaintext__[9]);
  ASGN(round__[10],plaintext__[10]);
  ASGN(round__[11],plaintext__[11]);
  ASGN(round__[12],plaintext__[12]);
  ASGN(round__[13],plaintext__[13]);
  ASGN(round__[14],plaintext__[14]);
  ASGN(round__[15],plaintext__[15]);
  ASGN(round__[16],plaintext__[16]);
  ASGN(round__[17],plaintext__[17]);
  ASGN(round__[18],plaintext__[18]);
  ASGN(round__[19],plaintext__[19]);
  ASGN(round__[20],plaintext__[20]);
  ASGN(round__[21],plaintext__[21]);
  ASGN(round__[22],plaintext__[22]);
  ASGN(round__[23],plaintext__[23]);
  ASGN(round__[24],plaintext__[24]);
  ASGN(round__[25],plaintext__[25]);
  ASGN(round__[26],plaintext__[26]);
  ASGN(round__[27],plaintext__[27]);
  ASGN(round__[28],plaintext__[28]);
  ASGN(round__[29],plaintext__[29]);
  ASGN(round__[30],plaintext__[30]);
  ASGN(round__[31],plaintext__[31]);
  ASGN(round__[32],plaintext__[32]);
  ASGN(round__[33],plaintext__[33]);
  ASGN(round__[34],plaintext__[34]);
  ASGN(round__[35],plaintext__[35]);
  ASGN(round__[36],plaintext__[36]);
  ASGN(round__[37],plaintext__[37]);
  ASGN(round__[38],plaintext__[38]);
  ASGN(round__[39],plaintext__[39]);
  ASGN(round__[40],plaintext__[40]);
  ASGN(round__[41],plaintext__[41]);
  ASGN(round__[42],plaintext__[42]);
  ASGN(round__[43],plaintext__[43]);
  ASGN(round__[44],plaintext__[44]);
  ASGN(round__[45],plaintext__[45]);
  ASGN(round__[46],plaintext__[46]);
  ASGN(round__[47],plaintext__[47]);
  ASGN(round__[48],plaintext__[48]);
  ASGN(round__[49],plaintext__[49]);
  ASGN(round__[50],plaintext__[50]);
  ASGN(round__[51],plaintext__[51]);
  ASGN(round__[52],plaintext__[52]);
  ASGN(round__[53],plaintext__[53]);
  ASGN(round__[54],plaintext__[54]);
  ASGN(round__[55],plaintext__[55]);
  ASGN(round__[56],plaintext__[56]);
  ASGN(round__[57],plaintext__[57]);
  ASGN(round__[58],plaintext__[58]);
  ASGN(round__[59],plaintext__[59]);
  ASGN(round__[60],plaintext__[60]);
  ASGN(round__[61],plaintext__[61]);
  ASGN(round__[62],plaintext__[62]);
  ASGN(round__[63],plaintext__[63]);
  ASGN(round__[64],plaintext__[64]);
  ASGN(round__[65],plaintext__[65]);
  ASGN(round__[66],plaintext__[66]);
  ASGN(round__[67],plaintext__[67]);
  ASGN(round__[68],plaintext__[68]);
  ASGN(round__[69],plaintext__[69]);
  ASGN(round__[70],plaintext__[70]);
  ASGN(round__[71],plaintext__[71]);
  ASGN(round__[72],plaintext__[72]);
  ASGN(round__[73],plaintext__[73]);
  ASGN(round__[74],plaintext__[74]);
  ASGN(round__[75],plaintext__[75]);
  ASGN(round__[76],plaintext__[76]);
  ASGN(round__[77],plaintext__[77]);
  ASGN(round__[78],plaintext__[78]);
  ASGN(round__[79],plaintext__[79]);
  ASGN(round__[80],plaintext__[80]);
  ASGN(round__[81],plaintext__[81]);
  ASGN(round__[82],plaintext__[82]);
  ASGN(round__[83],plaintext__[83]);
  ASGN(round__[84],plaintext__[84]);
  ASGN(round__[85],plaintext__[85]);
  ASGN(round__[86],plaintext__[86]);
  ASGN(round__[87],plaintext__[87]);
  ASGN(round__[88],plaintext__[88]);
  ASGN(round__[89],plaintext__[89]);
  ASGN(round__[90],plaintext__[90]);
  ASGN(round__[91],plaintext__[91]);
  ASGN(round__[92],plaintext__[92]);
  ASGN(round__[93],plaintext__[93]);
  ASGN(round__[94],plaintext__[94]);
  ASGN(round__[95],plaintext__[95]);
  ASGN(round__[96],plaintext__[96]);
  ASGN(round__[97],plaintext__[97]);
  ASGN(round__[98],plaintext__[98]);
  ASGN(round__[99],plaintext__[99]);
  ASGN(round__[100],plaintext__[100]);
  ASGN(round__[101],plaintext__[101]);
  ASGN(round__[102],plaintext__[102]);
  ASGN(round__[103],plaintext__[103]);
  ASGN(round__[104],plaintext__[104]);
  ASGN(round__[105],plaintext__[105]);
  ASGN(round__[106],plaintext__[106]);
  ASGN(round__[107],plaintext__[107]);
  ASGN(round__[108],plaintext__[108]);
  ASGN(round__[109],plaintext__[109]);
  ASGN(round__[110],plaintext__[110]);
  ASGN(round__[111],plaintext__[111]);
  ASGN(round__[112],plaintext__[112]);
  ASGN(round__[113],plaintext__[113]);
  ASGN(round__[114],plaintext__[114]);
  ASGN(round__[115],plaintext__[115]);
  ASGN(round__[116],plaintext__[116]);
  ASGN(round__[117],plaintext__[117]);
  ASGN(round__[118],plaintext__[118]);
  ASGN(round__[119],plaintext__[119]);
  ASGN(round__[120],plaintext__[120]);
  ASGN(round__[121],plaintext__[121]);
  ASGN(round__[122],plaintext__[122]);
  ASGN(round__[123],plaintext__[123]);
  ASGN(round__[124],plaintext__[124]);
  ASGN(round__[125],plaintext__[125]);
  ASGN(round__[126],plaintext__[126]);
  ASGN(round__[127],plaintext__[127]);
  for (int i__ = 0; i__ <= 13; i__++) {
    AddRoundKey__B1(round__,key__[i__],_tmp134_);
    SubBytesAll__B1(_tmp134_,_tmp135_);
    MixRows__B1(_tmp135_,round__);
  }
  AddRoundKey__B1(round__,key__[14],ciphertext__);

}

/* Additional functions */


/* **************************************************************** */
/*                            Usuba source                          */
/*                                                                  */
/*

 _no_inline table SubBytes(i :  b4 :: base)
  returns o :  b4 :: base
{
  2, 13, 3, 9, 7, 11, 10, 6, 14, 0, 15, 4, 8, 5, 1, 12
}


_no_inline node AddRoundKey(i :  b128 :: base,k :  b128 :: base)
  returns o :  b128 :: base
vars

let
  (o) = (i ^ k)
tel

_no_inline node SubBytesAll(input :  b128 :: base)
  returns output :  b128 :: base
vars

let
  forall i in [0,31] {
    (output[i,(32 + i),(64 + i),(96 + i)]) = SubBytes(input[i,(32 + i),(64 + i),(96 + i)])
  }
tel

 node col_mult(a :  b32 :: base,b : const b32 :: base)
  returns r :  b1 :: base
vars
  acc :  b32 :: base
let
  (acc[0]) = (a[0] & b[0]);
  forall i in [1,31] {
    (acc[i]) = (acc[(i - 1)] ^ (a[i] & b[i]))
  };
  (r) = acc[31]
tel

_no_inline node MixRows(input :  b32[4] :: base)
  returns output :  b32[4] :: base
vars
  M : const b32[4][33] :: base
let
  (M[0][0]) = (1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1);
  (M[1][0]) = (0,1,1,0,0,0,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1);
  (M[2][0]) = (0,1,1,0,1,0,0,1,0,0,1,0,1,1,0,0,1,1,1,1,0,0,1,0,1,0,0,0,0,0,0,0);
  (M[3][0]) = (0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1);
  forall col in [0,3] {
    forall idx in [0,31] {
      (output[col][idx]) = col_mult(input[col],M[col][idx]);
      (M[col][(idx + 1)]) = (M[col][idx] >>> 1)
    }
  }
tel

 node pyjamask(plaintext :  b128 :: base,key :  b128[15] :: base)
  returns ciphertext :  b128 :: base
vars
  round :  b128[15] :: base
let
  (round[0]) = plaintext;
  forall i in [0,13] {
    (round[(i + 1)]) = MixRows(SubBytesAll(AddRoundKey(round[i],key[i])))
  };
  (ciphertext) = AddRoundKey(round[14],key[14])
tel

*/
 