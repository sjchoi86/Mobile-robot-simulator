/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * occflow.h
 *
 * Code generation for function 'occflow'
 *
 */

#ifndef __OCCFLOW_H__
#define __OCCFLOW_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "occflow_types.h"

/* Function Declarations */
extern void occflow(const emlrtStack *sp, const emxArray_real_T *cgridvec,
                    emxArray_real_T *cgridvecprev, emxArray_real_T *context,
                    const emxArray_real_T *nei_idx, const emxArray_real_T
                    *nei_weight, real_T nei_filter_n, const emxArray_real_T
                    *nei4u_idx, const emxArray_real_T *nei4u_weight, real_T
                    nei4u_filter_n, real_T occval, real_T minthreshold, real_T
                    maxthreshold, real_T reinitval, real_T intensifyrate, real_T
                    nocc_attenuaterate, real_T unknown_attenuaterate, real_T
                    sigm_coef, real_T do_attenuation_first, emxArray_real_T
                    *predvec, emxArray_real_T *maxvec);

#endif

/* End of code generation (occflow.h) */
