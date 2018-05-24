//*********************************************************************************
#include "_filewriter.h"
using namespace bbb;
//*********************************************************************************

//*********************************************************************************
_FileWriter* _FileWriter::instance = nullptr;
//*********************************************************************************

//*********************************************************************************
_FileWriter::_FileWriter()
{

}
//*********************************************************************************

//*********************************************************************************
_FileWriter::~_FileWriter()
{
    delete instance;
    instance = nullptr;
}
//*********************************************************************************

//*********************************************************************************
_FileWriter* _FileWriter::getInstance()
{
    if(instance == nullptr)
    {
        instance = new _FileWriter();
    }
    return instance;
}
//*********************************************************************************

//*********************************************************************************
QString _FileWriter::getReportsPath()
{
//    return QStandardPaths::locate(QStandardPaths::DesktopLocation,
//                                  "",
//                                  QStandardPaths::LocateDirectory);
    //qDebug() << _FileReader::readReportsDir();
    return QString(_FileReader::readReportsDir() + "/");
}
//*********************************************************************************

//*********************************************************************************
// I am sorry to anyone who comes along to work on this function.  I tried to put
//  the loops into functions and inline functions, but no worky.  I was not about
//  to do #define macros.  Global scope is worse. - bob
void _FileWriter::makeTxtInvReport(QVector<Item> inventory, ReportType type)
{
    const int NAME_COL_SIZE = 30;
    const int OTHER_COL_SIZE = 14;
    QStringList oFileNames;
    oFileNames  << "FULL_INVENTORY_REPORT.txt"
                << "LOW_INVENTORY_REPORT.txt"
                << "CRITICALLY_LOW_INVENTORY_REPORT.txt"
                << "EXPIRABLE_INVENTORY_REPORT.txt"
                << "error.txt";

    int reportIndex = static_cast<int>(type);
    QFile file(getReportsPath() + oFileNames.at(reportIndex) );


    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << file.errorString();
    }


    QTextStream ofs(&file);


    QVector<Item>::iterator it = inventory.begin();
    const QVector<Item>::iterator EXIT_FLAG = inventory.end();

    //ofs.setFieldWidth(5);
    //ofs.setFieldAlignment(QTextStream::AlignLeft);

    ofs << "-------------------------------------------------------------------------" << endl;
    switch (type)
    {
    case Full      : ofs << "Full Inventory Report\n";                    break;
    case Low       : ofs << "Low Inventory Report (35% to target)\n";     break;
    case Critical  : ofs << "Critical Iventory Report (10% to target)\n"; break;
    case Expirable : ofs << "Expirable Inventory Report\n";                 break;
    default : ofs << "Bad enum value passed to txt writer\n"; break;
    }
    ofs << "-------------------------------------------------------------------------" << endl;
    ofs << endl;
    ofs << "-------------------------------------------------------------------------" << endl;
    ofs << left
        << qSetFieldWidth(NAME_COL_SIZE) << "Item Name"
        << right
        << qSetFieldWidth(OTHER_COL_SIZE)
        << qSetFieldWidth(OTHER_COL_SIZE) << "Quantity"
        << qSetFieldWidth(OTHER_COL_SIZE) << "Target #"
        << qSetFieldWidth(OTHER_COL_SIZE) << "Needed"
        << endl;
    ofs << "-------------------------------------------------------------------------" << endl;

    switch (type)
    {
    case Full :
        while(it != EXIT_FLAG)
        {
            ofs << left
                << qSetFieldWidth(NAME_COL_SIZE) << it->itemName
                << right
                << qSetFieldWidth(OTHER_COL_SIZE) << it->quantity
                << qSetFieldWidth(OTHER_COL_SIZE) << it->effectiveOnHand
                << qSetFieldWidth(OTHER_COL_SIZE) <<
                   (it->quantity < it->effectiveOnHand ? it->effectiveOnHand - it->quantity : 0)
                << endl;
            it++;
        }
        break;

    case Low :
        while(it != EXIT_FLAG)
        {
            if(it->effectiveOnHand == 0)
            {
                it++;
                continue;
            }
            if( (it->quantity - it->effectiveOnHand) / static_cast<float>(it->effectiveOnHand) <= .35f)
            {
                ofs << left
                    << qSetFieldWidth(NAME_COL_SIZE) << it->itemName
                    << right
                    << qSetFieldWidth(OTHER_COL_SIZE) << it->quantity
                    << qSetFieldWidth(OTHER_COL_SIZE) << it->effectiveOnHand
                    << qSetFieldWidth(OTHER_COL_SIZE) <<
                       (it->quantity < it->effectiveOnHand ? it->effectiveOnHand - it->quantity : 0)
                    << endl;
            }
            it++;
        }
        break;

    case Critical :
        while(it != EXIT_FLAG)
        {
            if(it->effectiveOnHand == 0)
            {
                it++;
                continue;
            }
            if((it->quantity - it->effectiveOnHand) / static_cast<float>(it->effectiveOnHand) <= .10f)
            {
                ofs << left
                    << qSetFieldWidth(NAME_COL_SIZE) << it->itemName
                    << right
                    << qSetFieldWidth(OTHER_COL_SIZE) << it->quantity
                    << qSetFieldWidth(OTHER_COL_SIZE) << it->effectiveOnHand
                    << qSetFieldWidth(OTHER_COL_SIZE) <<
                       (it->quantity < it->effectiveOnHand ? it->effectiveOnHand - it->quantity : 0)
                    << endl;
            }
            it++;
        }
        break;

    case Expirable :
        while(it != EXIT_FLAG)
        {
            if(it->canExpire)
            {
                ofs << left
                    << qSetFieldWidth(NAME_COL_SIZE) << it->itemName
                    << right
                    << qSetFieldWidth(OTHER_COL_SIZE) << it->quantity
                    << qSetFieldWidth(OTHER_COL_SIZE) << it->effectiveOnHand
                    << qSetFieldWidth(OTHER_COL_SIZE) <<
                       (it->quantity < it->effectiveOnHand ? it->effectiveOnHand - it->quantity : 0)
                    << endl;
            }
            it++;
        }
        break;

    default :
        ofs << "Error, bad ReportType enum passed";
         break;
    }

    file.close();

}
//*********************************************************************************

//*********************************************************************************
// I am sorry to anyone who comes along to work on this function.  I tried to put
//  the loops into functions and inline functions, but no worky.  I was not about
//  to do #define macros.  Global scope is worse. - bob
void _FileWriter::makeXmlInvReport(QVector<Item> inventory, ReportType type)
{
    QStringList oFileNames;
    oFileNames  << "FULL_INVENTORY_REPORT.xml"
                << "LOW_INVENTORY_REPORT.xml"
                << "CRITICALLY_LOW_INVENTORY_REPORT.xml"
                << "EXPIRABLE_INVENTORY_REPORT.xml"
                << "db_dump.xml";

    int reportIndex = static_cast<int>(type);

    //qDebug() << reportIndex;
    QFile file(getReportsPath() + oFileNames.at(reportIndex));

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << file.errorString();
    }

    QXmlStreamWriter stream(&file);

    QVector<Item>::iterator it = inventory.begin();
    const QVector<Item>::iterator EXIT_FLAG = inventory.end();


    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeComment("Created On:\t " + QDateTime::currentDateTime().toString());

    stream.writeComment("No Current Schema for this xml");
    stream.writeComment("This xml is output only.  "
                        "The bbb API should not read back from xml. "
                        "It is too dangerous");

    stream.writeStartElement("inventory");

    switch (type)
    {
    case Full:
        while(it != EXIT_FLAG)
        {
            stream.writeStartElement("item");

            // these are commented out bc excel put them into cols
            // they are here bc they are good info to have, but not needed for shopping list
            // stream.writeAttribute("dateModified", it->dateModified.toString());
            // stream.writeAttribute("modifiedBy", it->modifiedBy);

            stream.writeTextElement("itemName", it->itemName);
            stream.writeTextElement("quantity", QString::number(it->quantity));
            stream.writeTextElement("targetQuantity", QString::number(it->effectiveOnHand));
            stream.writeTextElement("needed", QString::number(it->quantity < it->effectiveOnHand
                                                              ? it->effectiveOnHand - it->quantity
                                                              : 0));
            stream.writeEndElement();
            it++;
        }
        break;
    case Low :

        while(it != EXIT_FLAG)
        {
            if(it->effectiveOnHand == 0)
            {
                it++;
                continue;
            }
            if( (it->quantity - it->effectiveOnHand) / static_cast<float>(it->effectiveOnHand) <= .35f)
            {
                stream.writeStartElement("item");
                stream.writeTextElement("itemName", it->itemName);
                stream.writeTextElement("quantity", QString::number(it->quantity));
                stream.writeTextElement("targetQuantity", QString::number(it->effectiveOnHand));
                stream.writeTextElement("needed", QString::number(it->quantity < it->effectiveOnHand
                                                                  ? it->effectiveOnHand - it->quantity
                                                                : 0));
                stream.writeEndElement();
            }

            it++;

        }
        break;
    case Critical :
        while(it != EXIT_FLAG)
        {
            if(it->effectiveOnHand == 0)
            {
                it++;
                continue;
            }
            if( (it->quantity - it->effectiveOnHand) / static_cast<float>(it->effectiveOnHand) <= .10f)
            {
                stream.writeStartElement("item");
                stream.writeTextElement("itemName", it->itemName);
                stream.writeTextElement("quantity", QString::number(it->quantity));
                stream.writeTextElement("targetQuantity", QString::number(it->effectiveOnHand));
                stream.writeTextElement("needed", QString::number(it->quantity < it->effectiveOnHand
                                                                  ? it->effectiveOnHand - it->quantity
                                                                  : 0));
                stream.writeEndElement();
            }

            it++;

        }
        break;
    case Expirable :

        while(it != EXIT_FLAG)
        {
            if(it->canExpire)
            {
                stream.writeStartElement("item");
                stream.writeTextElement("itemName", it->itemName);
                stream.writeTextElement("quantity", QString::number(it->quantity));
                stream.writeTextElement("targetQuantity", QString::number(it->effectiveOnHand));
                stream.writeTextElement("needed", QString::number(it->quantity < it->effectiveOnHand
                                                                  ? it->effectiveOnHand - it->quantity
                                                                  : 0));
                stream.writeEndElement();
            }

            it++;
        }

        break;
    case DbDump :
        while(it != EXIT_FLAG)
        {
            stream.writeStartElement("item");
            stream.writeAttribute("dateModified", it->dateModified.toString("yyyy/MM/dd hh:mm:ss"));
            stream.writeAttribute("modifiedBy", it->modifiedBy);

            stream.writeTextElement("itemName", it->itemName);
            stream.writeTextElement("quantity", QString::number(it->quantity));
            stream.writeTextElement("targetQuantity", QString::number(it->effectiveOnHand));
            stream.writeTextElement("catagory", bbb::Category::categoryToQString(it->category));
            stream.writeTextElement("box_num", QString::number(it->boxNum));


            stream.writeEndElement();
            it++;
        }
    default :
        stream.writeComment("Bad Enum passed to xml function");

    }

    stream.writeEndElement(); // end inventory


    stream.writeEndDocument();
    file.close();
}
//*********************************************************************************


//*********************************************************************************
void _FileWriter::writeDbFileLoc(QString path)
{
    QFile dbFile("C:/Users/007ds/Documents/GitHub/BigBlueBox/rec/db_path.data");  // todo correct to proper final path

    dbFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);

    QTextStream ofs(&dbFile);

    ofs << path;
    ofs.flush();

    dbFile.close();


}
//*********************************************************************************


//*********************************************************************************
void _FileWriter::writeReportsDir(QString path)
{
    QFile file("C:/Users/007ds/Documents/GitHub/BigBlueBox/rec/report_dir.data");  // todo correct to proper final path

    file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);

    QTextStream ofs(&file);

    ofs << path;
    ofs.flush();

    file.close();
}
//*********************************************************************************
