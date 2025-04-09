```
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH +=/usr/local/include/ \
              /usr/local/include/opencv4/ \
              /usr/local/include/opencv4/opencv2

LIBS += /usr/local/lib/*.so

SOURCES += \
        main.cpp

```
