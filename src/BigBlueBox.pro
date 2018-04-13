###########################################################################
#   ______  _          ______  _                ______                    #
#  (____  \(_)        (____  \| |              (____  \                   #
#   ____)  )_  ____    ____)  ) |_   _  ____    ____)  ) ___ _   _        #
#  |  __  (| |/ _  |  |  __  (| | | | |/ _  )  |  __  ( / _ ( \ / )       #
#  | |__)  ) ( ( | |  | |__)  ) | |_| ( (/ /   | |__)  ) |_| ) X (        #
#  |______/|_|\_|| |  |______/|_|\____|\____)  |______/ \___(_/ \_)       #
#            (_____|                                                      #
###########################################################################

QT       += core gui sql svg testlib
CONFIG   += c++14
#QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -std=c++14
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = BigBlueBox
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp        \
        mainwindow.cpp  \
        item.cpp        \
        category.cpp    \
        dbconnect.cpp   \
        reportsView.cpp \
        _regex.cpp      \
        usersession.cpp \
        _filewriter.cpp \
        mainmenu.cpp    \
        pages/settingspage.cpp \
        directoryhandler.cpp   \
        _filereader.cpp        \
        pages/gearCenter.cpp   \
        qr/BitBuffer.cpp \
        qr/QrCode.cpp    \
        qr/QrSegment.cpp \
        qr/QrInterface.cpp \
        gear.cpp            \

        
HEADERS += \
        mainwindow.h    \
        reportsView.h   \
        item.h          \
        category.h      \
        dbconnect.h     \
        _regex.h        \
        usersession.h   \
        _filewriter.h   \
        bbb.h           \
        mainmenu.h      \
        pages/settingspage.h \
        directoryhandler.h   \
        _filereader.h        \
        pages/gearCenter.h   \
        qr/BitBuffer.h   \
        qr/QrCode.h      \
        qr/QrSegment.h \
        qr/QrInterface.h \
        gear.h           \

        
FORMS += \
        mainwindow.ui   \
        reportsView.ui  \
        mainmenu.ui     \
        pages/settingspage.ui \
        pages/gearCenter.ui   \
        
RESOURCES += \
    ../rec/rec.qrc \

test {

#QT -= svg

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SOURCES -= main.cpp \


SOURCES += \
        test/unittest.cpp     \
        test/main.cpp         \
        test/_regextest.cpp   \
        test/categorytest.cpp \
        test/itemtest.cpp     \
        test/_filewriterbench.cpp \


HEADERS += \
        test/unittest.h     \
        test/_regextest.h   \
        test/categorytest.h \
        test/itemtest.h     \
        test/_filewriterbench.h \


SOURCES -= \
        pages/gearCenter.cpp   \
        qr/BitBuffer.cpp \
        qr/QrCode.cpp    \
        qr/QrSegment.cpp \
        qr/QrInterface.cpp \
        gear.cpp            \

HEADERS -= \
        pages/gearCenter.h   \
        qr/BitBuffer.h   \
        qr/QrCode.h      \
        qr/QrSegment.h   \
        qr/QrInterface.h \
        gear.h           \


RESOURCES -= \
    ../rec/rec.qrc \
}



