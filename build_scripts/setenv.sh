export CURRENT_DIR=$PWD
export BUILD_DIR=build

export APP_NAME=SpanTree
export APP_ROOT=$CURRENT_DIR/..

if [ -z ${QTDIR} ] ; then
    export QTDIR=$HOME/depot/Qt/5.15.2/wasm_32
fi

export QMAKE=$QTDIR/bin/qmake
export MAKE=make

export EMSDK_ENV=$HOME/depot/emsdk/emsdk_env.sh

source $EMSDK_ENV