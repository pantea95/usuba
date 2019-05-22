/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba. */


/* Do NOT change the order of those define/include */
#define NO_RUNTIME
#ifndef BITS_PER_REG
#define BITS_PER_REG 64
#endif
/* including the architecture specific .h */
#include "STD.h"

/* auxiliary functions */
void andTI__ (/*inputs*/ DATATYPE a__0__,DATATYPE a__1__,DATATYPE a__2__,DATATYPE b__0__,DATATYPE b__1__,DATATYPE b__2__,DATATYPE r__0__,DATATYPE r__1__,DATATYPE r__2__, /*outputs*/ DATATYPE* x__0__,DATATYPE* x__1__,DATATYPE* x__2__) {
  
  // Variables declaration
  DATATYPE c1__0__;
  DATATYPE c1__1__;
  DATATYPE c1__2__;
  DATATYPE c2__0__;
  DATATYPE c2__1__;
  DATATYPE c2__2__;
  DATATYPE c3__0__;
  DATATYPE c3__1__;
  DATATYPE c3__2__;
  DATATYPE d1__0__;
  DATATYPE d1__1__;
  DATATYPE d1__2__;
  DATATYPE d2__0__;
  DATATYPE d2__1__;
  DATATYPE d2__2__;
  DATATYPE d3__0__;
  DATATYPE d3__1__;
  DATATYPE d3__2__;
  DATATYPE d4__0__;
  DATATYPE d4__1__;
  DATATYPE d4__2__;


  // Instructions (body)
  c1__0__ = AND(a__0__,b__0__);
  c1__1__ = AND(a__1__,b__1__);
  c1__2__ = AND(a__2__,b__2__);
  c2__0__ = AND(a__0__,b__1__);
  c2__1__ = AND(a__1__,b__2__);
  c2__2__ = AND(a__2__,b__0__);
  c3__0__ = AND(a__1__,b__0__);
  c3__1__ = AND(a__2__,b__1__);
  c3__2__ = AND(a__0__,b__2__);
  d1__0__ = XOR(c1__0__,r__0__);
  d1__1__ = XOR(c1__1__,r__1__);
  d1__2__ = XOR(c1__2__,r__2__);
  d2__0__ = XOR(d1__0__,c2__0__);
  d2__1__ = XOR(d1__1__,c2__1__);
  d2__2__ = XOR(d1__2__,c2__2__);
  d3__0__ = XOR(d2__0__,c3__0__);
  d3__1__ = XOR(d2__1__,c3__1__);
  d3__2__ = XOR(d2__2__,c3__2__);
  d4__0__ = XOR(d3__0__,r__1__);
  d4__1__ = XOR(d3__1__,r__2__);
  d4__2__ = XOR(d3__2__,r__0__);
  *x__0__ = d4__0__;
  *x__1__ = d4__1__;
  *x__2__ = d4__2__;

}

void andTI____ (/*inputs*/ DATATYPE a__0__,DATATYPE a__1__,DATATYPE a__2__,DATATYPE b__0__,DATATYPE b__1__,DATATYPE b__2__,DATATYPE r__0__,DATATYPE r__1__,DATATYPE r__2__, /*outputs*/ DATATYPE* x__0__,DATATYPE* x__1__,DATATYPE* x__2__) {
  
  // Variables declaration
  DATATYPE c1__0__;
  DATATYPE c1__1__;
  DATATYPE c1__2__;
  DATATYPE c2__0__;
  DATATYPE c2__1__;
  DATATYPE c2__2__;
  DATATYPE c3__0__;
  DATATYPE c3__1__;
  DATATYPE c3__2__;
  DATATYPE d1__0__;
  DATATYPE d1__1__;
  DATATYPE d1__2__;
  DATATYPE d2__0__;
  DATATYPE d2__1__;
  DATATYPE d2__2__;
  DATATYPE d3__0__;
  DATATYPE d3__1__;
  DATATYPE d3__2__;
  DATATYPE d4__0__;
  DATATYPE d4__1__;
  DATATYPE d4__2__;


  // Instructions (body)
  c1__0__ = OR(a__0__,b__0__);
  c1__1__ = OR(a__1__,b__1__);
  c1__2__ = OR(a__2__,b__2__);
  c2__0__ = OR(a__0__,b__1__);
  c2__1__ = OR(a__1__,b__2__);
  c2__2__ = OR(a__2__,b__0__);
  c3__0__ = OR(a__1__,b__0__);
  c3__1__ = OR(a__2__,b__1__);
  c3__2__ = OR(a__0__,b__2__);
  d1__0__ = XOR(c1__0__,r__0__);
  d1__1__ = XOR(c1__1__,r__1__);
  d1__2__ = XOR(c1__2__,r__2__);
  d2__0__ = XOR(d1__0__,c2__0__);
  d2__1__ = XOR(d1__1__,c2__1__);
  d2__2__ = XOR(d1__2__,c2__2__);
  d3__0__ = XOR(d2__0__,c3__0__);
  d3__1__ = XOR(d2__1__,c3__1__);
  d3__2__ = XOR(d2__2__,c3__2__);
  d4__0__ = XOR(d3__0__,r__1__);
  d4__1__ = XOR(d3__1__,r__2__);
  d4__2__ = XOR(d3__2__,r__0__);
  *x__0__ = d4__0__;
  *x__1__ = d4__1__;
  *x__2__ = d4__2__;

}

void notTI__ (/*inputs*/ DATATYPE a__0__,DATATYPE a__1__,DATATYPE a__2__, /*outputs*/ DATATYPE* a____0__,DATATYPE* a____1__,DATATYPE* a____2__) {
  
  // Variables declaration
  DATATYPE _tmp7_;


  // Instructions (body)
  _tmp7_ = NOT(a__0__);
  *a____0__ = _tmp7_;
  *a____1__ = a__1__;
  *a____2__ = a__2__;

}

/* main function */
void orTI__ (/*inputs*/ DATATYPE a__0__,DATATYPE a__1__,DATATYPE a__2__,DATATYPE b__0__,DATATYPE b__1__,DATATYPE b__2__,DATATYPE r__0__,DATATYPE r__1__,DATATYPE r__2__, /*outputs*/ DATATYPE* x__0__,DATATYPE* x__1__,DATATYPE* x__2__) {
  
  // Variables declaration
  DATATYPE _tmp8_1;
  DATATYPE _tmp8_2;
  DATATYPE _tmp8_3;
  DATATYPE _tmp9_1;
  DATATYPE _tmp9_2;
  DATATYPE _tmp9_3;


  // Instructions (body)
  notTI__(a__0__,a__1__,a__2__,&_tmp8_1,&_tmp8_2,&_tmp8_3);
  notTI__(b__0__,b__1__,b__2__,&_tmp9_1,&_tmp9_2,&_tmp9_3);
  andTI__(_tmp8_1,_tmp8_2,_tmp8_3,_tmp9_1,_tmp9_2,_tmp9_3,r__0__,r__1__,r__2__,&_tmp8_1,&_tmp8_2,&_tmp8_3);
  notTI__(_tmp8_1,_tmp8_2,_tmp8_3,&*x__0__,&*x__1__,&*x__2__);

}
 