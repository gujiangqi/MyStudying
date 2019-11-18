TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    spiderApp.cpp \
    confparser.cpp \
    spider_include.cpp

HEADERS += \
    confparser.h \
    spiderApp.h \
    spider_include.h \
    Url.h \
    UrlManager.h

