###########################################################################
#   ______  _          ______  _                ______                    #
#  (____  \(_)        (____  \| |              (____  \                   #
#   ____)  )_  ____    ____)  ) |_   _  ____    ____)  ) ___ _   _        #
#  |  __  (| |/ _  |  |  __  (| | | | |/ _  )  |  __  ( / _ ( \ / )       #
#  | |__)  ) ( ( | |  | |__)  ) | |_| ( (/ /   | |__)  ) |_| ) X (        #
#  |______/|_|\_|| |  |______/|_|\____|\____)  |______/ \___(_/ \_)       #
#            (_____|                                                      #
###########################################################################

QT       += core gui sql svg testlib    # Test lib only needed in test build after project is done
CONFIG   += c++14
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


INCLUDEPATH +="framelesswindow"

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
        main.cpp                \
        mainwindow.cpp          \
        item.cpp                \
        category.cpp            \
        dbconnect.cpp           \
        reportsView.cpp         \
        _regex.cpp              \
        usersession.cpp         \
        _filewriter.cpp         \
        mainmenu.cpp            \
        pages/settingspage.cpp  \
        directoryhandler.cpp    \
        _filereader.cpp         \
        pages/gearCenter.cpp    \
        qr/BitBuffer.cpp        \
        qr/QrCode.cpp           \
        qr/QrSegment.cpp        \
        qr/QrInterface.cpp      \
        gear.cpp                \
        framelesswindow/framelesswindow.cpp \
        framelesswindow/windowdragger.cpp   \
        DarkStyle.cpp           \
        pages/gearManager.cpp   \


        
HEADERS += \
        mainwindow.h            \
        reportsView.h           \
        item.h                  \
        category.h              \
        dbconnect.h             \
        _regex.h                \
        usersession.h           \
        _filewriter.h           \
        bbb.h                   \
        mainmenu.h              \
        pages/settingspage.h    \
        directoryhandler.h      \
        _filereader.h           \
        pages/gearCenter.h      \
        qr/BitBuffer.h          \
        qr/QrCode.h             \
        qr/QrSegment.h          \
        qr/QrInterface.h        \
        gear.h                  \
       framelesswindow/framelesswindow.h \
       framelesswindow/windowdragger.h   \
       DarkStyle.h              \
       pages/gearManager.h      \


        
FORMS += \
        mainwindow.ui           \
        reportsView.ui          \
        mainmenu.ui             \
        pages/settingspage.ui   \
        pages/gearCenter.ui     \
        pages/gearManager.ui    \
        
RESOURCES += \
            ../rec/rec.qrc      \
            framelesswindow.qrc \




###########################################################
# UNIT TESTING BUILD
###########################################################
test {

# These are for CodeCov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

# Remove normal main.cpp file
                      # This main will launch the GUI, not the testing




# Add the Unit Testing Files
SOURCES += \
        test/main.cpp           \
        test/unittest.cpp       \
        test/_regextest.cpp     \
        test/categorytest.cpp   \
        test/itemtest.cpp       \
        test/qrtest.cpp         \


# Add the Unit Testing Headers
HEADERS += \
        test/unittest.h         \
        test/_regextest.h       \
        test/categorytest.h     \
        test/itemtest.h         \
        test/qrtest.h           \


# Removing unnecessary files for unit testing
SOURCES -= \
        main.cpp \
        mainwindow.cpp          \
        #dbconnect.cpp           \
        reportsView.cpp         \
        usersession.cpp         \
        _filewriter.cpp         \
        mainmenu.cpp            \
        pages/settingspage.cpp  \
        directoryhandler.cpp    \
        #_filereader.cpp         \
        pages/gearCenter.cpp    \
        #qr/BitBuffer.cpp        \
        #qr/QrCode.cpp           \
        #qr/QrSegment.cpp        \
        #qr/QrInterface.cpp      \
        #gear.cpp                \

## Removing unnecessary header for unit testing
HEADERS -= \
        mainwindow.h            \
        reportsView.h           \
        #dbconnect.h             \
        usersession.h           \
        _filewriter.h           \
        bbb.h                   \
        mainmenu.h              \
        pages/settingspage.h    \
        directoryhandler.h      \
        #_filereader.h           \
        pages/gearCenter.h      \
        #qr/BitBuffer.h          \
        #qr/QrCode.h             \
        #qr/QrSegment.h          \
        #qr/QrInterface.h        \
        #gear.h                  \

#        mainwindow.h            \
#        pages/gearCenter.h      \
#        pages/settingspage.h    \
#        qr/BitBuffer.h          \
#        qr/QrCode.h             \
#        qr/QrSegment.h          \
#        qr/QrInterface.h        \
#        gear.h                  \
#        _filewriter.h           \
#        reportsView.h           \

# Remove all Forms
FORMS -= \
        mainwindow.ui           \
        reportsView.ui          \
        mainmenu.ui             \
        pages/settingspage.ui   \
        pages/gearCenter.ui     \

# Remove all recources
RESOURCES -= \
            ../rec/rec.qrc      \
            framelesswindow.qrc \

}
###########################################################



