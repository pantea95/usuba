/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba.
   From the file "nist/ace/usuba/ua/ace.ua" (included below). */

#include <stdint.h>

/* Do NOT change the order of those define/include */

#ifndef BITS_PER_REG
#define BITS_PER_REG 32
#endif
/* including the architecture specific .h */
#include "MASKED.h"

/* auxiliary functions */
void f__V32 (/*inputs*/ DATATYPE x__[MASKING_ORDER], /*outputs*/ DATATYPE y__[MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp1_[MASKING_ORDER];
  DATATYPE _tmp2_[MASKING_ORDER];
  DATATYPE _tmp3_[MASKING_ORDER];
  DATATYPE _tmp4_[MASKING_ORDER];

  // Instructions (body)
  L_ROTATE(_tmp1_,x__,5,32);
  REFRESH(_tmp2_,x__);
  AND(_tmp3_,_tmp1_,_tmp2_);
  L_ROTATE(_tmp4_,x__,1,32);
  XOR(y__,_tmp3_,_tmp4_);

}

void simeck_box__V32 (/*inputs*/ DATATYPE input__[2][MASKING_ORDER],DATATYPE rc__[MASKING_ORDER], /*outputs*/ DATATYPE output__[2][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp11_[MASKING_ORDER];
  DATATYPE _tmp12_[MASKING_ORDER];
  DATATYPE _tmp13_[MASKING_ORDER];
  DATATYPE _tmp15_[MASKING_ORDER];
  DATATYPE _tmp16_[MASKING_ORDER];
  DATATYPE _tmp18_[MASKING_ORDER];
  DATATYPE _tmp19_[MASKING_ORDER];
  DATATYPE _tmp20_[MASKING_ORDER];
  DATATYPE _tmp22_[MASKING_ORDER];
  DATATYPE _tmp23_[MASKING_ORDER];
  DATATYPE _tmp25_[MASKING_ORDER];
  DATATYPE _tmp26_[MASKING_ORDER];
  DATATYPE _tmp27_[MASKING_ORDER];
  DATATYPE _tmp29_[MASKING_ORDER];
  DATATYPE _tmp30_[MASKING_ORDER];
  DATATYPE _tmp32_[MASKING_ORDER];
  DATATYPE _tmp33_[MASKING_ORDER];
  DATATYPE _tmp34_[MASKING_ORDER];
  DATATYPE _tmp36_[MASKING_ORDER];
  DATATYPE _tmp37_[MASKING_ORDER];
  DATATYPE _tmp39_[MASKING_ORDER];
  DATATYPE _tmp40_[MASKING_ORDER];
  DATATYPE _tmp41_[MASKING_ORDER];
  DATATYPE _tmp43_[MASKING_ORDER];
  DATATYPE _tmp44_[MASKING_ORDER];
  DATATYPE _tmp46_[MASKING_ORDER];
  DATATYPE _tmp47_[MASKING_ORDER];
  DATATYPE _tmp48_[MASKING_ORDER];
  DATATYPE _tmp50_[MASKING_ORDER];
  DATATYPE _tmp51_[MASKING_ORDER];
  DATATYPE _tmp53_[MASKING_ORDER];
  DATATYPE _tmp54_[MASKING_ORDER];
  DATATYPE _tmp55_[MASKING_ORDER];
  DATATYPE _tmp57_[MASKING_ORDER];
  DATATYPE _tmp58_[MASKING_ORDER];
  DATATYPE _tmp5_[MASKING_ORDER];
  DATATYPE _tmp60_[MASKING_ORDER];
  DATATYPE _tmp6_[MASKING_ORDER];
  DATATYPE _tmp8_[MASKING_ORDER];
  DATATYPE _tmp9_[MASKING_ORDER];
  DATATYPE round__[9][2][MASKING_ORDER];
  DATATYPE tmp__[MASKING_ORDER];
  DATATYPE _tmp187_[MASKING_ORDER];
  DATATYPE _tmp186_[MASKING_ORDER];
  DATATYPE _tmp185_[MASKING_ORDER];
  DATATYPE _tmp184_[MASKING_ORDER];
  DATATYPE _tmp183_[MASKING_ORDER];
  DATATYPE _tmp182_[MASKING_ORDER];
  DATATYPE _tmp181_[MASKING_ORDER];
  DATATYPE _tmp180_[MASKING_ORDER];
  DATATYPE _tmp179_[MASKING_ORDER];
  DATATYPE _tmp178_[MASKING_ORDER];
  DATATYPE _tmp177_[MASKING_ORDER];
  DATATYPE _tmp176_[MASKING_ORDER];
  DATATYPE _tmp175_[MASKING_ORDER];
  DATATYPE _tmp174_[MASKING_ORDER];
  DATATYPE _tmp173_[MASKING_ORDER];
  DATATYPE _tmp172_[MASKING_ORDER];

  // Instructions (body)
  ASGN(round__[0][0],input__[0]);
  ASGN(round__[0][1],input__[1]);
  f__V32(round__[0][0],_tmp5_);
  XOR(_tmp6_,_tmp5_,round__[0][1]);
  ASGN_CST(_tmp172_, LIFT_32(4294967294));
  XOR_CST(_tmp8_,_tmp6_,_tmp172_);
  R_SHIFT(_tmp9_,rc__,0,32);
  ASGN_CST(_tmp173_, LIFT_32(1));
  AND_CST(_tmp11_,_tmp9_,_tmp173_);
  XOR(tmp__,_tmp8_,_tmp11_);
  ASGN(round__[1][0],tmp__);
  ASGN(round__[1][1],round__[0][0]);
  f__V32(round__[1][0],_tmp12_);
  XOR(_tmp13_,_tmp12_,round__[1][1]);
  ASGN_CST(_tmp174_, LIFT_32(4294967294));
  XOR_CST(_tmp15_,_tmp13_,_tmp174_);
  R_SHIFT(_tmp16_,rc__,1,32);
  ASGN_CST(_tmp175_, LIFT_32(1));
  AND_CST(_tmp18_,_tmp16_,_tmp175_);
  XOR(tmp__,_tmp15_,_tmp18_);
  ASGN(round__[2][0],tmp__);
  ASGN(round__[2][1],round__[1][0]);
  f__V32(round__[2][0],_tmp19_);
  XOR(_tmp20_,_tmp19_,round__[2][1]);
  ASGN_CST(_tmp176_, LIFT_32(4294967294));
  XOR_CST(_tmp22_,_tmp20_,_tmp176_);
  R_SHIFT(_tmp23_,rc__,2,32);
  ASGN_CST(_tmp177_, LIFT_32(1));
  AND_CST(_tmp25_,_tmp23_,_tmp177_);
  XOR(tmp__,_tmp22_,_tmp25_);
  ASGN(round__[3][0],tmp__);
  ASGN(round__[3][1],round__[2][0]);
  f__V32(round__[3][0],_tmp26_);
  XOR(_tmp27_,_tmp26_,round__[3][1]);
  ASGN_CST(_tmp178_, LIFT_32(4294967294));
  XOR_CST(_tmp29_,_tmp27_,_tmp178_);
  R_SHIFT(_tmp30_,rc__,3,32);
  ASGN_CST(_tmp179_, LIFT_32(1));
  AND_CST(_tmp32_,_tmp30_,_tmp179_);
  XOR(tmp__,_tmp29_,_tmp32_);
  ASGN(round__[4][0],tmp__);
  ASGN(round__[4][1],round__[3][0]);
  f__V32(round__[4][0],_tmp33_);
  XOR(_tmp34_,_tmp33_,round__[4][1]);
  ASGN_CST(_tmp180_, LIFT_32(4294967294));
  XOR_CST(_tmp36_,_tmp34_,_tmp180_);
  R_SHIFT(_tmp37_,rc__,4,32);
  ASGN_CST(_tmp181_, LIFT_32(1));
  AND_CST(_tmp39_,_tmp37_,_tmp181_);
  XOR(tmp__,_tmp36_,_tmp39_);
  ASGN(round__[5][0],tmp__);
  ASGN(round__[5][1],round__[4][0]);
  f__V32(round__[5][0],_tmp40_);
  XOR(_tmp41_,_tmp40_,round__[5][1]);
  ASGN_CST(_tmp182_, LIFT_32(4294967294));
  XOR_CST(_tmp43_,_tmp41_,_tmp182_);
  R_SHIFT(_tmp44_,rc__,5,32);
  ASGN_CST(_tmp183_, LIFT_32(1));
  AND_CST(_tmp46_,_tmp44_,_tmp183_);
  XOR(tmp__,_tmp43_,_tmp46_);
  ASGN(round__[6][0],tmp__);
  ASGN(round__[6][1],round__[5][0]);
  f__V32(round__[6][0],_tmp47_);
  XOR(_tmp48_,_tmp47_,round__[6][1]);
  ASGN_CST(_tmp184_, LIFT_32(4294967294));
  XOR_CST(_tmp50_,_tmp48_,_tmp184_);
  R_SHIFT(_tmp51_,rc__,6,32);
  ASGN_CST(_tmp185_, LIFT_32(1));
  AND_CST(_tmp53_,_tmp51_,_tmp185_);
  XOR(tmp__,_tmp50_,_tmp53_);
  ASGN(round__[7][0],tmp__);
  ASGN(round__[7][1],round__[6][0]);
  f__V32(round__[7][0],_tmp54_);
  XOR(_tmp55_,_tmp54_,round__[7][1]);
  ASGN_CST(_tmp186_, LIFT_32(4294967294));
  XOR_CST(_tmp57_,_tmp55_,_tmp186_);
  R_SHIFT(_tmp58_,rc__,7,32);
  ASGN_CST(_tmp187_, LIFT_32(1));
  AND_CST(_tmp60_,_tmp58_,_tmp187_);
  XOR(tmp__,_tmp57_,_tmp60_);
  ASGN(round__[8][0],tmp__);
  ASGN(round__[8][1],round__[7][0]);
  ASGN(output__[0],round__[8][0]);
  ASGN(output__[1],round__[8][1]);

}

void ACE_step__V32 (/*inputs*/ DATATYPE A__[2][MASKING_ORDER],DATATYPE B__[2][MASKING_ORDER],DATATYPE C__[2][MASKING_ORDER],DATATYPE D__[2][MASKING_ORDER],DATATYPE E__[2][MASKING_ORDER],DATATYPE RC__0__[MASKING_ORDER],DATATYPE RC__1__[MASKING_ORDER],DATATYPE RC__2__[MASKING_ORDER],DATATYPE SC__0__[MASKING_ORDER],DATATYPE SC__1__[MASKING_ORDER],DATATYPE SC__2__[MASKING_ORDER], /*outputs*/ DATATYPE Ar__[2][MASKING_ORDER],DATATYPE Br__[2][MASKING_ORDER],DATATYPE Cr__[2][MASKING_ORDER],DATATYPE Dr__[2][MASKING_ORDER],DATATYPE Er__[2][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _shadow_A__1_[2][MASKING_ORDER];
  DATATYPE _shadow_B__4_[2][MASKING_ORDER];
  DATATYPE _shadow_C__2_[2][MASKING_ORDER];
  DATATYPE _shadow_D__5_[2][MASKING_ORDER];
  DATATYPE _shadow_E__3_[2][MASKING_ORDER];
  DATATYPE _shadow_E__6_[2][MASKING_ORDER];
  DATATYPE _tmp61_[2][MASKING_ORDER];
  DATATYPE _tmp63_[MASKING_ORDER];
  DATATYPE _tmp66_[2][MASKING_ORDER];
  DATATYPE _tmp68_[MASKING_ORDER];
  DATATYPE _tmp71_[2][MASKING_ORDER];
  DATATYPE _tmp73_[MASKING_ORDER];
  DATATYPE _tmp190_[MASKING_ORDER];
  DATATYPE _tmp189_[MASKING_ORDER];
  DATATYPE _tmp188_[MASKING_ORDER];

  // Instructions (body)
  simeck_box__V32(A__,RC__0__,_shadow_A__1_);
  simeck_box__V32(C__,RC__1__,_shadow_C__2_);
  simeck_box__V32(E__,RC__2__,_shadow_E__3_);
  XOR(_tmp61_[0],B__[0],_shadow_C__2_[0]);
  XOR(_tmp61_[1],B__[1],_shadow_C__2_[1]);
  XOR(_tmp63_,_tmp61_[1],SC__0__);
  NOT(_shadow_B__4_[0],_tmp61_[0]);
  ASGN_CST(_tmp188_, LIFT_32(4294967040));
  XOR_CST(_shadow_B__4_[1],_tmp63_,_tmp188_);
  XOR(_tmp66_[0],D__[0],_shadow_E__3_[0]);
  XOR(_tmp66_[1],D__[1],_shadow_E__3_[1]);
  XOR(_tmp68_,_tmp66_[1],SC__1__);
  NOT(_shadow_D__5_[0],_tmp66_[0]);
  ASGN_CST(_tmp189_, LIFT_32(4294967040));
  XOR_CST(_shadow_D__5_[1],_tmp68_,_tmp189_);
  XOR(_tmp71_[0],_shadow_E__3_[0],_shadow_A__1_[0]);
  XOR(_tmp71_[1],_shadow_E__3_[1],_shadow_A__1_[1]);
  XOR(_tmp73_,_tmp71_[1],SC__2__);
  NOT(_shadow_E__6_[0],_tmp71_[0]);
  ASGN_CST(_tmp190_, LIFT_32(4294967040));
  XOR_CST(_shadow_E__6_[1],_tmp73_,_tmp190_);
  ASGN(Ar__[0],_shadow_D__5_[0]);
  ASGN(Ar__[1],_shadow_D__5_[1]);
  ASGN(Br__[0],_shadow_C__2_[0]);
  ASGN(Br__[1],_shadow_C__2_[1]);
  ASGN(Cr__[0],_shadow_A__1_[0]);
  ASGN(Cr__[1],_shadow_A__1_[1]);
  ASGN(Dr__[0],_shadow_E__6_[0]);
  ASGN(Dr__[1],_shadow_E__6_[1]);
  ASGN(Er__[0],_shadow_B__4_[0]);
  ASGN(Er__[1],_shadow_B__4_[1]);

}

/* main function */
void ACE__ (/*inputs*/ DATATYPE input__[5][2][MASKING_ORDER], /*outputs*/ DATATYPE output__[5][2][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE RC__[3][16][MASKING_ORDER];
  DATATYPE SC__[3][16][MASKING_ORDER];
  DATATYPE tmp__[5][2][MASKING_ORDER];

  // Instructions (body)
  ASGN_CST(SC__[0][0], LIFT_32(80));
  ASGN_CST(SC__[0][1], LIFT_32(92));
  ASGN_CST(SC__[0][2], LIFT_32(145));
  ASGN_CST(SC__[0][3], LIFT_32(141));
  ASGN_CST(SC__[0][4], LIFT_32(83));
  ASGN_CST(SC__[0][5], LIFT_32(96));
  ASGN_CST(SC__[0][6], LIFT_32(104));
  ASGN_CST(SC__[0][7], LIFT_32(225));
  ASGN_CST(SC__[0][8], LIFT_32(246));
  ASGN_CST(SC__[0][9], LIFT_32(157));
  ASGN_CST(SC__[0][10], LIFT_32(64));
  ASGN_CST(SC__[0][11], LIFT_32(79));
  ASGN_CST(SC__[0][12], LIFT_32(190));
  ASGN_CST(SC__[0][13], LIFT_32(91));
  ASGN_CST(SC__[0][14], LIFT_32(233));
  ASGN_CST(SC__[0][15], LIFT_32(127));
  ASGN_CST(SC__[1][0], LIFT_32(40));
  ASGN_CST(SC__[1][1], LIFT_32(174));
  ASGN_CST(SC__[1][2], LIFT_32(72));
  ASGN_CST(SC__[1][3], LIFT_32(198));
  ASGN_CST(SC__[1][4], LIFT_32(169));
  ASGN_CST(SC__[1][5], LIFT_32(48));
  ASGN_CST(SC__[1][6], LIFT_32(52));
  ASGN_CST(SC__[1][7], LIFT_32(112));
  ASGN_CST(SC__[1][8], LIFT_32(123));
  ASGN_CST(SC__[1][9], LIFT_32(206));
  ASGN_CST(SC__[1][10], LIFT_32(32));
  ASGN_CST(SC__[1][11], LIFT_32(39));
  ASGN_CST(SC__[1][12], LIFT_32(95));
  ASGN_CST(SC__[1][13], LIFT_32(173));
  ASGN_CST(SC__[1][14], LIFT_32(116));
  ASGN_CST(SC__[1][15], LIFT_32(63));
  ASGN_CST(SC__[2][0], LIFT_32(20));
  ASGN_CST(SC__[2][1], LIFT_32(87));
  ASGN_CST(SC__[2][2], LIFT_32(36));
  ASGN_CST(SC__[2][3], LIFT_32(99));
  ASGN_CST(SC__[2][4], LIFT_32(84));
  ASGN_CST(SC__[2][5], LIFT_32(24));
  ASGN_CST(SC__[2][6], LIFT_32(154));
  ASGN_CST(SC__[2][7], LIFT_32(56));
  ASGN_CST(SC__[2][8], LIFT_32(189));
  ASGN_CST(SC__[2][9], LIFT_32(103));
  ASGN_CST(SC__[2][10], LIFT_32(16));
  ASGN_CST(SC__[2][11], LIFT_32(19));
  ASGN_CST(SC__[2][12], LIFT_32(47));
  ASGN_CST(SC__[2][13], LIFT_32(214));
  ASGN_CST(SC__[2][14], LIFT_32(186));
  ASGN_CST(SC__[2][15], LIFT_32(31));
  ASGN_CST(RC__[0][0], LIFT_32(7));
  ASGN_CST(RC__[0][1], LIFT_32(10));
  ASGN_CST(RC__[0][2], LIFT_32(155));
  ASGN_CST(RC__[0][3], LIFT_32(224));
  ASGN_CST(RC__[0][4], LIFT_32(209));
  ASGN_CST(RC__[0][5], LIFT_32(26));
  ASGN_CST(RC__[0][6], LIFT_32(34));
  ASGN_CST(RC__[0][7], LIFT_32(247));
  ASGN_CST(RC__[0][8], LIFT_32(98));
  ASGN_CST(RC__[0][9], LIFT_32(150));
  ASGN_CST(RC__[0][10], LIFT_32(113));
  ASGN_CST(RC__[0][11], LIFT_32(170));
  ASGN_CST(RC__[0][12], LIFT_32(43));
  ASGN_CST(RC__[0][13], LIFT_32(233));
  ASGN_CST(RC__[0][14], LIFT_32(207));
  ASGN_CST(RC__[0][15], LIFT_32(183));
  ASGN_CST(RC__[1][0], LIFT_32(83));
  ASGN_CST(RC__[1][1], LIFT_32(93));
  ASGN_CST(RC__[1][2], LIFT_32(73));
  ASGN_CST(RC__[1][3], LIFT_32(127));
  ASGN_CST(RC__[1][4], LIFT_32(190));
  ASGN_CST(RC__[1][5], LIFT_32(29));
  ASGN_CST(RC__[1][6], LIFT_32(40));
  ASGN_CST(RC__[1][7], LIFT_32(108));
  ASGN_CST(RC__[1][8], LIFT_32(130));
  ASGN_CST(RC__[1][9], LIFT_32(71));
  ASGN_CST(RC__[1][10], LIFT_32(107));
  ASGN_CST(RC__[1][11], LIFT_32(136));
  ASGN_CST(RC__[1][12], LIFT_32(220));
  ASGN_CST(RC__[1][13], LIFT_32(139));
  ASGN_CST(RC__[1][14], LIFT_32(89));
  ASGN_CST(RC__[1][15], LIFT_32(198));
  ASGN_CST(RC__[2][0], LIFT_32(67));
  ASGN_CST(RC__[2][1], LIFT_32(228));
  ASGN_CST(RC__[2][2], LIFT_32(94));
  ASGN_CST(RC__[2][3], LIFT_32(204));
  ASGN_CST(RC__[2][4], LIFT_32(50));
  ASGN_CST(RC__[2][5], LIFT_32(78));
  ASGN_CST(RC__[2][6], LIFT_32(117));
  ASGN_CST(RC__[2][7], LIFT_32(37));
  ASGN_CST(RC__[2][8], LIFT_32(253));
  ASGN_CST(RC__[2][9], LIFT_32(249));
  ASGN_CST(RC__[2][10], LIFT_32(118));
  ASGN_CST(RC__[2][11], LIFT_32(160));
  ASGN_CST(RC__[2][12], LIFT_32(176));
  ASGN_CST(RC__[2][13], LIFT_32(9));
  ASGN_CST(RC__[2][14], LIFT_32(30));
  ASGN_CST(RC__[2][15], LIFT_32(173));
  ASGN(tmp__[0][0],input__[0][0]);
  ASGN(tmp__[0][1],input__[0][1]);
  ASGN(tmp__[1][0],input__[1][0]);
  ASGN(tmp__[1][1],input__[1][1]);
  ASGN(tmp__[2][0],input__[2][0]);
  ASGN(tmp__[2][1],input__[2][1]);
  ASGN(tmp__[3][0],input__[3][0]);
  ASGN(tmp__[3][1],input__[3][1]);
  ASGN(tmp__[4][0],input__[4][0]);
  ASGN(tmp__[4][1],input__[4][1]);
  for (int i__ = 0; i__ <= 15; i__++) {
    ACE_step__V32(tmp__[0],tmp__[1],tmp__[2],tmp__[3],tmp__[4],RC__[0][i__],RC__[1][i__],RC__[2][i__],SC__[0][i__],SC__[1][i__],SC__[2][i__],tmp__[0],tmp__[1],tmp__[2],tmp__[3],tmp__[4]);
  }
  ASGN(output__[0][0],tmp__[0][0]);
  ASGN(output__[0][1],tmp__[0][1]);
  ASGN(output__[1][0],tmp__[1][0]);
  ASGN(output__[1][1],tmp__[1][1]);
  ASGN(output__[2][0],tmp__[2][0]);
  ASGN(output__[2][1],tmp__[2][1]);
  ASGN(output__[3][0],tmp__[3][0]);
  ASGN(output__[3][1],tmp__[3][1]);
  ASGN(output__[4][0],tmp__[4][0]);
  ASGN(output__[4][1],tmp__[4][1]);

}

/* Additional functions */
uint32_t bench_speed() {
  /* inputs */
  DATATYPE input__[5][2][MASKING_ORDER] = { 0 };
  /* outputs */
  DATATYPE output__[5][2][MASKING_ORDER] = { 0 };
  /* fun call */
  ACE__(input__,output__);

  /* Returning the number of encrypted bytes */
  return 40;
}

/* **************************************************************** */
/*                            Usuba source                          */
/*                                                                  */
/*

 node f(x :  u32 :: base)
  returns y :  u32 :: base
vars

let
  (y) = (((x <<< 5) & refresh(x)) ^ (x <<< 1))
tel

 node simeck_box(input :  u32x2 :: base,rc :  u32 :: base)
  returns output :  u32x2 :: base
vars
  round :  u32x2[9] :: base,
  tmp :  u32[8] :: base
let
  (round[0]) = input;
  _unroll forall i in [0,7] {
    (tmp[i]) = (((f(round[i][0]) ^ round[i][1]) ^ 4294967294) ^ ((rc >> i) & 1));
    (round[(i + 1)][0,1]) = (tmp[i],round[i][0])
  };
  (output) = round[8]
tel

 node ACE_step(A :  u32x2 :: base,B :  u32x2 :: base,C :  u32x2 :: base,D :  u32x2 :: base,E :  u32x2 :: base,RC :  u32[3] :: base,SC :  u32[3] :: base)
  returns Ar :  u32x2 :: base,Br :  u32x2 :: base,Cr :  u32x2 :: base,Dr :  u32x2 :: base,Er :  u32x2 :: base
vars

let
  (A) := simeck_box(A,RC[0]);
  (C) := simeck_box(C,RC[1]);
  (E) := simeck_box(E,RC[2]);
  (B) := (((B ^ C) ^ (0,SC[0])) ^ (4294967295,4294967040));
  (D) := (((D ^ E) ^ (0,SC[1])) ^ (4294967295,4294967040));
  (E) := (((E ^ A) ^ (0,SC[2])) ^ (4294967295,4294967040));
  (Ar) = D;
  (Br) = C;
  (Cr) = A;
  (Dr) = E;
  (Er) = B
tel

 node ACE(input :  u32x2[5] :: base)
  returns output :  u32x2[5] :: base
vars
  SC :  u32[3][16] :: base,
  RC :  u32[3][16] :: base,
  tmp :  u32x2[17][5] :: base
let
  (SC) = (80,92,145,141,83,96,104,225,246,157,64,79,190,91,233,127,40,174,72,198,169,48,52,112,123,206,32,39,95,173,116,63,20,87,36,99,84,24,154,56,189,103,16,19,47,214,186,31);
  (RC) = (7,10,155,224,209,26,34,247,98,150,113,170,43,233,207,183,83,93,73,127,190,29,40,108,130,71,107,136,220,139,89,198,67,228,94,204,50,78,117,37,253,249,118,160,176,9,30,173);
  (tmp[0]) = input;
  forall i in [0,15] {
    (tmp[(i + 1)]) = ACE_step(tmp[i],RC[0,1,2][i],SC[0,1,2][i])
  };
  (output) = tmp[16]
tel

*/
 