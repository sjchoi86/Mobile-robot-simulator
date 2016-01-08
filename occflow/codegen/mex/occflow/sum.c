/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "occflow.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "occflow_data.h"

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 13, "sum",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/sum.m" };

static emlrtRSInfo x_emlrtRSI = { 46, "sumprod",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRSInfo y_emlrtRSI = { 36, "combine_vector_elements",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 19, 15, "sumprod",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 39, 9, "sumprod",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

/* Function Definitions */
real_T sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  boolean_T overflow;
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &w_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &n_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (x->size[k] != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &o_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &x_emlrtRSI;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    c_st.site = &y_emlrtRSI;
    if (2 > x->size[1]) {
      overflow = false;
    } else {
      overflow = (x->size[1] > 2147483646);
    }

    if (overflow) {
      d_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 2; k <= x->size[1]; k++) {
      y += x->data[k - 1];
    }
  }

  return y;
}

/* End of code generation (sum.c) */
