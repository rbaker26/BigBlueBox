#ifndef _FILEWRITERBENCH_H
#define _FILEWRITERBENCH_H

#include <QObject>
#include <QtTest>
#include <QDebug>

#include <QVector>

#include "item.h"
#include "_filewriter.h"



namespace bbbTest {
class _FileWriterBench : public QObject
{
    Q_OBJECT
public:
    _FileWriterBench();

private:
    QString fileLoc;
    QString textFileName;
    QString xmlFileName;
    QVector<bbb::Item> tempVector;

    QVector<bbb::Item> itemMaker();

private slots:

    void txtBenchmark();

    void xmlBenchmark();

}; // end class
} // end namespace

#endif // _FILEWRITERBENCH_H
