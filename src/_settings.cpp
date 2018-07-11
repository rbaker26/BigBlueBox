#include "_settings.h"
using namespace bbb;


//*********************************************************************************
_Settings::_Settings()
{
    this->jsonPath = bbb::DirectoryHandler::getAndCheckRoamingPath();

    if(!jsonPath.contains(tempAppName))
    {
       // jsonPath.append(tempAppName);
    }
    jsonPath.append("/config/settings.json");
    qDebug() << "JSON Path" << jsonPath;

}
//*********************************************************************************



//*********************************************************************************
_Settings::~_Settings()
{

}
//*********************************************************************************

void  _Settings::appNamePassThough(QString name)
{
    tempAppName = name;
}


//*********************************************************************************
QJsonDocument _Settings::readFile(QString path)
{
    QString jsonText;

    QFile file;
    file.setFileName(jsonPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    jsonText = file.readAll();
    file.close();
    //qDebug() << jsonText.toUtf8();
    QJsonDocument docd = QJsonDocument::fromJson(jsonText.toUtf8());
    //qDebug() << "DOCD" << docd.toJson();

    return docd;
}
//*********************************************************************************



//*********************************************************************************
QString _Settings::getAppColorTheme()
{
    QJsonDocument jDoc = readFile(jsonPath);
    //qDebug() << jDoc;
    QJsonObject sett = jDoc.object();
    QJsonValue val = sett.value(QString("system_settings"));
    //qDebug() << val.toString();
    QJsonObject itm = val.toObject();
    QJsonValue subVal = itm["selected_theme"];

    return subVal.toString();

//    QJsonObject sett = jDoc.object();
//    QJsonValue sysSetting = sett.value(QString("system_settings"));

//    QJsonObject item =




}
//*********************************************************************************



//*********************************************************************************
void _Settings::setAppColorTheme(QString theme)
{

}
//*********************************************************************************
