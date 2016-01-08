@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=get_pathcosts_mex
set MEX_NAME=get_pathcosts_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for get_pathcosts > get_pathcosts_mex.mki
echo COMPILER=%COMPILER%>> get_pathcosts_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> get_pathcosts_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> get_pathcosts_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> get_pathcosts_mex.mki
echo LINKER=%LINKER%>> get_pathcosts_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> get_pathcosts_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> get_pathcosts_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> get_pathcosts_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> get_pathcosts_mex.mki
echo BORLAND=%BORLAND%>> get_pathcosts_mex.mki
echo OMPFLAGS= >> get_pathcosts_mex.mki
echo OMPLINKFLAGS= >> get_pathcosts_mex.mki
echo EMC_COMPILER=msvc120>> get_pathcosts_mex.mki
echo EMC_CONFIG=optim>> get_pathcosts_mex.mki
"C:\Program Files\MATLAB\R2015a\bin\win64\gmake" -B -f get_pathcosts_mex.mk
