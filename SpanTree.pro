QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/CanvasWidget.cpp \
    src/GridDrawer.cpp \
    src/GridGraph.cpp \
    src/STGenerator.cpp \
    src/SpanTree.cpp \
    src/main.cpp

HEADERS += \
    src/CanvasWidget.h \
    src/GridDrawer.h \
    src/GridGraph.h \
    src/Matrix.h \
    src/STGenerator.h \
    src/SpanTree.h

FORMS += \
    SpanTree.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    SpanTree.qrc

UI_DIR=../GeneratedFiles
MOC_DIR=../GeneratedFiles
RCC_DIR=../GeneratedFiles
OBJECTS_DIR=./obj