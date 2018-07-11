//********************************************************************
// MARK FOR DELETE - OBSOLETE
//********************************************************************
//#include "jsonReader.h"

//JSONReader::JSONReader()
//{
//    QString tempPath = bbb::DirectoryHandler::getAndCheckRoamingPath() + "/config/";
//    QDir dir(tempPath);
//    if(!dir.exists())
//    {
//        dir.mkpath(tempPath);
//    }
//    setPath(tempPath + "settings.json");
//}

//~JSONReader()
//{
//    if(file.isOpen())
//    {
//        file.close();
//    }
//}


//void JSONReader::setFilePath(QString path)
//{
//    if(file.isOpen())
//    {
//        file.close();
//    }

//    this->path = path;
//    file.open(path);
//}


//QString JSONReader::readJSON()
//{
//    QString json;
//    json = file.readAll();

//}
