/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp2.c
 *
 * Code generation for function 'interp2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_pathcosts.h"
#include "interp2.h"
#include "get_pathcosts_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "bsearch.h"
#include "isincreasing.h"
#include "get_pathcosts_data.h"

/* Variable Definitions */
static emlrtRSInfo e_emlrtRSI = { 68, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRSInfo f_emlrtRSI = { 70, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRSInfo g_emlrtRSI = { 69, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRSInfo h_emlrtRSI = { 164, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRSInfo i_emlrtRSI = { 44, "isplaid",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\isplaid.m"
};

static emlrtRSInfo j_emlrtRSI = { 49, "isplaid",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\isplaid.m"
};

static emlrtRSInfo k_emlrtRSI = { 47, "isplaid",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\isplaid.m"
};

static emlrtRSInfo m_emlrtRSI = { 18, "unmeshgrid",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\unmeshgrid.m"
};

static emlrtRSInfo n_emlrtRSI = { 251, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRSInfo o_emlrtRSI = { 283, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 1, 15, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 24, 23, "unmeshgrid",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\unmeshgrid.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 169, 27, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 164, 31, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 150, 23, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 142, 23, "interp2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

/* Function Definitions */
void interp2(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
             emxArray_real_T *varargin_2, const emxArray_real_T *varargin_3,
             const emxArray_real_T *varargin_4, const emxArray_real_T
             *varargin_5, emxArray_real_T *Vq)
{
  boolean_T overflow;
  uint32_T b_varargin_1[2];
  uint32_T sz[2];
  boolean_T p;
  int32_T i;
  boolean_T exitg7;
  int32_T element_offset;
  int32_T nx;
  boolean_T b_p;
  boolean_T exitg6;
  boolean_T guard1 = false;
  boolean_T b_guard1 = false;
  int32_T exitg4;
  int32_T iy;
  int32_T exitg3;
  boolean_T exitg5;
  int32_T exitg2;
  int32_T exitg1;
  emxArray_real_T *X;
  emxArray_real_T *Y;
  real_T qx1;
  real_T rx;
  real_T ry;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &e_emlrtRSI;
  if ((varargin_3->size[1] >= 2) && (varargin_3->size[0] >= 2)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &l_emlrtRTEI,
      "Coder:toolbox:NotEnoughPoints", 0);
  }

  b_varargin_1[0] = (uint32_T)varargin_4->size[0];
  b_varargin_1[1] = 1U;
  sz[0] = (uint32_T)varargin_5->size[0];
  sz[1] = 1U;
  p = false;
  overflow = true;
  i = 0;
  exitg7 = false;
  while ((!exitg7) && (i < 2)) {
    if (!((int32_T)b_varargin_1[i] == (int32_T)sz[i])) {
      overflow = false;
      exitg7 = true;
    } else {
      i++;
    }
  }

  if (!overflow) {
  } else {
    p = true;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &k_emlrtRTEI,
      "Coder:toolbox:interp2_sizeXIandYIMustMatch", 0);
  }

  b_st.site = &h_emlrtRSI;
  p = false;
  for (element_offset = 0; element_offset < 2; element_offset++) {
    sz[element_offset] = (uint32_T)varargin_1->size[element_offset];
  }

  nx = varargin_1->size[0] * varargin_1->size[1];
  for (element_offset = 0; element_offset < 2; element_offset++) {
    b_varargin_1[element_offset] = (uint32_T)varargin_1->size[element_offset];
  }

  overflow = false;
  b_p = true;
  i = 0;
  exitg6 = false;
  while ((!exitg6) && (i < 2)) {
    if (!((int32_T)b_varargin_1[i] == (int32_T)sz[i])) {
      b_p = false;
      exitg6 = true;
    } else {
      i++;
    }
  }

  if (!b_p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    guard1 = false;
    b_guard1 = false;
    if (nx > 1) {
      c_st.site = &i_emlrtRSI;
      if (1 > varargin_1->size[1]) {
        overflow = false;
      } else {
        overflow = (varargin_1->size[1] > 2147483646);
      }

      if (overflow) {
        d_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      i = 1;
      do {
        exitg4 = 0;
        if (i <= varargin_1->size[1]) {
          element_offset = (i - 1) * varargin_1->size[0];
          c_st.site = &j_emlrtRSI;
          if (1 > varargin_1->size[0]) {
            overflow = false;
          } else {
            overflow = (varargin_1->size[0] > 2147483646);
          }

          if (overflow) {
            d_st.site = &l_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          iy = 1;
          do {
            exitg3 = 0;
            if (iy <= varargin_1->size[0]) {
              if (!(varargin_1->data[element_offset] == varargin_1->data
                    [(element_offset + iy) - 1])) {
                exitg3 = 1;
              } else {
                iy++;
              }
            } else {
              i++;
              exitg3 = 2;
            }
          } while (exitg3 == 0);

          if (exitg3 == 1) {
            exitg4 = 1;
          }
        } else {
          exitg4 = 2;
        }
      } while (exitg4 == 0);

      if (exitg4 == 1) {
      } else {
        b_guard1 = true;
      }
    } else {
      b_guard1 = true;
    }

    if (b_guard1) {
      for (element_offset = 0; element_offset < 2; element_offset++) {
        b_varargin_1[element_offset] = (uint32_T)varargin_2->size[element_offset];
      }

      overflow = false;
      b_p = true;
      i = 0;
      exitg5 = false;
      while ((!exitg5) && (i < 2)) {
        if (!((int32_T)b_varargin_1[i] == (int32_T)sz[i])) {
          b_p = false;
          exitg5 = true;
        } else {
          i++;
        }
      }

      if (!b_p) {
      } else {
        overflow = true;
      }

      if (!overflow) {
      } else if (nx > 1) {
        c_st.site = &i_emlrtRSI;
        if (1 > varargin_1->size[0]) {
          overflow = false;
        } else {
          overflow = (varargin_1->size[0] > 2147483646);
        }

        if (overflow) {
          d_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        i = 0;
        do {
          exitg2 = 0;
          if (i + 1 <= varargin_1->size[0]) {
            c_st.site = &k_emlrtRSI;
            if (1 > varargin_1->size[1]) {
              overflow = false;
            } else {
              overflow = (varargin_1->size[1] > 2147483646);
            }

            if (overflow) {
              d_st.site = &l_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }

            element_offset = 1;
            do {
              exitg1 = 0;
              if (element_offset <= varargin_1->size[1]) {
                if (!(varargin_2->data[i] == varargin_2->data[i +
                      (element_offset - 1) * varargin_1->size[0]])) {
                  exitg1 = 1;
                } else {
                  element_offset++;
                }
              } else {
                i++;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = 1;
            }
          } else {
            guard1 = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      } else {
        guard1 = true;
      }
    }

    if (guard1) {
      p = true;
    }
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &j_emlrtRTEI,
      "Coder:toolbox:GridMustBeVectorsOrPlaid", 0);
  }

  if ((varargin_3->size[0] == varargin_2->size[0]) && (varargin_3->size[1] ==
       varargin_1->size[1])) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &i_emlrtRTEI,
      "MATLAB:xyzchk:lengthXAndYDoNotMatchSizeZ", 0);
  }

  emxInit_real_T(&st, &X, 2, &d_emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  element_offset = X->size[0] * X->size[1];
  X->size[0] = 1;
  X->size[1] = varargin_1->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)X, element_offset, (int32_T)sizeof
                    (real_T), &d_emlrtRTEI);
  b_st.site = &m_emlrtRSI;
  if (1 > varargin_1->size[1]) {
    overflow = false;
  } else {
    overflow = (varargin_1->size[1] > 2147483646);
  }

  if (overflow) {
    c_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (i = 0; i + 1 <= varargin_1->size[1]; i++) {
    X->data[i] = varargin_1->data[varargin_1->size[0] * i];
  }

  if (isincreasing(X)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &h_emlrtRTEI,
      "Coder:toolbox:NonIncreasing", 0);
  }

  emxInit_real_T(&st, &Y, 2, &d_emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  element_offset = Y->size[0] * Y->size[1];
  Y->size[0] = 1;
  Y->size[1] = varargin_2->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)Y, element_offset, (int32_T)sizeof
                    (real_T), &d_emlrtRTEI);
  b_st.site = &m_emlrtRSI;
  if (1 > varargin_2->size[0]) {
    overflow = false;
  } else {
    overflow = (varargin_2->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (i = 0; i + 1 <= varargin_2->size[0]; i++) {
    Y->data[i] = varargin_2->data[i];
  }

  if (isincreasing(Y)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &h_emlrtRTEI,
      "Coder:toolbox:NonIncreasing", 0);
  }

  st.site = &g_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  sz[0] = (uint32_T)varargin_4->size[0];
  element_offset = Vq->size[0];
  Vq->size[0] = (int32_T)sz[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)Vq, element_offset, (int32_T)
                    sizeof(real_T), &d_emlrtRTEI);
  c_st.site = &o_emlrtRSI;
  if (1 > (int32_T)sz[0]) {
    overflow = false;
  } else {
    overflow = ((int32_T)sz[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (i = 0; i + 1 <= (int32_T)sz[0]; i++) {
    if ((varargin_4->data[i] >= X->data[0]) && (varargin_4->data[i] <= X->data
         [X->size[1] - 1]) && (varargin_5->data[i] >= Y->data[0]) &&
        (varargin_5->data[i] <= Y->data[Y->size[1] - 1])) {
      element_offset = b_bsearch(X, varargin_4->data[i]) - 1;
      iy = b_bsearch(Y, varargin_5->data[i]);
      if (varargin_4->data[i] == X->data[element_offset]) {
        qx1 = varargin_3->data[(iy + varargin_3->size[0] * element_offset) - 1];
        rx = varargin_3->data[iy + varargin_3->size[0] * element_offset];
      } else if (varargin_4->data[i] == X->data[element_offset + 1]) {
        qx1 = varargin_3->data[(iy + varargin_3->size[0] * (element_offset + 1))
          - 1];
        rx = varargin_3->data[iy + varargin_3->size[0] * (element_offset + 1)];
      } else {
        rx = (varargin_4->data[i] - X->data[element_offset]) / (X->
          data[element_offset + 1] - X->data[element_offset]);
        if (varargin_3->data[(iy + varargin_3->size[0] * element_offset) - 1] ==
            varargin_3->data[(iy + varargin_3->size[0] * (element_offset + 1)) -
            1]) {
          qx1 = varargin_3->data[(iy + varargin_3->size[0] * element_offset) - 1];
        } else {
          qx1 = (1.0 - rx) * varargin_3->data[(iy + varargin_3->size[0] *
            element_offset) - 1] + rx * varargin_3->data[(iy + varargin_3->size
            [0] * (element_offset + 1)) - 1];
        }

        if (varargin_3->data[iy + varargin_3->size[0] * element_offset] ==
            varargin_3->data[iy + varargin_3->size[0] * (element_offset + 1)]) {
          rx = varargin_3->data[iy + varargin_3->size[0] * element_offset];
        } else {
          rx = (1.0 - rx) * varargin_3->data[iy + varargin_3->size[0] *
            element_offset] + rx * varargin_3->data[iy + varargin_3->size[0] *
            (element_offset + 1)];
        }
      }

      if ((varargin_5->data[i] == Y->data[iy - 1]) || (qx1 == rx)) {
        rx = qx1;
      } else if (varargin_5->data[i] == Y->data[iy]) {
      } else {
        ry = (varargin_5->data[i] - Y->data[iy - 1]) / (Y->data[iy] - Y->data[iy
          - 1]);
        rx = (1.0 - ry) * qx1 + ry * rx;
      }

      Vq->data[i] = rx;
    } else {
      Vq->data[i] = rtNaN;
    }
  }

  emxFree_real_T(&Y);
  emxFree_real_T(&X);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (interp2.c) */
