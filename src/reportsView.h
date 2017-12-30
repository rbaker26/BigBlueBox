#ifndef REPORTSVIEW_H
#define REPORTSVIEW_H

#include <QWidget>
#include <QPair>

#include "dbconnect.h"
#include "item.h"
#include "_regex.h"
#include "_filewriter.h"

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

    void on_pushButton_edit_clicked();

    void on_checkBox_editsOn_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_addDel_activated(int index);

    void on_pushButton_makeReport_clicked();

private:
    Ui::ReportsView *ui;
    //**********************************************************
    //! \brief Sends the doubleclicked row to the tool box
    //! \author Bob Baker
    void sendRowToToolBox(QStringList row);
    //**********************************************************

    //**********************************************************
    //! \brief Sets up the inventoy table
    //! \author Bob Baker
    void initTableInv();
    //**********************************************************

    //**********************************************************
    //! \brief Fills the inventory table from the database
    //! \author Bob Baker
    void fillTableInv();
    //**********************************************************

    void clearTable();

    QVector<bbb::Item> fullInventory;



    // 5 col size
    QString orgItemName;

    QString getOrgItemNameFromToolBox();
    bbb::Row getNewRowFromToolBox();
    QPair<QString, bbb::Row> makePair(QString orgName, bbb::Row r2);
    QPair<QString, bbb::Row> rowForUpdate;

    void updateStoredVector(QPair<QString, bbb::Row> rowForUpdate);
    void updateDataBase(QPair<QString, bbb::Row> rowForUpdate);


};

#endif // REPORTSVIEW_H
