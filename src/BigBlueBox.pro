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
QT       += core gui sql
CONFIG   += c++11
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
    _filewriter.cpp
        
HEADERS += \
        mainwindow.h    \
        reportsView.h   \
        item.h          \
        category.h      \
        dbconnect.h     \
        _regex.h        \
    gearcentral.h \
    usersession.h \
    _filewriter.h \
    bbb.h
        
FORMS += \
        mainwindow.ui   \
        reportsView.ui  \
    gearcentral.ui
        
test {

}

RESOURCES += \
    ../rec/rec.qrc

