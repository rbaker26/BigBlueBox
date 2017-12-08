#ifndef REPORTSVIEW_H
#define REPORTSVIEW_H

#include <QWidget>

#include "dbconnect.h"
#include "item.h"

namespace Ui {
class ReportsView;
}

class ReportsView : public QWidget
{
    Q_OBJECT

public:
    explicit ReportsView(QWidget *parent = 0);
    ~ReportsView();

private slots:

    void on_tableWidget_inv_cellDoubleClicked(int row, int column);

private:
    Ui::ReportsView *ui;
    void sendRowToToolBox(QStringList row);
};

#endif // REPORTSVIEW_H
