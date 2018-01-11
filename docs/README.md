

<h1 align="center">BigBlueBox IMS</h1>
<div align="center">
  <img align="center" src="../rec/bluebox25x25.png" />
  <img align="center" src="../rec/bluebox25x25.png" />
  <img align="center" src="../rec/bluebox25x25.png" />
  <img align="center" src="../rec/bluebox25x25.png" />
  <img align="center" src="../rec/bluebox25x25.png" />
  <img align="center" src="../rec/bluebox25x25.png" />
  <img align="center" src="../rec/bluebox25x25.png" />
  <img align="center" src="../rec/bluebox25x25.png" />
  <img align="center" src="../rec/bluebox25x25.png" />
  <img align="center" src="../rec/bluebox25x25.png" />
</div>
  
<p align="center">
A Inventory Management System for a NYLT Course or other Boy Scout Programs. <br>
For source code documentation, <a href="https://rbaker26.github.io/BigBlueBox/html/index.html">click here</a>
</p>

<div align="center">
  <!-- Travis -->
  <a href="https://travis-ci.org/rbaker26/BigBlueBox">
    <img src="https://travis-ci.org/rbaker26/BigBlueBox.svg?branch=master"
      alt="Travis Build Status" />
  </a>
  <!-- Appveyor -->
  <a href="https://ci.appveyor.com/project/rbaker26/bigbluebox/branch/master">
    <img src="https://ci.appveyor.com/api/projects/status/n5w5hxdsnvb7jpm9/branch/master?svg=true"
      alt="Appveyor Build Status" />
  </a>
  <!-- Issues -->
  <a href="https://github.com/rbaker26/BigBlueBox/issues">
    <img src="https://img.shields.io/github/issues/rbaker26/BigBlueBox.svg"
      alt="Open Issues" />
  </a>
  <a href="https://github.com/rbaker26/BigBlueBox/issues">
    <img src="https://img.shields.io/github/issues-closed/rbaker26/BigBlueBox.svg"
      alt="Open Issues" />
  </a>
  
  <!-- Code Coverage via Codecov -->
  <a href="https://codecov.io/gh/rbaker26/BigBlueBox">
    <img src="https://codecov.io/gh/rbaker26/BigBlueBox/branch/master/graph/badge.svg"
      alt="Code Coverage" />
  </a>
  <!-- SamVer -->
  <a href="https://github.com/rbaker26/BigBlueBox/releases">
    <img src="https://img.shields.io/github/release/rbaker26/BigBlueBox/all.svg"
      alt="Version" />
  </a>
  <!-- License -->
  <a href="https://github.com/rbaker26/BigBlueBox/blob/master/LICENSE">
    <img src="https://img.shields.io/badge/License-GPL%20v3-blue.svg"
      alt="License" />
  </a>
  
</div>
<br />

<!-- Later I will add more links to the readme here--> 
<!--
<div align="center">
  <h3>
    <a href="">
      Website
    </a>
    <span> | </span>
    <a href="">
      Handbook
    </a>
    <span> | </span>
    <a href="">
      Ecosystem
    </a>
    <span> | </span> 
-->
   
<!--
    <a href="">
      Contributing
    </a>
    <span> | </span>
    <a href="">
      Reddit
    </a>
    <span> | </span>
    <a href="">
      Chat
    </a>
  </h3>
</div>

-->


## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

This project currently uses Qt 5.3.9, with the MSVC2017-64bit kit, and a SQLITE databased backend.<br>
<ul>
  <li> DB Browser for SQLITE can be found here: http://sqlitebrowser.org/ </li>
  <li> Qt - Open Source can be found here:  https://www1.qt.io/download-open-source/ </li>
</ul>
<br>  


### Installing

__DB Browser for SQLITE__

  1. Download correct version for your system.
  2. Run the installer.
  3. Specify the directory where DB Browser for SQLITE will be installed.
  4. Follow the rest of the installer's prompts.
  
__Qt__

  1. Download from website provided.
  2. Run the installer. 
  3. Login with a Qt Account or follow the steps provided to create one.
  4. Specify the directory where Qt will be installed.  (~30 GB) 
  
  5. <b> Select Components </b>  
        1. Select "Qt Creator [version #]" 
        2. Expand "Qt" tab.
        3. Select "Qt 5.9.3" or higher. 
  
  6. Follow the rest of the installer's prompts.

<br>


## Testing

Testing will include continuous integration testing using Travis.ci and regression testing using QtTestLib and Travis.ci.  

### CI Testing

This is simply ci test. This project uses two online ci services, Travis and Appveyor. 

#### Travis
Travis.ci will use .travis.yml and Shell build scripts to build the project.  If any new addtions create compile-time conflicts, they 
will be shown here.  <br>

[Click here](https://travis-ci.org/rbaker26/BigBlueBox) to see the latest travis.ci build status.
 
#### Appveyor
Appveyor will use appveyor.yml to build the project. If any new addtions create compile-time conflicts, they 
will be shown here.  <br>

[![Build history](https://buildstats.info/appveyor/chart/rbaker26/BigBlueBox)](https://ci.appveyor.com/project/rbaker26/BigBlueBox/history) <br>


### Regression Testing

Unit tests written with the QtTestLib will be run on travis.ci.  If any tests fail, travis.ci build state will be set to 
failed.  Tests will be exported to Codecov for a coverage report.  UI classes will not be tested. <br>
Tests will be verbose and should cover all possible paths within a function. <br> 
This project will follow the examples at [this](http://doc.qt.io/qt-5/qttestlib-tutorial1-example.html) link.

<br>

## Code Coverage
Coverage will be handled by Codecove.  The coverage report is generated during the test build in travis.ci.  The reports are uploaded from travis back to Codecov. This project has no target coverage percentage, but any tests that can be written should be writen.<br>
<div align="center">
  <a href="https://codecov.io/gh/rbaker26/BigBlueBox">
    <img align="center" src="https://codecov.io/gh/rbaker26/BigBlueBox/branch/master/graphs/commits.svg" slt="Coverage Graph"/>
  </a>  
  <br />
  <sub align="center">Graph of Coverage over Time</sub>
</div>
  
<br>

## Style

This project uses standard C++ style and Doxygen comments on all function prototypes, class definitions and enum definitions.
Doxygen comments should only be in .h files.  In .cpp files, regular C++ comments should be used.  

For more in-depth details regarding style, [click here](./Style.md) to go to the style page.

<br>

## Deployment

No deployment plan at this time.  Still in development.

<br>

## Built With

* [Qt Framework](http://www.dropwizard.io/1.0.2/docs/) - Desktop application framework 
* [SQLITE](https://www.sqlite.org) - Data Management
* [Doxygen](http://www.stack.nl/~dimitri/doxygen/index.html) - Autogenerating documentation

<br>

## Contributing
Message me if you want to contribute.

<br>

## Versioning
This project uses [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/rbaker26/BigBlueBox/tags). 

<br>

## Authors
* **Robert Baker** - *Initial work* - [github profile](https://github.com/rbaker26)

See also the list of [contributors](https://github.com/rbaker26/BigBlueBox/graphs/contributors) who participated in this project.

<br>

## License
This project is licensed under the GPL 3.0 License - see the [LICENSE.md](https://github.com/rbaker26/BigBlueBox/blob/master/LICENSE) file for details

<br>


## Acknowledgments
* [*Jeroen de Bruijn*](https://gist.github.com/vidavidorra) - Auto generation and deployment [script](https://github.com/rbaker26/BigBlueBox/blob/master/generateDocumentationAndDeploy.sh) for Doxygen after successful travis.ci build.  


