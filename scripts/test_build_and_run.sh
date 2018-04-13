#!/bin/bash
 # This will build and run the project in test mode.
 # Test mode will execute all unit tests and will generate a coverage report.
 # The coverage report will be uploaded to codecov after_success.
 #- ./build.sh # I will make this later
 
qmake "CONFIG+=test" src/BigBlueBox.pro
make 
./BigBlueBox
codecov
