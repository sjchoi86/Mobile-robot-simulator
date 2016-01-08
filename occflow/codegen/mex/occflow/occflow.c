/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * occflow.c
 *
 * Code generation for function 'occflow'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "occflow.h"
#include "occflow_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "sum.h"
#include "exp.h"
#include "occflow_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 15, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRSInfo b_emlrtRSI = { 17, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRSInfo c_emlrtRSI = { 19, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRSInfo d_emlrtRSI = { 26, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRSInfo e_emlrtRSI = { 30, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRSInfo f_emlrtRSI = { 74, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRSInfo g_emlrtRSI = { 97, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRSInfo h_emlrtRSI = { 98, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRSInfo i_emlrtRSI = { 44, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo j_emlrtRSI = { 234, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo k_emlrtRSI = { 253, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo m_emlrtRSI = { 18, "indexShapeCheck",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"
};

static emlrtRSInfo n_emlrtRSI = { 16, "max",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/max.m" };

static emlrtRSInfo o_emlrtRSI = { 18, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo p_emlrtRSI = { 97, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo q_emlrtRSI = { 308, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo r_emlrtRSI = { 281, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo s_emlrtRSI = { 16, "min",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/min.m" };

static emlrtRSInfo t_emlrtRSI = { 59, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo u_emlrtRSI = { 182, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo v_emlrtRSI = { 208, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo ab_emlrtRSI = { 160, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo bb_emlrtRSI = { 163, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo cb_emlrtRSI = { 105, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRTEInfo emlrtRTEI = { 3, 7, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 253, 13, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo d_emlrtRTEI = { 19, 24, "scalexpAllocNoCheck",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAllocNoCheck.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 16, 9, "scalexpAlloc",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 15, 1, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 17, 1, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 19, 1, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 25, 5, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 29, 9, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 68, 1, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 36, 6, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtECInfo emlrtECI = { -1, 15, 21, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 25, 24, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 27, 17, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 31, 17, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtECInfo b_emlrtECI = { -1, 31, 9, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 39, 20, "noccidx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 40, 28, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 42, 17, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtECInfo c_emlrtECI = { -1, 42, 9, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtBCInfo g_emlrtBCI = { -1, -1, 50, 26, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 51, 26, "nei_idx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 52, 29, "nei_weight", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtRTEInfo p_emlrtRTEI = { 53, 5, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtBCInfo j_emlrtBCI = { -1, -1, 54, 22, "curr_col", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 55, 22, "cneicon", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 56, 22, "cneiweight", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtDCInfo emlrtDCI = { 58, 38, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  1 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 58, 38, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 58, 46, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtRTEInfo q_emlrtRTEI = { 69, 1, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRTEInfo r_emlrtRTEI = { 72, 9, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtBCInfo o_emlrtBCI = { -1, -1, 73, 30, "nei4u_idx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 73, 33, "nei4u_idx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 74, 33, "nei4u_weight", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 74, 36, "nei4u_weight", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 74, 56, "nei4u_weight", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 76, 36, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  1 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 76, 36, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 76, 42, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 89, 20, "noccidx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 90, 28, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 92, 17, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtECInfo d_emlrtECI = { -1, 92, 9, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m"
};

static emlrtRTEInfo s_emlrtRTEI = { 243, 9, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo t_emlrtRTEI = { 85, 5, "indexShapeCheck",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"
};

static emlrtRTEInfo u_emlrtRTEI = { 38, 19, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 81, 19, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRTEInfo w_emlrtRTEI = { 13, 15, "rdivide",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/ops/rdivide.m" };

static emlrtRTEInfo x_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"
};

static emlrtBCInfo y_emlrtBCI = { -1, -1, 80, 21, "tempcontext", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 80, 24, "tempcontext", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 49, 18, "occidx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 61, 21, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 61, 29, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 24, 15, "newlyoccidx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2016_IROS_OCCFLOWnew/occflow/occflow.m",
  0 };

/* Function Definitions */
void occflow(const emlrtStack *sp, const emxArray_real_T *cgridvec,
             emxArray_real_T *cgridvecprev, emxArray_real_T *context, const
             emxArray_real_T *nei_idx, const emxArray_real_T *nei_weight, real_T
             nei_filter_n, const emxArray_real_T *nei4u_idx, const
             emxArray_real_T *nei4u_weight, real_T nei4u_filter_n, real_T occval,
             real_T minthreshold, real_T maxthreshold, real_T reinitval, real_T
             intensifyrate, real_T nocc_attenuaterate, real_T
             unknown_attenuaterate, real_T sigm_coef, real_T
             do_attenuation_first, emxArray_real_T *predvec, emxArray_real_T
             *maxvec)
{
  emxArray_boolean_T *x;
  int32_T ix;
  int32_T idx;
  emxArray_boolean_T *r0;
  int32_T nx;
  emxArray_int32_T *ii;
  boolean_T overflow;
  int32_T iy;
  boolean_T exitg6;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  emxArray_real_T *newlyoccidx;
  boolean_T exitg5;
  boolean_T guard2 = false;
  boolean_T b_guard3 = false;
  emxArray_real_T *occidx;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T b_guard2 = false;
  emxArray_real_T *noccidx;
  int32_T nrnocc;
  int32_T j;
  emxArray_real_T *curr_col;
  emxArray_real_T *updt_col;
  emxArray_real_T *z;
  int32_T coccidx;
  boolean_T b_guard1 = false;
  int32_T ixstart;
  int32_T n;
  real_T mtmp;
  boolean_T exitg3;
  int32_T varargin_1[2];
  int32_T k;
  int32_T iv3[2];
  int32_T iv4[2];
  real_T d0;
  emxArray_real_T *tempcontext;
  emxArray_real_T *b_nei4u_weight;
  real_T sumval;
  int32_T m;
  int32_T iv5[2];
  boolean_T b_ix;
  boolean_T exitg2;
  boolean_T b_ixstart;
  int32_T varargin_2[2];
  boolean_T p;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  (void)unknown_attenuaterate;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &x, 1, &emlrtRTEI, true);

  /*  */
  /*  Occupancy flow with vector input  */
  /*  */
  /*  Compute indices first  */
  ix = x->size[0];
  x->size[0] = cgridvec->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, ix, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  idx = cgridvec->size[0];
  for (ix = 0; ix < idx; ix++) {
    x->data[ix] = (cgridvec->data[ix] == occval);
  }

  emxInit_boolean_T(sp, &r0, 1, &emlrtRTEI, true);
  ix = r0->size[0];
  r0->size[0] = cgridvecprev->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, ix, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  idx = cgridvecprev->size[0];
  for (ix = 0; ix < idx; ix++) {
    r0->data[ix] = (cgridvecprev->data[ix] != occval);
  }

  ix = x->size[0];
  nx = r0->size[0];
  if (ix != nx) {
    emlrtSizeEqCheck1DR2012b(ix, nx, &emlrtECI, sp);
  }

  st.site = &emlrtRSI;
  ix = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, ix, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  idx = x->size[0];
  for (ix = 0; ix < idx; ix++) {
    x->data[ix] = (x->data[ix] && r0->data[ix]);
  }

  emxFree_boolean_T(&r0);
  emxInit_int32_T(&st, &ii, 1, &l_emlrtRTEI, true);
  b_st.site = &i_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  ix = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  c_st.site = &j_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  iy = 1;
  exitg6 = false;
  while ((!exitg6) && (iy <= nx)) {
    guard3 = false;
    if (x->data[iy - 1]) {
      idx++;
      ii->data[idx - 1] = iy;
      if (idx >= nx) {
        exitg6 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3) {
      iy++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &s_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ix = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      ix = 0;
    } else {
      ix = idx;
    }

    c_st.site = &k_emlrtRSI;
    overflow = !(ii->size[0] != 1);
    guard4 = false;
    if (overflow) {
      overflow = false;
      if (ix != 1) {
        overflow = true;
      }

      if (overflow) {
        overflow = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4) {
      overflow = false;
    }

    d_st.site = &m_emlrtRSI;
    if (!overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &t_emlrtRTEI,
        "Coder:FE:PotentialVectorVector", 0);
    }

    nx = ii->size[0];
    ii->size[0] = ix;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nx, (int32_T)sizeof(int32_T),
                      &c_emlrtRTEI);
  }

  emxInit_real_T(&b_st, &newlyoccidx, 1, &f_emlrtRTEI, true);
  ix = newlyoccidx->size[0];
  newlyoccidx->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)newlyoccidx, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  idx = ii->size[0];
  for (ix = 0; ix < idx; ix++) {
    newlyoccidx->data[ix] = ii->data[ix];
  }

  st.site = &b_emlrtRSI;
  ix = x->size[0];
  x->size[0] = cgridvec->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, ix, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  idx = cgridvec->size[0];
  for (ix = 0; ix < idx; ix++) {
    x->data[ix] = (cgridvec->data[ix] == occval);
  }

  b_st.site = &i_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  ix = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  c_st.site = &j_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  iy = 1;
  exitg5 = false;
  while ((!exitg5) && (iy <= nx)) {
    guard2 = false;
    if (x->data[iy - 1]) {
      idx++;
      ii->data[idx - 1] = iy;
      if (idx >= nx) {
        exitg5 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      iy++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &s_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ix = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      ix = 0;
    } else {
      ix = idx;
    }

    c_st.site = &k_emlrtRSI;
    overflow = !(ii->size[0] != 1);
    b_guard3 = false;
    if (overflow) {
      overflow = false;
      if (ix != 1) {
        overflow = true;
      }

      if (overflow) {
        overflow = true;
      } else {
        b_guard3 = true;
      }
    } else {
      b_guard3 = true;
    }

    if (b_guard3) {
      overflow = false;
    }

    d_st.site = &m_emlrtRSI;
    if (!overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &t_emlrtRTEI,
        "Coder:FE:PotentialVectorVector", 0);
    }

    nx = ii->size[0];
    ii->size[0] = ix;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nx, (int32_T)sizeof(int32_T),
                      &c_emlrtRTEI);
  }

  emxInit_real_T(&b_st, &occidx, 1, &g_emlrtRTEI, true);
  ix = occidx->size[0];
  occidx->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)occidx, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  idx = ii->size[0];
  for (ix = 0; ix < idx; ix++) {
    occidx->data[ix] = ii->data[ix];
  }

  st.site = &c_emlrtRSI;
  ix = x->size[0];
  x->size[0] = cgridvec->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, ix, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  idx = cgridvec->size[0];
  for (ix = 0; ix < idx; ix++) {
    x->data[ix] = (cgridvec->data[ix] != occval);
  }

  b_st.site = &i_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  ix = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  c_st.site = &j_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  iy = 1;
  exitg4 = false;
  while ((!exitg4) && (iy <= nx)) {
    guard1 = false;
    if (x->data[iy - 1]) {
      idx++;
      ii->data[idx - 1] = iy;
      if (idx >= nx) {
        exitg4 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      iy++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &s_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ix = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      ix = 0;
    } else {
      ix = idx;
    }

    c_st.site = &k_emlrtRSI;
    overflow = !(ii->size[0] != 1);
    b_guard2 = false;
    if (overflow) {
      overflow = false;
      if (ix != 1) {
        overflow = true;
      }

      if (overflow) {
        overflow = true;
      } else {
        b_guard2 = true;
      }
    } else {
      b_guard2 = true;
    }

    if (b_guard2) {
      overflow = false;
    }

    d_st.site = &m_emlrtRSI;
    if (!overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &t_emlrtRTEI,
        "Coder:FE:PotentialVectorVector", 0);
    }

    nx = ii->size[0];
    ii->size[0] = ix;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nx, (int32_T)sizeof(int32_T),
                      &c_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  emxInit_real_T(&b_st, &noccidx, 1, &h_emlrtRTEI, true);
  ix = noccidx->size[0];
  noccidx->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)noccidx, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  idx = ii->size[0];
  for (ix = 0; ix < idx; ix++) {
    noccidx->data[ix] = ii->data[ix];
  }

  nrnocc = noccidx->size[0] - 1;

  /*  1 Intensify newly occupied cells  */
  j = 0;
  emxInit_real_T1(sp, &curr_col, 2, &i_emlrtRTEI, true);
  emxInit_real_T1(sp, &updt_col, 2, &j_emlrtRTEI, true);
  emxInit_real_T1(sp, &z, 2, &emlrtRTEI, true);
  while (j <= newlyoccidx->size[0] - 1) {
    /*  For newly occupied cells  */
    ix = newlyoccidx->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= ix))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, ix, &eb_emlrtBCI, sp);
    }

    coccidx = (int32_T)newlyoccidx->data[j] - 1;
    ix = context->size[0];
    nx = (int32_T)newlyoccidx->data[j];
    if (!((nx >= 1) && (nx <= ix))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &emlrtBCI, sp);
    }

    st.site = &d_emlrtRSI;
    b_st.site = &n_emlrtRSI;
    c_st.site = &o_emlrtRSI;
    ix = context->size[1];
    b_guard1 = false;
    if (ix == 1) {
      b_guard1 = true;
    } else {
      ix = context->size[1];
      if (ix != 1) {
        b_guard1 = true;
      } else {
        overflow = false;
      }
    }

    if (b_guard1) {
      overflow = true;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &u_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    ix = context->size[1];
    if (ix > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &v_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &p_emlrtRSI;
    ixstart = 1;
    n = context->size[1];
    nx = (int32_T)newlyoccidx->data[j];
    mtmp = context->data[nx - 1];
    ix = context->size[1];
    if (ix > 1) {
      if (muDoubleScalarIsNaN(mtmp)) {
        e_st.site = &r_emlrtRSI;
        ix = context->size[1];
        if (2 > ix) {
          overflow = false;
        } else {
          ix = context->size[1];
          overflow = (ix > 2147483646);
        }

        if (overflow) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        ix = 2;
        exitg3 = false;
        while ((!exitg3) && (ix <= n)) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(context->data[coccidx + context->size[0] *
               (ix - 1)])) {
            mtmp = context->data[coccidx + context->size[0] * (ix - 1)];
            exitg3 = true;
          } else {
            ix++;
          }
        }
      }

      ix = context->size[1];
      if (ixstart < ix) {
        e_st.site = &q_emlrtRSI;
        ix = context->size[1];
        if (ixstart + 1 > ix) {
          overflow = false;
        } else {
          ix = context->size[1];
          overflow = (ix > 2147483646);
        }

        if (overflow) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (ix = ixstart + 1; ix <= n; ix++) {
          if (context->data[coccidx + context->size[0] * (ix - 1)] > mtmp) {
            mtmp = context->data[coccidx + context->size[0] * (ix - 1)];
          }
        }
      }
    }

    if (mtmp < minthreshold) {
      idx = context->size[1];
      iy = context->size[0];
      nx = (int32_T)newlyoccidx->data[j];
      if (!((nx >= 1) && (nx <= iy))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, iy, &b_emlrtBCI, sp);
      }

      for (ix = 0; ix < idx; ix++) {
        context->data[(nx + context->size[0] * ix) - 1] = reinitval;
      }

      /*  Reinitialize */
    } else {
      idx = context->size[1];
      nx = (int32_T)newlyoccidx->data[j];
      ix = updt_col->size[0] * updt_col->size[1];
      updt_col->size[0] = 1;
      updt_col->size[1] = idx;
      emxEnsureCapacity(sp, (emxArray__common *)updt_col, ix, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (ix = 0; ix < idx; ix++) {
        updt_col->data[updt_col->size[0] * ix] = intensifyrate * context->data
          [(nx + context->size[0] * ix) - 1];
      }

      /*  Intensify */
      st.site = &e_emlrtRSI;
      b_st.site = &s_emlrtRSI;
      c_st.site = &o_emlrtRSI;
      d_st.site = &t_emlrtRSI;
      ix = curr_col->size[0] * curr_col->size[1];
      curr_col->size[0] = 1;
      curr_col->size[1] = updt_col->size[1];
      emxEnsureCapacity(&d_st, (emxArray__common *)curr_col, ix, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      idx = updt_col->size[0] * updt_col->size[1];
      for (ix = 0; ix < idx; ix++) {
        curr_col->data[ix] = updt_col->data[ix];
      }

      e_st.site = &u_emlrtRSI;
      for (ix = 0; ix < 2; ix++) {
        varargin_1[ix] = updt_col->size[ix];
      }

      ix = z->size[0] * z->size[1];
      z->size[0] = 1;
      z->size[1] = updt_col->size[1];
      emxEnsureCapacity(&e_st, (emxArray__common *)z, ix, (int32_T)sizeof(real_T),
                        &d_emlrtRTEI);
      iy = updt_col->size[1];
      ix = updt_col->size[0] * updt_col->size[1];
      updt_col->size[0] = 1;
      updt_col->size[1] = varargin_1[1];
      emxEnsureCapacity(&e_st, (emxArray__common *)updt_col, ix, (int32_T)sizeof
                        (real_T), &e_emlrtRTEI);
      if (dimagree(updt_col, curr_col)) {
      } else {
        emlrtErrorWithMessageIdR2012b(&e_st, &x_emlrtRTEI, "MATLAB:dimagree", 0);
      }

      e_st.site = &v_emlrtRSI;
      if (1 > z->size[1]) {
        overflow = false;
      } else {
        overflow = (z->size[1] > 2147483646);
      }

      if (overflow) {
        f_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (k = 0; k + 1 <= iy; k++) {
        updt_col->data[k] = muDoubleScalarMin(curr_col->data[k], maxthreshold);
      }

      /*  Max-thesholding */
      ix = context->size[0];
      nx = (int32_T)newlyoccidx->data[j];
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &c_emlrtBCI, sp);
      }

      idx = context->size[1];
      ix = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity(sp, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      for (ix = 0; ix < idx; ix++) {
        ii->data[ix] = ix;
      }

      iv3[0] = 1;
      iv3[1] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(iv3, 2, *(int32_T (*)[2])updt_col->size, 2,
        &b_emlrtECI, sp);
      nx = (int32_T)newlyoccidx->data[j];
      idx = updt_col->size[1];
      for (ix = 0; ix < idx; ix++) {
        context->data[(nx + context->size[0] * ii->data[ix]) - 1] =
          updt_col->data[updt_col->size[0] * ix];
      }
    }

    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&z);

  /*  2 Attenuate unoccupied cells */
  if (do_attenuation_first == 1.0) {
    j = 0;
    while (j <= nrnocc) {
      /*  For unoccupied cells */
      ix = noccidx->size[0];
      nx = j + 1;
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &d_emlrtBCI, sp);
      }

      ix = context->size[0];
      nx = (int32_T)noccidx->data[j];
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &e_emlrtBCI, sp);
      }

      idx = context->size[1];
      iy = (int32_T)noccidx->data[j];
      ix = updt_col->size[0] * updt_col->size[1];
      updt_col->size[0] = 1;
      updt_col->size[1] = idx;
      emxEnsureCapacity(sp, (emxArray__common *)updt_col, ix, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (ix = 0; ix < idx; ix++) {
        updt_col->data[updt_col->size[0] * ix] = context->data[(iy +
          context->size[0] * ix) - 1] * nocc_attenuaterate;
      }

      /*  Attenuate */
      ix = context->size[0];
      nx = (int32_T)noccidx->data[j];
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &f_emlrtBCI, sp);
      }

      idx = context->size[1];
      ix = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity(sp, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      for (ix = 0; ix < idx; ix++) {
        ii->data[ix] = ix;
      }

      iv4[0] = 1;
      iv4[1] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(iv4, 2, *(int32_T (*)[2])updt_col->size, 2,
        &c_emlrtECI, sp);
      iy = (int32_T)noccidx->data[j];
      idx = updt_col->size[1];
      for (ix = 0; ix < idx; ix++) {
        context->data[(iy + context->size[0] * ii->data[ix]) - 1] =
          updt_col->data[updt_col->size[0] * ix];
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  /*  4 Propagation  */
  j = 0;
  while (j <= occidx->size[0] - 1) {
    /*  For occupied cells  */
    ix = occidx->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= ix))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, ix, &bb_emlrtBCI, sp);
    }

    idx = context->size[1];
    ix = context->size[0];
    iy = (int32_T)occidx->data[j];
    if (!((iy >= 1) && (iy <= ix))) {
      emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &g_emlrtBCI, sp);
    }

    ix = curr_col->size[0] * curr_col->size[1];
    curr_col->size[0] = 1;
    curr_col->size[1] = idx;
    emxEnsureCapacity(sp, (emxArray__common *)curr_col, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ix = 0; ix < idx; ix++) {
      curr_col->data[curr_col->size[0] * ix] = context->data[(iy + context->
        size[0] * ix) - 1];
    }

    ix = nei_idx->size[0];
    nx = (int32_T)occidx->data[j];
    if (!((nx >= 1) && (nx <= ix))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &h_emlrtBCI, sp);
    }

    ix = nei_weight->size[0];
    nx = (int32_T)occidx->data[j];
    if (!((nx >= 1) && (nx <= ix))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &i_emlrtBCI, sp);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nei_filter_n, mxDOUBLE_CLASS,
      (int32_T)nei_filter_n, &p_emlrtRTEI, sp);
    k = 0;
    while (k <= (int32_T)nei_filter_n - 1) {
      /*  For all neighbor cells  */
      ix = curr_col->size[1];
      nx = k + 1;
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &j_emlrtBCI, sp);
      }

      ix = nei_idx->size[1];
      nx = k + 1;
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &k_emlrtBCI, sp);
      }

      ix = nei_weight->size[1];
      nx = k + 1;
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &l_emlrtBCI, sp);
      }

      iy = (int32_T)occidx->data[j];
      if (nei_idx->data[(iy + nei_idx->size[0] * k) - 1] != 0.0) {
        /*  If properly connected, propagate */
        iy = (int32_T)occidx->data[j];
        d0 = nei_idx->data[(iy + nei_idx->size[0] * k) - 1];
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &emlrtDCI, sp);
        }

        ix = context->size[0];
        nx = (int32_T)d0;
        if (!((nx >= 1) && (nx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &m_emlrtBCI, sp);
        }

        ix = context->size[1];
        nx = k + 1;
        if (!((nx >= 1) && (nx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &n_emlrtBCI, sp);
        }

        /*  Maximum value thresholding  */
        iy = (int32_T)occidx->data[j];
        idx = (int32_T)occidx->data[j];
        nx = (int32_T)occidx->data[j];
        ix = context->size[0];
        nx = (int32_T)nei_idx->data[(nx + nei_idx->size[0] * k) - 1];
        if (!((nx >= 1) && (nx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &cb_emlrtBCI, sp);
        }

        ix = context->size[1];
        if (!((k + 1 >= 1) && (k + 1 <= ix))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, ix, &db_emlrtBCI, sp);
        }

        context->data[(nx + context->size[0] * k) - 1] = muDoubleScalarMax
          (context->data[((int32_T)nei_idx->data[(iy + nei_idx->size[0] * k) - 1]
                          + context->size[0] * k) - 1], muDoubleScalarMin
           (nei_weight->data[(idx + nei_weight->size[0] * k) - 1] *
            curr_col->data[k], maxthreshold));

        /*  Make sure current context propagation does not weaken the flow information */
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&occidx);
  emxInit_real_T1(sp, &tempcontext, 2, &k_emlrtRTEI, true);

  /*  5 Uncertainty in acceleration */
  ix = tempcontext->size[0] * tempcontext->size[1];
  tempcontext->size[0] = context->size[0];
  tempcontext->size[1] = context->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)tempcontext, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  idx = context->size[0] * context->size[1];
  for (ix = 0; ix < idx; ix++) {
    tempcontext->data[ix] = context->data[ix];
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nei_filter_n, mxDOUBLE_CLASS, (int32_T)
    nei_filter_n, &q_emlrtRTEI, sp);
  j = 0;
  emxInit_real_T1(sp, &b_nei4u_weight, 2, &emlrtRTEI, true);
  while (j <= (int32_T)nei_filter_n - 1) {
    /*  For all context level */
    k = 0;
    while (k <= nei_idx->size[0] - 1) {
      /*  For all cells */
      sumval = 0.0;
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, nei4u_filter_n, mxDOUBLE_CLASS,
        (int32_T)nei4u_filter_n, &r_emlrtRTEI, sp);
      m = 0;
      while (m <= (int32_T)nei4u_filter_n - 1) {
        ix = nei4u_idx->size[0];
        nx = k + 1;
        if (!((nx >= 1) && (nx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &o_emlrtBCI, sp);
        }

        ix = nei4u_idx->size[1];
        nx = m + 1;
        if (!((nx >= 1) && (nx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &p_emlrtBCI, sp);
        }

        ix = nei4u_weight->size[0];
        nx = k + 1;
        if (!((nx >= 1) && (nx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &q_emlrtBCI, sp);
        }

        ix = nei4u_weight->size[1];
        nx = m + 1;
        if (!((nx >= 1) && (nx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &r_emlrtBCI, sp);
        }

        idx = nei4u_weight->size[1];
        ix = nei4u_weight->size[0];
        nx = 1 + k;
        if (!((nx >= 1) && (nx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &s_emlrtBCI, sp);
        }

        ix = b_nei4u_weight->size[0] * b_nei4u_weight->size[1];
        b_nei4u_weight->size[0] = 1;
        b_nei4u_weight->size[1] = idx;
        emxEnsureCapacity(sp, (emxArray__common *)b_nei4u_weight, ix, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        for (ix = 0; ix < idx; ix++) {
          b_nei4u_weight->data[b_nei4u_weight->size[0] * ix] =
            nei4u_weight->data[(nx + nei4u_weight->size[0] * ix) - 1];
        }

        st.site = &f_emlrtRSI;
        mtmp = sum(&st, b_nei4u_weight);
        if (nei4u_idx->data[k + nei4u_idx->size[0] * m] != 0.0) {
          d0 = nei4u_idx->data[k + nei4u_idx->size[0] * m];
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &b_emlrtDCI, sp);
          }

          ix = context->size[0];
          nx = (int32_T)d0;
          if (!((nx >= 1) && (nx <= ix))) {
            emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &t_emlrtBCI, sp);
          }

          ix = context->size[1];
          nx = j + 1;
          if (!((nx >= 1) && (nx <= ix))) {
            emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &u_emlrtBCI, sp);
          }

          sumval += nei4u_weight->data[k + nei4u_weight->size[0] * m] / mtmp *
            context->data[((int32_T)nei4u_idx->data[k + nei4u_idx->size[0] * m]
                           + context->size[0] * j) - 1];
        }

        m++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      ix = tempcontext->size[0];
      nx = 1 + k;
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &y_emlrtBCI, sp);
      }

      ix = tempcontext->size[1];
      if (!((j + 1 >= 1) && (j + 1 <= ix))) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, ix, &ab_emlrtBCI, sp);
      }

      tempcontext->data[(nx + tempcontext->size[0] * j) - 1] = sumval;
      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_nei4u_weight);
  ix = context->size[0] * context->size[1];
  context->size[0] = tempcontext->size[0];
  context->size[1] = tempcontext->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)context, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  idx = tempcontext->size[1];
  for (ix = 0; ix < idx; ix++) {
    iy = tempcontext->size[0];
    for (nx = 0; nx < iy; nx++) {
      context->data[nx + context->size[0] * ix] = tempcontext->data[nx +
        tempcontext->size[0] * ix];
    }
  }

  if (do_attenuation_first == 0.0) {
    /*  2 Attenuate unoccupied cells */
    j = 0;
    while (j <= nrnocc) {
      /*  For unoccupied cells, attenuate */
      ix = noccidx->size[0];
      nx = j + 1;
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &v_emlrtBCI, sp);
      }

      ix = context->size[0];
      nx = (int32_T)noccidx->data[j];
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &w_emlrtBCI, sp);
      }

      idx = context->size[1];
      iy = (int32_T)noccidx->data[j];
      ix = updt_col->size[0] * updt_col->size[1];
      updt_col->size[0] = 1;
      updt_col->size[1] = idx;
      emxEnsureCapacity(sp, (emxArray__common *)updt_col, ix, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (ix = 0; ix < idx; ix++) {
        updt_col->data[updt_col->size[0] * ix] = context->data[(iy +
          context->size[0] * ix) - 1] * nocc_attenuaterate;
      }

      ix = context->size[0];
      nx = (int32_T)noccidx->data[j];
      if (!((nx >= 1) && (nx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, ix, &x_emlrtBCI, sp);
      }

      idx = context->size[1];
      ix = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity(sp, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      for (ix = 0; ix < idx; ix++) {
        ii->data[ix] = ix;
      }

      iv5[0] = 1;
      iv5[1] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(iv5, 2, *(int32_T (*)[2])updt_col->size, 2,
        &d_emlrtECI, sp);
      iy = (int32_T)noccidx->data[j];
      idx = updt_col->size[1];
      for (ix = 0; ix < idx; ix++) {
        context->data[(iy + context->size[0] * ii->data[ix]) - 1] =
          updt_col->data[updt_col->size[0] * ix];
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  emxFree_int32_T(&ii);
  emxFree_real_T(&updt_col);
  emxFree_real_T(&noccidx);

  /*  6 Prediction */
  st.site = &g_emlrtRSI;
  ix = tempcontext->size[0] * tempcontext->size[1];
  tempcontext->size[0] = context->size[1];
  tempcontext->size[1] = context->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)tempcontext, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  idx = context->size[0];
  for (ix = 0; ix < idx; ix++) {
    iy = context->size[1];
    for (nx = 0; nx < iy; nx++) {
      tempcontext->data[nx + tempcontext->size[0] * ix] = context->data[ix +
        context->size[0] * nx];
    }
  }

  b_st.site = &n_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  if (((tempcontext->size[0] == 1) && (tempcontext->size[1] == 1)) ||
      (tempcontext->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &u_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (tempcontext->size[0] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &v_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  ix = curr_col->size[0] * curr_col->size[1];
  curr_col->size[0] = 1;
  curr_col->size[1] = tempcontext->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)curr_col, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  n = tempcontext->size[0];
  ix = 0;
  iy = -1;
  d_st.site = &ab_emlrtRSI;
  if (1 > tempcontext->size[1]) {
    overflow = false;
  } else {
    overflow = (tempcontext->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (nx = 1; nx <= tempcontext->size[1]; nx++) {
    d_st.site = &bb_emlrtRSI;
    ixstart = ix;
    idx = ix + n;
    mtmp = tempcontext->data[ix];
    if (n > 1) {
      if (muDoubleScalarIsNaN(tempcontext->data[ix])) {
        e_st.site = &r_emlrtRSI;
        if (ix + 2 > idx) {
          b_ix = false;
        } else {
          b_ix = (idx > 2147483646);
        }

        if (b_ix) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        k = ix + 1;
        exitg2 = false;
        while ((!exitg2) && (k + 1 <= idx)) {
          ixstart = k;
          if (!muDoubleScalarIsNaN(tempcontext->data[k])) {
            mtmp = tempcontext->data[k];
            exitg2 = true;
          } else {
            k++;
          }
        }
      }

      if (ixstart + 1 < idx) {
        e_st.site = &q_emlrtRSI;
        if (ixstart + 2 > idx) {
          b_ixstart = false;
        } else {
          b_ixstart = (idx > 2147483646);
        }

        if (b_ixstart) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (k = ixstart + 1; k + 1 <= idx; k++) {
          if (tempcontext->data[k] > mtmp) {
            mtmp = tempcontext->data[k];
          }
        }
      }
    }

    iy++;
    curr_col->data[iy] = mtmp;
    ix += n;
  }

  emxFree_real_T(&tempcontext);
  ix = maxvec->size[0];
  maxvec->size[0] = curr_col->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)maxvec, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  idx = curr_col->size[1];
  for (ix = 0; ix < idx; ix++) {
    maxvec->data[ix] = curr_col->data[curr_col->size[0] * ix];
  }

  emxFree_real_T(&curr_col);
  st.site = &h_emlrtRSI;

  /*  sigm_a  <= if we increase the value, than the sigm function gets peaky! */
  b_st.site = &cb_emlrtRSI;
  ix = predvec->size[0];
  predvec->size[0] = maxvec->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)predvec, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  idx = maxvec->size[0];
  for (ix = 0; ix < idx; ix++) {
    predvec->data[ix] = -sigm_coef * maxvec->data[ix];
  }

  c_st.site = &cb_emlrtRSI;
  b_exp(&c_st, predvec);
  ix = predvec->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)predvec, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  idx = predvec->size[0];
  for (ix = 0; ix < idx; ix++) {
    predvec->data[ix] = 1.0 - predvec->data[ix];
  }

  ix = newlyoccidx->size[0];
  newlyoccidx->size[0] = maxvec->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)newlyoccidx, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  idx = maxvec->size[0];
  for (ix = 0; ix < idx; ix++) {
    newlyoccidx->data[ix] = -sigm_coef * maxvec->data[ix];
  }

  c_st.site = &cb_emlrtRSI;
  b_exp(&c_st, newlyoccidx);
  ix = newlyoccidx->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)newlyoccidx, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  idx = newlyoccidx->size[0];
  for (ix = 0; ix < idx; ix++) {
    newlyoccidx->data[ix]++;
  }

  varargin_1[0] = predvec->size[0];
  varargin_1[1] = 1;
  varargin_2[0] = newlyoccidx->size[0];
  varargin_2[1] = 1;
  overflow = false;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!p) {
  } else {
    overflow = true;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &w_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  ix = predvec->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)predvec, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  idx = predvec->size[0];
  for (ix = 0; ix < idx; ix++) {
    predvec->data[ix] /= newlyoccidx->data[ix];
  }

  emxFree_real_T(&newlyoccidx);

  /*  7 Save previous grid */
  ix = cgridvecprev->size[0];
  cgridvecprev->size[0] = cgridvec->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)cgridvecprev, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  idx = cgridvec->size[0];
  for (ix = 0; ix < idx; ix++) {
    cgridvecprev->data[ix] = cgridvec->data[ix];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (occflow.c) */
