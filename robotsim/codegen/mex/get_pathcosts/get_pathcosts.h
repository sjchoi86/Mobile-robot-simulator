/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_pathcosts.h
 *
 * Code generation for function 'get_pathcosts'
 *
 */

#ifndef __GET_PATHCOSTS_H__
#define __GET_PATHCOSTS_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "get_pathcosts_types.h"

/* Function Declarations */
extern void get_pathcosts(const emlrtStack *sp, const emxArray_real_T *xpaths,
  const emxArray_real_T *ypaths, const emxArray_real_T *xmesh, const
  emxArray_real_T *ymesh, const emxArray_real_T *grid4obscost, const real_T
  robot_pos[3], const real_T goal[2], emxArray_real_T *obscost, emxArray_real_T *
  goaldist);

#endif

/* End of code generation (get_pathcosts.h) */
