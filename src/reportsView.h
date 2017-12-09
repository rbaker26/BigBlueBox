#ifndef REPORTSVIEW_H
#define REPORTSVIEW_H

#include <QWidget>

#include "dbconnect.h"
#include "item.h"
#include "_regex.h"

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
};

#endif // REPORTSVIEW_H
