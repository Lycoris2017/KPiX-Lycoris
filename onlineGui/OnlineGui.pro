
TEMPLATE = app
FORMS    = 
HEADERS  = ../generic/DataRead_v1.h ../generic/Data_v1.h ../kpix/KpixEvent_v1.h ../kpix/KpixSample_v1.h SharedMem.h MainWindow.h HistWindow.h KpixHistogram.h CalibWindow.h TimeWindow.h HitWindow.h ../generic/XmlVariables_v1.h
SOURCES  = ../generic/DataRead_v1.cpp ../generic/Data_v1.cpp ../kpix/KpixEvent_v1.cpp ../kpix/KpixSample_v1.cpp OnlineGui.cpp SharedMem.cpp MainWindow.cpp HistWindow.cpp KpixHistogram.cpp CalibWindow.cpp TimeWindow.cpp HitWindow.cpp ../generic/XmlVariables_v1.cpp
TARGET   = ../bin/onlineGui
QT       += network xml
INCLUDEPATH += ../generic/ ../kpix/ /usr/include/libxml2 /usr/include/qwt
LIBS        +=  -lqwt -lxml2 -lrt -lm -lbz2
