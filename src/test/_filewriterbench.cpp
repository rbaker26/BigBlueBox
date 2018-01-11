#include "_filewriterbench.h"
using namespace bbbTest;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

_FileWriterBench::_FileWriterBench()
{
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
    const int numItemInVector = 200;

    // Some default vals for these meaningless items.
    QString name = "ItemName";
    int count    = 0;
    int target   = 0;

    bbb::Item tempItem;
    tempItem.itemName = name;
    for(int i = 0; i < numItemInVector; i++)
    {
        // Somewhat random vals
        tempItem.quantity = count * 3;
        tempItem.effectiveOnHand = target * 2;

        // increment val "seeds"
        count++;
        target++;

        returnVector.push_back(tempItem);
    }
    return returnVector;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

//void _FileWriterBench::txtBenchmark_data()
//{
////    using namespace bbb;
////    QVector<Item> iventory = this->tempVector;

////    QTest::addColumn<(QVector<Item>)>("itemVector");
////    QTest::newRow("Item Vector") << iventory;
//}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void _FileWriterBench::txtBenchmark()
{
    //set new file path for linux platform for testing.
    QBENCHMARK{
         bbb::_FileWriter::getInstance()->makeTxtInvReport(this->tempVector);
    }


}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
