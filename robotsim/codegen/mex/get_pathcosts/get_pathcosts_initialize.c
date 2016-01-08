/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_pathcosts_initialize.c
 *
 * Code generation for function 'get_pathcosts_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_pathcosts.h"
#include "get_pathcosts_initialize.h"
#include "get_pathcosts_data.h"

/* Function Definitions */
void get_pathcosts_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (get_pathcosts_initialize.c) */
