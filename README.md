# BigBlueBox
[![Build Status](https://travis-ci.org/rbaker26/BigBlueBox.svg?branch=master)](https://travis-ci.org/rbaker26/BigBlueBox) 
[![Build status](https://ci.appveyor.com/api/projects/status/n5w5hxdsnvb7jpm9/branch/master?svg=true)](https://ci.appveyor.com/project/rbaker26/bigbluebox/branch/master)
[![codecov](https://codecov.io/gh/rbaker26/BigBlueBox/branch/master/graph/badge.svg)](https://codecov.io/gh/rbaker26/BigBlueBox)
[![GitHub (pre-)release](https://img.shields.io/github/release/rbaker26/BigBlueBox/all.svg)](https://travis-ci.org/rbaker26/BigBlueBox)
<!-- [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) -->
<br>

A Inventory Management System for a NYLT Course or other Boy Scout Programs.

For documentation for source code, [click here](https://rbaker26.github.io/BigBlueBox/html/index.html).

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
  3. Login with a Qt Account or follow the steps provided to creare one.
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

This is simply ci test.  Travis.ci will use a .yml to build the files.  If any new addtions create compile-time conflicts, they 
will be shown here.  


 [Click here](https://travis-ci.org/rbaker26/BigBlueBox) to see the latest travis.ci build status.
 

### Regression Testing

Unit tests written with the QtTestLib will be run on travis.ci.  If any tests fail, travis.ci build state will be set to 
failed.   
This project will follow the examples at [this](http://doc.qt.io/qt-5/qttestlib-tutorial1-example.html) link.

<br>

## Style

This project uses standard C++ style and Doxygen comments on all function prototypes, class definitions and enum definitions.
Doxygen comments should only be in .h files.  In .cpp files, regular C++ comments should be used.  

For more in-depth details regarding style, [click here]() to go to the style page.

<br>

## Deployment

No deployment plan at this time.  Still in development.

<br>

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

<br>

## Contributing
Message me if you want to contribute.

<br>

## Versioning
This project uses [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/rbaker26/BigBlueBox/tags). 

<br>

## Authors
* **Robert Baker** - *Initial work* 

See also the list of [contributors](https://github.com/rbaker26/BigBlueBox/graphs/contributors) who participated in this project.

<br>

## License
This project is licensed under the GPL 3.0 License - see the [LICENSE.md](https://github.com/rbaker26/BigBlueBox/blob/master/LICENSE) file for details

<br>

<!--
## Acknowledgments
* Hat tip to anyone who's code was used
* Inspiration
* etc


-->
