source ./setenv.sh

export BROWSER_PATH=firefox

cd $APP_ROOT


if [ ! -d "./$BUILD_DIR" ]; then
    echo -- Error: Build Directory Not Found! --
    exit /b 1
fi

cd $CURRENT_DIR

export WEBPAGE_PATH=$APP_ROOT/$BUILD_DIR/$APP_NAME.html

emrun --browser $BROWSER_PATH $WEBPAGE_PATH 