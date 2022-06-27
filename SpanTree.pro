QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = SpanTree

#Default configuration
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#WebAssembly debug specific flags
wasm: equals(WASM_DEBUG, "true") {
	CONFIG += debug
	QT_WASM_TOTAL_MEMORY = 2GB
	QT_WASM_PTHREAD_POOL_SIZE = 8
}

#Set build generated file directories
CONFIG(debug, debug|release) {
	message(Generating $$TARGET Makefile for $(QMAKESPEC) (Debug mode).)
	MOC_DIR = ../GeneratedFiles/Debug
	UI_DIR  = ../GeneratedFiles/Debug
	RCC_DIR = ../GeneratedFiles/Debug
} else {
    message(Generating $$TARGET Makefile for $(QMAKESPEC) (Release mode))
	MOC_DIR = ../GeneratedFiles/Release
	UI_DIR  = ../GeneratedFiles/Release
	RCC_DIR = ../GeneratedFiles/Release
}
OBJECTS_DIR = .obj

#Add include files search paths
INCLUDEPATH += src/include

#Include file(s)
include($${TARGET}.pri)