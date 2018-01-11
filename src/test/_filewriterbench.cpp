#include "_filewriterbench.h"
using namespace bbbTest;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

_FileWriterBench::_FileWriterBench()
{
    qDebug() << "\n";
    this->fileLoc = "./";
    this->textFileName = "text.txt";
    this->xmlFileName  = "myXml.xml";
    this->tempVector   = itemMaker();
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

QVector<bbb::Item> _FileWriterBench::itemMaker()
{
    QVector<bbb::Item> returnVector;

    // Total number of Items in Vector
    // This should be a somewhat large number so we can get meaningfull benchmarks.
    // Around 200 - 500 Items
    const int numItemInVector = 300;

    // Some default vals for these meaningless items.
    QString name = "ItemName";
    int count    = 10;
    int target   = 0;

    bbb::Item tempItem;
    tempItem.itemName = name;
    for(int i = 0; i < numItemInVector; i++)
    {
        // Somewhat random vals
        // The target will overtake the quantity
        tempItem.quantity = count * 3;
        tempItem.effectiveOnHand = target * 4;

        // increment val "seeds"
        count++;
        target++;

        returnVector.push_back(tempItem);
    }
    return returnVector;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void _FileWriterBench::txtBenchmark()
{
    typedef bbb::_FileWriter::ReportType rt;

    // Normal Printout
    QBENCHMARK{
         bbb::_FileWriter::getInstance()->makeTxtInvReport(this->tempVector);
    }

    // Low Report
    QBENCHMARK{
         bbb::_FileWriter::getInstance()->makeTxtInvReport(this->tempVector, rt::Low);
    }

    // Crit Low Report
    QBENCHMARK{
         bbb::_FileWriter::getInstance()->makeTxtInvReport(this->tempVector, rt::Critical);
    }

    // Expirable Report
    QBENCHMARK{
         bbb::_FileWriter::getInstance()->makeTxtInvReport(this->tempVector, rt::Expirable);
    }



}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
