
HEADERS+=test.h
SOURCES+=main.cpp
QMAKE_CXXFLAGS+=-std=c++11
QMAKE_LIBS+=-lpthread
QT+=network

QMAKE_LFLAGS+="-Wl,--rpath=/root/sources/opencv-2.4.9/build/__install/lib"
LIBS += -L/root/sources/opencv-2.4.9/build/__install/lib/  -lopencv_core  -lopencv_highgui  -lopencv_objdetect -lopencv_imgproc -lopencv_ml -lopencv_video
INCLUDEPATH+=/root/sources/opencv-2.4.9/build/__install/include
