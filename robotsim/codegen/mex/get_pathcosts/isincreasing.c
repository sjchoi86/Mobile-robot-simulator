/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * isincreasing.c
 *
 * Code generation for function 'isincreasing'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_pathcosts.h"
#include "isincreasing.h"

/* Function Definitions */
boolean_T isincreasing(const emxArray_real_T *x)
{
  boolean_T p;
  int32_T n;
  boolean_T guard1 = false;
  int32_T k;
  int32_T exitg1;
  n = x->size[1];
  guard1 = false;
  if (n >= 2) {
    k = 0;
    do {
      exitg1 = 0;
      if (k <= n - 2) {
        if (!(x->data[k] < x->data[1 + k])) {
          p = false;
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        guard1 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard1) {
    p = true;
  }

  return p;
}

/* End of code generation (isincreasing.c) */
