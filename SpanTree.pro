QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/gui/canvaswidget.cpp \
    src/gui/griddrawer.cpp \
    src/core/gridgraph.cpp \
    src/core/stgenerator.cpp \
    src/core/spantree.cpp \
    src/app/main.cpp

HEADERS += \
    src/gui/canvaswidget.h \
    src/gui/griddrawer.h \
    src/core/gridgraph.h \
    src/core/matrix.h \
    src/core/stgenerator.h \
    src/core/spantree.h

FORMS += \
    SpanTree.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    SpanTree.qrc
	
INCLUDEPATH += \
	src/include

UI_DIR = ../GeneratedFiles
MOC_DIR = ../GeneratedFiles
RCC_DIR = ../GeneratedFiles
OBJECTS_DIR = ./obj