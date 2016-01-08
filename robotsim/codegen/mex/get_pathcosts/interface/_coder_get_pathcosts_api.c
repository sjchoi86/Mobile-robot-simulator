/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_get_pathcosts_api.c
 *
 * Code generation for function '_coder_get_pathcosts_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_pathcosts.h"
#include "_coder_get_pathcosts_api.h"
#include "get_pathcosts_emxutil.h"
#include "get_pathcosts_data.h"

/* Variable Definitions */
static emlrtRTEInfo e_emlrtRTEI = { 1, 1, "_coder_get_pathcosts_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *robot_pos, const char_T *identifier))[3];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *goal,
  const char_T *identifier))[2];
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *xpaths, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2];
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2];

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *robot_pos, const char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(robot_pos), &thisId);
  emlrtDestroyArray(&robot_pos);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *goal,
  const char_T *identifier))[2]
{
  real_T (*y)[2];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(goal), &thisId);
  emlrtDestroyArray(&goal);
  return y;
}
  static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *xpaths,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(xpaths), &thisId, y);
  emlrtDestroyArray(&xpaths);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv0[1] = { 0 };

  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u->data);
  emlrtSetDimensions((mxArray *)m0, u->size, 1);
  emlrtAssign(&y, m0);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2]
{
  real_T (*y)[2];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv1[2];
  int32_T i;
  int32_T iv2[2];
  boolean_T bv0[2] = { true, true };

  for (i = 0; i < 2; i++) {
    iv1[i] = -1;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv1, &bv0[0],
    iv2);
  ret->size[0] = iv2[0];
  ret->size[1] = iv2[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  int32_T iv3[2];
  int32_T i0;
  for (i0 = 0; i0 < 2; i0++) {
    iv3[i0] = 1 + (i0 << 1);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv3);
  ret = (real_T (*)[3])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2]
{
  real_T (*ret)[2];
  int32_T iv4[2];
  int32_T i1;
  for (i1 = 0; i1 < 2; i1++) {
    iv4[i1] = 1 + i1;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv4);
  ret = (real_T (*)[2])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void get_pathcosts_api(const mxArray * const prhs[7], const mxArray *plhs[2])
{
  emxArray_real_T *xpaths;
  emxArray_real_T *ypaths;
  emxArray_real_T *xmesh;
  emxArray_real_T *ymesh;
  emxArray_real_T *grid4obscost;
  emxArray_real_T *obscost;
  emxArray_real_T *goaldist;
  real_T (*robot_pos)[3];
  real_T (*goal)[2];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &xpaths, 2, &e_emlrtRTEI, true);
  emxInit_real_T(&st, &ypaths, 2, &e_emlrtRTEI, true);
  emxInit_real_T(&st, &xmesh, 2, &e_emlrtRTEI, true);
  emxInit_real_T(&st, &ymesh, 2, &e_emlrtRTEI, true);
  emxInit_real_T(&st, &grid4obscost, 2, &e_emlrtRTEI, true);
  b_emxInit_real_T(&st, &obscost, 1, &e_emlrtRTEI, true);
  b_emxInit_real_T(&st, &goaldist, 1, &e_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "xpaths", xpaths);
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "ypaths", ypaths);
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "xmesh", xmesh);
  emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "ymesh", ymesh);
  emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "grid4obscost", grid4obscost);
  robot_pos = c_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "robot_pos");
  goal = e_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "goal");

  /* Invoke the target function */
  get_pathcosts(&st, xpaths, ypaths, xmesh, ymesh, grid4obscost, *robot_pos,
                *goal, obscost, goaldist);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(obscost);
  plhs[1] = emlrt_marshallOut(goaldist);
  goaldist->canFreeData = false;
  emxFree_real_T(&goaldist);
  obscost->canFreeData = false;
  emxFree_real_T(&obscost);
  grid4obscost->canFreeData = false;
  emxFree_real_T(&grid4obscost);
  ymesh->canFreeData = false;
  emxFree_real_T(&ymesh);
  xmesh->canFreeData = false;
  emxFree_real_T(&xmesh);
  ypaths->canFreeData = false;
  emxFree_real_T(&ypaths);
  xpaths->canFreeData = false;
  emxFree_real_T(&xpaths);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_get_pathcosts_api.c) */
