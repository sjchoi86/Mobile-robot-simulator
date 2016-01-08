/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_get_pathcosts_mex.c
 *
 * Code generation for function '_coder_get_pathcosts_mex'
 *
 */

/* Include files */
#include "get_pathcosts.h"
#include "_coder_get_pathcosts_mex.h"
#include "get_pathcosts_terminate.h"
#include "_coder_get_pathcosts_api.h"
#include "get_pathcosts_initialize.h"
#include "get_pathcosts_data.h"

/* Function Declarations */
static void get_pathcosts_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T
  nrhs, const mxArray *prhs[7]);

/* Function Definitions */
static void get_pathcosts_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T
  nrhs, const mxArray *prhs[7])
{
  int32_T n;
  const mxArray *inputs[7];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        13, "get_pathcosts");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "get_pathcosts");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  get_pathcosts_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  get_pathcosts_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(get_pathcosts_atexit);

  /* Module initialization. */
  get_pathcosts_initialize();

  /* Dispatch the entry-point. */
  get_pathcosts_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_get_pathcosts_mex.c) */
