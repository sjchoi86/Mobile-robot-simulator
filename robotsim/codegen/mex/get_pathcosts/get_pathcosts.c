/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_pathcosts.c
 *
 * Code generation for function 'get_pathcosts'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_pathcosts.h"
#include "get_pathcosts_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "norm.h"
#include "interp2.h"
#include "get_pathcosts_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 8, "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m"
};

static emlrtRSInfo b_emlrtRSI = { 9, "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m"
};

static emlrtRSInfo c_emlrtRSI = { 15, "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m"
};

static emlrtRSInfo d_emlrtRSI = { 16, "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m"
};

static emlrtRSInfo p_emlrtRSI = { 16, "max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"
};

static emlrtRSInfo q_emlrtRSI = { 18, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo r_emlrtRSI = { 96, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo s_emlrtRSI = { 229, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo t_emlrtRSI = { 202, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 32, "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 7, 5, "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 8, 5, "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 7, 25, "xpaths", "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 7, 46, "ypaths", "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m",
  0 };

static emlrtECInfo emlrtECI = { 1, 7, 17, "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m"
};

static emlrtBCInfo c_emlrtBCI = { -1, -1, 10, 27, "curr_path", "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m",
  0 };

static emlrtRTEInfo f_emlrtRTEI = { 38, 19, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 81, 19, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 12, 5, "obscost", "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 13, 5, "goaldist", "get_pathcosts",
  "E:\\Dropbox\\Research\\Implementation in papers\\2016_IROS_OCCFLOWnew\\robotsim\\get_pathcosts.m",
  0 };

/* Function Definitions */
void get_pathcosts(const emlrtStack *sp, const emxArray_real_T *xpaths, const
                   emxArray_real_T *ypaths, const emxArray_real_T *xmesh, const
                   emxArray_real_T *ymesh, const emxArray_real_T *grid4obscost,
                   const real_T robot_pos[3], const real_T goal[2],
                   emxArray_real_T *obscost, emxArray_real_T *goaldist)
{
  int32_T ix;
  int32_T n;
  int32_T path_idx;
  emxArray_real_T *curr_path;
  emxArray_real_T *predvals;
  emxArray_real_T *r0;
  emxArray_real_T *r1;
  emxArray_real_T *b_curr_path;
  emxArray_real_T *c_curr_path;
  emxArray_real_T *b_xpaths;
  emxArray_real_T *b_ypaths;
  int32_T ixstart;
  boolean_T overflow;
  real_T mtmp;
  boolean_T exitg3;
  int32_T b_n;
  real_T d_curr_path[2];
  real_T curr_rel_r;
  real_T curr_rel_deg;
  real_T b_robot_pos[2];
  real_T b_goal[2];
  int32_T c_n;
  boolean_T exitg2;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  ix = obscost->size[0];
  obscost->size[0] = xpaths->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)obscost, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  n = xpaths->size[0];
  for (ix = 0; ix < n; ix++) {
    obscost->data[ix] = 0.0;
  }

  ix = goaldist->size[0];
  goaldist->size[0] = xpaths->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)goaldist, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  n = xpaths->size[0];
  for (ix = 0; ix < n; ix++) {
    goaldist->data[ix] = 0.0;
  }

  path_idx = 0;
  emxInit_real_T(sp, &curr_path, 2, &b_emlrtRTEI, true);
  b_emxInit_real_T(sp, &predvals, 1, &c_emlrtRTEI, true);
  emxInit_real_T(sp, &r0, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &r1, 2, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &b_curr_path, 1, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &c_curr_path, 1, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &b_xpaths, 1, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &b_ypaths, 1, &emlrtRTEI, true);
  while (path_idx <= xpaths->size[0] - 1) {
    ix = xpaths->size[0];
    n = path_idx + 1;
    emlrtDynamicBoundsCheckR2012b(n, 1, ix, &emlrtBCI, sp);
    ix = ypaths->size[0];
    n = path_idx + 1;
    emlrtDynamicBoundsCheckR2012b(n, 1, ix, &b_emlrtBCI, sp);
    n = xpaths->size[1];
    ixstart = xpaths->size[1];
    ix = b_xpaths->size[0];
    b_xpaths->size[0] = ixstart;
    emxEnsureCapacity(sp, (emxArray__common *)b_xpaths, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ix = 0; ix < ixstart; ix++) {
      b_xpaths->data[ix] = xpaths->data[path_idx + xpaths->size[0] * ix];
    }

    ix = r0->size[0] * r0->size[1];
    r0->size[0] = n;
    r0->size[1] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r0, ix, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (ix = 0; ix < n; ix++) {
      r0->data[ix] = b_xpaths->data[ix];
    }

    n = ypaths->size[1];
    ixstart = ypaths->size[1];
    ix = b_ypaths->size[0];
    b_ypaths->size[0] = ixstart;
    emxEnsureCapacity(sp, (emxArray__common *)b_ypaths, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ix = 0; ix < ixstart; ix++) {
      b_ypaths->data[ix] = ypaths->data[path_idx + ypaths->size[0] * ix];
    }

    ix = r1->size[0] * r1->size[1];
    r1->size[0] = n;
    r1->size[1] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)r1, ix, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (ix = 0; ix < n; ix++) {
      r1->data[ix] = b_ypaths->data[ix];
    }

    ix = r0->size[0];
    n = r1->size[0];
    if (ix != n) {
      emlrtDimSizeEqCheckR2012b(ix, n, &emlrtECI, sp);
    }

    ix = curr_path->size[0] * curr_path->size[1];
    curr_path->size[0] = r0->size[0];
    curr_path->size[1] = 2;
    emxEnsureCapacity(sp, (emxArray__common *)curr_path, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    n = r0->size[0];
    for (ix = 0; ix < n; ix++) {
      curr_path->data[ix] = r0->data[ix];
    }

    n = r1->size[0];
    for (ix = 0; ix < n; ix++) {
      curr_path->data[ix + curr_path->size[0]] = r1->data[ix];
    }

    n = curr_path->size[0];
    ix = b_curr_path->size[0];
    b_curr_path->size[0] = n;
    emxEnsureCapacity(sp, (emxArray__common *)b_curr_path, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ix = 0; ix < n; ix++) {
      b_curr_path->data[ix] = curr_path->data[ix];
    }

    n = curr_path->size[0];
    ix = c_curr_path->size[0];
    c_curr_path->size[0] = n;
    emxEnsureCapacity(sp, (emxArray__common *)c_curr_path, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ix = 0; ix < n; ix++) {
      c_curr_path->data[ix] = curr_path->data[ix + curr_path->size[0]];
    }

    st.site = &emlrtRSI;
    interp2(&st, xmesh, ymesh, grid4obscost, b_curr_path, c_curr_path, predvals);
    st.site = &b_emlrtRSI;
    b_st.site = &p_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    if ((predvals->size[0] == 1) || (predvals->size[0] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &f_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (predvals->size[0] > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &g_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &r_emlrtRSI;
    ixstart = 1;
    n = predvals->size[0];
    mtmp = predvals->data[0];
    if (predvals->size[0] > 1) {
      if (muDoubleScalarIsNaN(predvals->data[0])) {
        e_st.site = &t_emlrtRSI;
        overflow = (predvals->size[0] > 2147483646);
        if (overflow) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        ix = 2;
        exitg3 = false;
        while ((!exitg3) && (ix <= n)) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(predvals->data[ix - 1])) {
            mtmp = predvals->data[ix - 1];
            exitg3 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart < predvals->size[0]) {
        e_st.site = &s_emlrtRSI;
        if (ixstart + 1 > predvals->size[0]) {
          overflow = false;
        } else {
          overflow = (predvals->size[0] > 2147483646);
        }

        if (overflow) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (ixstart + 1 <= n) {
          if (predvals->data[ixstart] > mtmp) {
            mtmp = predvals->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    ix = curr_path->size[0];
    n = curr_path->size[0];
    emlrtDynamicBoundsCheckR2012b(n, 1, ix, &c_emlrtBCI, sp);
    ix = obscost->size[0];
    n = 1 + path_idx;
    if ((n >= 1) && (n < ix)) {
      b_n = n;
    } else {
      b_n = emlrtDynamicBoundsCheckR2012b(n, 1, ix, &d_emlrtBCI, sp);
    }

    obscost->data[b_n - 1] = mtmp;

    /*  lower the better */
    /*  */
    /*  Get Reference Cartesian Position from Relative Cartiesian Position   */
    /*  */
    n = curr_path->size[0];
    ixstart = curr_path->size[0];
    d_curr_path[0] = curr_path->data[n - 1];
    d_curr_path[1] = curr_path->data[(ixstart + curr_path->size[0]) - 1];
    curr_rel_r = norm(d_curr_path);
    n = curr_path->size[0];
    ixstart = curr_path->size[0];
    curr_rel_deg = muDoubleScalarAtan2(curr_path->data[(n + curr_path->size[0])
      - 1], curr_path->data[ixstart - 1]) * 180.0 / 3.1415926535897931;

    /*  cartesian pos */
    /*  ref cart pos */
    b_robot_pos[0] = robot_pos[0] + curr_rel_r * muDoubleScalarCos
      (0.017453292519943295 * (robot_pos[2] + curr_rel_deg));
    b_robot_pos[1] = robot_pos[1] + curr_rel_r * muDoubleScalarSin
      (0.017453292519943295 * (robot_pos[2] + curr_rel_deg));
    for (ix = 0; ix < 2; ix++) {
      b_goal[ix] = goal[ix] - b_robot_pos[ix];
    }

    ix = goaldist->size[0];
    n = 1 + path_idx;
    if ((n >= 1) && (n < ix)) {
      c_n = n;
    } else {
      c_n = emlrtDynamicBoundsCheckR2012b(n, 1, ix, &e_emlrtBCI, sp);
    }

    goaldist->data[c_n - 1] = norm(b_goal);

    /*  lower the better */
    path_idx++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_ypaths);
  emxFree_real_T(&b_xpaths);
  emxFree_real_T(&c_curr_path);
  emxFree_real_T(&b_curr_path);
  emxFree_real_T(&r1);
  emxFree_real_T(&r0);
  emxFree_real_T(&predvals);
  emxFree_real_T(&curr_path);
  st.site = &c_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  if ((obscost->size[0] == 1) || (obscost->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &f_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (obscost->size[0] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &g_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &r_emlrtRSI;
  ixstart = 1;
  n = obscost->size[0];
  mtmp = obscost->data[0];
  if (obscost->size[0] > 1) {
    if (muDoubleScalarIsNaN(obscost->data[0])) {
      e_st.site = &t_emlrtRSI;
      overflow = (obscost->size[0] > 2147483646);
      if (overflow) {
        f_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(obscost->data[ix - 1])) {
          mtmp = obscost->data[ix - 1];
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < obscost->size[0]) {
      e_st.site = &s_emlrtRSI;
      if (ixstart + 1 > obscost->size[0]) {
        overflow = false;
      } else {
        overflow = (obscost->size[0] > 2147483646);
      }

      if (overflow) {
        f_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (ixstart + 1 <= n) {
        if (obscost->data[ixstart] > mtmp) {
          mtmp = obscost->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  ix = obscost->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)obscost, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  n = obscost->size[0];
  for (ix = 0; ix < n; ix++) {
    obscost->data[ix] /= mtmp + 1.0E-6;
  }

  st.site = &d_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  if ((goaldist->size[0] == 1) || (goaldist->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &f_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (goaldist->size[0] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &g_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &r_emlrtRSI;
  ixstart = 1;
  n = goaldist->size[0];
  mtmp = goaldist->data[0];
  if (goaldist->size[0] > 1) {
    if (muDoubleScalarIsNaN(goaldist->data[0])) {
      e_st.site = &t_emlrtRSI;
      overflow = (goaldist->size[0] > 2147483646);
      if (overflow) {
        f_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(goaldist->data[ix - 1])) {
          mtmp = goaldist->data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < goaldist->size[0]) {
      e_st.site = &s_emlrtRSI;
      if (ixstart + 1 > goaldist->size[0]) {
        overflow = false;
      } else {
        overflow = (goaldist->size[0] > 2147483646);
      }

      if (overflow) {
        f_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (ixstart + 1 <= n) {
        if (goaldist->data[ixstart] > mtmp) {
          mtmp = goaldist->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  ix = goaldist->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)goaldist, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  n = goaldist->size[0];
  for (ix = 0; ix < n; ix++) {
    goaldist->data[ix] /= mtmp;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (get_pathcosts.c) */
