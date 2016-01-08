/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp2.h
 *
 * Code generation for function 'interp2'
 *
 */

#ifndef __INTERP2_H__
#define __INTERP2_H__

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
extern void interp2(const emlrtStack *sp, const emxArray_real_T *varargin_1,
                    const emxArray_real_T *varargin_2, const emxArray_real_T
                    *varargin_3, const emxArray_real_T *varargin_4, const
                    emxArray_real_T *varargin_5, emxArray_real_T *Vq);

#endif

/* End of code generation (interp2.h) */
