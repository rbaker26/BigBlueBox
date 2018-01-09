###########################################################################
#   ______  _          ______  _                ______                    #
#  (____  \(_)        (____  \| |              (____  \                   #
#   ____)  )_  ____    ____)  ) |_   _  ____    ____)  ) ___ _   _        #
#  |  __  (| |/ _  |  |  __  (| | | | |/ _  )  |  __  ( / _ ( \ / )       #
#  | |__)  ) ( ( | |  | |__)  ) | |_| ( (/ /   | |__)  ) |_| ) X (        #
#  |______/|_|\_|| |  |______/|_|\____|\____)  |______/ \___(_/ \_)       #
#            (_____|                                                      #
###########################################################################


# in gear class, add default comments. like precomplied comments for health status or custom msg.
#2019 year, make a patrol box standered and put that into system,
#after 2018, empty all patrol boxs.  then add them back in to make a patrol box standered.

QT       += core gui sql testlib
CONFIG   += c++14
QMAKE_CXXFLAGS += -std=c++11

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
        gearcentral.cpp \
        usersession.cpp \
        _filewriter.cpp \
        mainmenu.cpp    \
        pages/settingspage.cpp \
        directoryhandler.cpp   \
    test/itemtest.cpp



        
HEADERS += \
        mainwindow.h    \
        reportsView.h   \
        item.h          \
        category.h      \
        dbconnect.h     \
        _regex.h        \
        gearcentral.h   \
        usersession.h   \
        _filewriter.h   \
        bbb.h           \
        mainmenu.h      \
        pages/settingspage.h \
        directoryhandler.h   \
    test/itemtest.h



        
FORMS += \
        mainwindow.ui   \
        reportsView.ui  \
        gearcentral.ui  \
        mainmenu.ui     \
        pages/settingspage.ui \
        
RESOURCES += \
    ../rec/rec.qrc \

test {

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SOURCES -= main.cpp

SOURCES += \
        test/unittest.cpp     \
        test/main.cpp         \
        test/_regextest.cpp   \
        test/categorytest.cpp \


HEADERS += \
        test/unittest.h     \
        test/_regextest.h   \
        test/categorytest.h \

RESOURCES -= \
    ../rec/rec.qrc \
}



