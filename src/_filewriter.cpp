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
//    delete instance;
//    instance = nullptr;
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
void _FileWriter::makeReport(QVector<Item> inventory)
{
    const int NAME_COL_SIZE = 30;
    const int OTHER_COL_SIZE = 14;
    QStringList oFileNames;
    oFileNames  << "../FULL_INVENTORY_REPORT.txt"
                << "../LOW_INVENTORY_REPORT.txt"
                << "../CRITICALLY_LOW_INVENTORY_REPORT.txt"
                << "../EXPIRABLE_INVENTORY_REPORT.txt";

    QFile file(oFileNames.at(0));

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

    }

    QTextStream ofs(&file);


    QVector<Item>::iterator it = inventory.begin();
    const QVector<Item>::iterator EXIT_FLAG = inventory.end();

    //ofs.setFieldWidth(5);
    //ofs.setFieldAlignment(QTextStream::AlignLeft);

    ofs << "-------------------------------------------------------------------------" << endl;
    ofs << "Full Inventory\n";
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

}
//*********************************************************************************
