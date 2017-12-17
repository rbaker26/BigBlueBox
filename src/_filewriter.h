#ifndef _FILEWRITER_H
#define _FILEWRITER_H

#include <QFile>
#include <QTextStream>

#include <QVector>
#include <QStringList>

#include "item.h"

namespace bbb
{
    class _FileWriter
    {
    private:
        _FileWriter();
        static _FileWriter* instance;
    public:
        //_FileWriter();
        ~_FileWriter();
        static _FileWriter* getInstance();

        // every option should also have a output to .csv option as well
        // can be controled via combo box dropdown in reports veiw.
         void makeReport(QVector<Item> inventory);
    };
}


#endif // _FILEWRITER_H
