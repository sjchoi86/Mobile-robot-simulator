/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsearch.c
 *
 * Code generation for function 'bsearch'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_pathcosts.h"
#include "bsearch.h"

/* Function Definitions */
int32_T b_bsearch(const emxArray_real_T *x, real_T xi)
{
  int32_T n;
  int32_T low_ip1;
  int32_T high_i;
  int32_T b_n;
  int32_T b_high_i;
  int32_T mid_i;
  n = 1;
  low_ip1 = 2;
  high_i = x->size[1];
  while (high_i > low_ip1) {
    if (n >= 0) {
      b_n = (int32_T)((uint32_T)n >> 1);
    } else {
      b_n = (int32_T)~(~(uint32_T)n >> 1);
    }

    if (high_i >= 0) {
      b_high_i = (int32_T)((uint32_T)high_i >> 1);
    } else {
      b_high_i = (int32_T)~(~(uint32_T)high_i >> 1);
    }

    mid_i = b_n + b_high_i;
    if (((n & 1) == 1) && ((high_i & 1) == 1)) {
      mid_i++;
    }

    if (xi >= x->data[mid_i - 1]) {
      n = mid_i;
      low_ip1 = mid_i + 1;
    } else {
      high_i = mid_i;
    }
  }

  return n;
}

/* End of code generation (bsearch.c) */
