# Shared library without any Qt functionality
TEMPLATE = lib
QT -= gui core

CONFIG += warn_on plugin release
CONFIG -= thread exceptions qt rtti debug

VERSION = 1.0.0

INCLUDEPATH += ./SDK/CHeaders/XPLM
INCLUDEPATH += ./SDK/CHeaders/Wrappers
INCLUDEPATH += ./SDK/CHeaders/Widgets

# Defined to use X-Plane SDK 2.0 capabilities - no backward compatibility before 9.0
DEFINES += XPLM200 XPLM210

DEFINES += PRIVATENAMESPACE=C604Plugin

win32 {
        DEFINES += APL=0 IBM=1 LIN=0
        LIBS += -L../SDK/Libraries/Win
        LIBS += -lXPLM -lXPWidgets
        TARGET = win.xpl
}

unix:!macx {
        DEFINES += APL=0 IBM=0 LIN=1
        TARGET = lin.xpl
        # WARNING! This requires the latest version of the X-SDK !!!!
        QMAKE_CXXFLAGS += -fvisibility=hidden
}

macx {
        DEFINES += APL=1 IBM=0 LIN=0
        TARGET = mac.xpl
        QMAKE_LFLAGS += -flat_namespace -undefined suppress

        # Build for multiple architectures.
        # The following line is only needed to build universal on PPC architectures.
        # QMAKE_MAC_SDK=/Developer/SDKs/MacOSX10.4u.sdk
        # The following line defines for which architectures we build.
        CONFIG += x86 # ppc
}

SOURCES += \
    plugin_main.cpp \
    plugin_interface/plugin.cpp \
    plugin_interface/testplugin.cpp \
    challenger604plugin.cpp

HEADERS += \
    plugin_interface/plugin.h \
    plugin_interface/testplugin.h \
    challenger604plugin.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/PPL-master/libC604Plugin/release/ -lppl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/PPL-master/libC604Plugin/debug/ -lppl
else:symbian: LIBS += -lppl
else:unix: LIBS += -L$$PWD/PPL-master/libC604Plugin/ -lppl

INCLUDEPATH += $$PWD/PPL-master/src
DEPENDPATH += $$PWD/PPL-master/src

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/PPL-master/libC604Plugin/release/ppl.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/PPL-master/libC604Plugin/debug/ppl.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/PPL-master/libC604Plugin/libppl.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Challenger604Logic-build-desktop-Desktop_Qt_4_8_1_for_GCC__Qt_SDK__Debug/release/ -lChallenger604Logic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Challenger604Logic-build-desktop-Desktop_Qt_4_8_1_for_GCC__Qt_SDK__Debug/debug/ -lChallenger604Logic
else:unix:!symbian: LIBS += -L$$PWD/../Challenger604Logic-build-desktop-Desktop_Qt_4_8_1_for_GCC__Qt_SDK__Debug/ -lChallenger604Logic

INCLUDEPATH += $$PWD/../Challenger604Logic
DEPENDPATH += $$PWD/../Challenger604Logic
