#!/bin/bash
  # This will build the project without tests.
  # It will not run the application because the GUI will timeout.
qmake -project
qmake src/BigBlueBox.pro
make
