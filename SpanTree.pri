# Header files
HEADERS += \
    src/core/matrix.h \
    src/core/gridgraph.h \
    src/core/stgenerator.h \
    src/gui/spantree.h \
    src/gui/canvaswidget.h \
    src/gui/griddrawer.h

# Source files
SOURCES += \
    src/app/main.cpp \
    src/core/gridgraph.cpp \
    src/core/stgenerator.cpp \
    src/gui/spantree.cpp \
    src/gui/canvaswidget.cpp \
    src/gui/griddrawer.cpp

# Resource file(s)
RESOURCES += \
    SpanTree.qrc

# Forms
FORMS += \
    SpanTree.ui