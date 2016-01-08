MATLAB="/Applications/MATLAB_R2015b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/human/.matlab/R2015b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for get_pathcosts" > get_pathcosts_mex.mki
echo "CC=$CC" >> get_pathcosts_mex.mki
echo "CFLAGS=$CFLAGS" >> get_pathcosts_mex.mki
echo "CLIBS=$CLIBS" >> get_pathcosts_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> get_pathcosts_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> get_pathcosts_mex.mki
echo "CXX=$CXX" >> get_pathcosts_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> get_pathcosts_mex.mki
echo "CXXLIBS=$CXXLIBS" >> get_pathcosts_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> get_pathcosts_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> get_pathcosts_mex.mki
echo "LD=$LD" >> get_pathcosts_mex.mki
echo "LDFLAGS=$LDFLAGS" >> get_pathcosts_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> get_pathcosts_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> get_pathcosts_mex.mki
echo "Arch=$Arch" >> get_pathcosts_mex.mki
echo OMPFLAGS= >> get_pathcosts_mex.mki
echo OMPLINKFLAGS= >> get_pathcosts_mex.mki
echo "EMC_COMPILER=Xcode with Clang" >> get_pathcosts_mex.mki
echo "EMC_CONFIG=optim" >> get_pathcosts_mex.mki
"/Applications/MATLAB_R2015b.app/bin/maci64/gmake" -B -f get_pathcosts_mex.mk
