QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QT += multimedia
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    16BitWav.cpp \
    32BitWav.cpp \
    8BitWav.cpp \
    Sorting.cpp \
    fileeditor.cpp \
    filemanager.cpp \
    main.cpp \
    puimanager.cpp \
    user_interface.cpp

HEADERS += \
    16BitWav.h \
    32BitWav.h \
    8BitWav.h \
    MetaDataHeader.h \
    MetaStructure.h \
    Sorting.h \
    WavFile.h \
    WavStructure.h \
    fileeditor.h \
    filemanager.h \
    puimanager.h \
    user_interface.h

FORMS += \
    Wav_Processor.ui

TRANSLATIONS += \
    WavProcessor_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
