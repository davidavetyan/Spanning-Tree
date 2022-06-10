source ./setenv.sh

cd $APP_ROOT

if [ ! -d "./$BUILD_DIR" ]; then
  mkdir $BUILD_DIR
fi

cd $BUILD_DIR

$QMAKE $APP_ROOT/$APP_NAME.pro
$MAKE

cd $CURRENT_DIR
