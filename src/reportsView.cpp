#include "reportsView.h"
#include "ui_reportsView.h"
//*********************************************************************************

ReportsView::ReportsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportsView)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(3);

    clearTable();

    initTableInv();
    fillTableInv();

    ui->pushButton_edit->setEnabled(false);


}
//*********************************************************************************

//*********************************************************************************
ReportsView::~ReportsView()
{
    delete ui;
}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_tableWidget_inv_cellDoubleClicked(int row, int column)
{
    QStringList rowData;
    for(int i = 0; i < ui->tableWidget_inv->columnCount(); i++)
    {
        rowData << ui->tableWidget_inv->item(row, i)->text();
    }
    qDebug() << "Row\t" << "Column\t";
    qDebug() << row << "\t" << column;
    qDebug() << rowData;

    sendRowToToolBox(rowData);

    orgItemName = getOrgItemNameFromToolBox();

}
//*********************************************************************************

//*********************************************************************************
void ReportsView::sendRowToToolBox(QStringList row)
{
    QString name = row.at(0);
    int quantity = QString(row.at(1)).toInt();
    int target = QString((row.at(2))).toInt();
    QString catString = (QString(row.at(3)));
    QString  boxNum = row.at(4);


    //***********************************************
    //* Adjust tool box
    //***********************************************
    ui->lineEdit_itemName->setText(name);
    ui->spinBox_quantity->setValue(quantity);
    ui->spinBox_targetQ->setValue(target);
    ui->lineEdit_cat->setText(catString);
    ui->lineEdit_box->setText(boxNum);
    //***********************************************

    //***********************************************
    //* Add / Delete tool box
    //***********************************************
    ui->lineEdit_itemNameNew->setText(name);
    ui->spinBox_quantityNew->setValue(quantity);
    ui->spinBox_targetQNew->setValue(target);
    ui->lineEdit_catNew->setText(catString);
    ui->lineEdit_boxNew->setText(boxNum);
    //***********************************************

}
//*********************************************************************************

//*********************************************************************************
void ReportsView::initTableInv()
{
    QStringList header;
    header << "Name" << "Quantity" << "EFOH" << "Cat" << "BOX#";
    ui->tableWidget_inv->setColumnCount(5);
    ui->tableWidget_inv->setHorizontalHeaderLabels(header);
    ui->tableWidget_inv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_inv->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_inv->verticalHeader()->hide();

    ui->tableWidget_inv->setSortingEnabled(false);
}
//*********************************************************************************

//*********************************************************************************
void ReportsView::fillTableInv()
{
    fullInventory = DbConnect::getInstance()->getFullInvAsVector();
    QVector<Item>::iterator it              = fullInventory.begin();
    const QVector<Item>::iterator EXIT_FLAG = fullInventory.end();

    int rowCount = 0;
    while(it != EXIT_FLAG)
    { // Start While loop
        ui->tableWidget_inv->insertRow(ui->tableWidget_inv->rowCount());

        ui->tableWidget_inv->setItem(rowCount ,0, new QTableWidgetItem(it->itemName));
        ui->tableWidget_inv->setItem(rowCount ,1, new QTableWidgetItem(QString::number((it->quantity))));
        ui->tableWidget_inv->setItem(rowCount ,2, new QTableWidgetItem(QString::number(it->effectiveOnHand)));
        //QString catagoryS = Category::categoryToQString(QString::number(it->category).toInt()-1);
        ui->tableWidget_inv->setItem(rowCount ,3, new QTableWidgetItem(QString::number(static_cast<int>(it->category))));
        ui->tableWidget_inv->setItem(rowCount ,4, new QTableWidgetItem(QString::number(it->boxNum)));
        rowCount++;
        it++;
    }// end while-loop
}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_pushButton_edit_clicked()
{
    typedef bbb2::_Regex rx;
    bool regexPass = ( rx::isItemName( ui->lineEdit_itemName->text()) &&
                       rx::isBoxName(ui->lineEdit_box->text())  );

    Row thisRow;
    thisRow.itemName = ui->lineEdit_itemName->text();
    thisRow.quantity = ui->spinBox_quantity->value();
    thisRow.category = static_cast<Category::categoryType>(ui->lineEdit_cat->text().toInt());
    thisRow.effectiveOnHand = ui->spinBox_targetQ->value();
    thisRow.boxNum = ui->lineEdit_box->text().toInt();
//    bool inputFieldsHaveChanged = 0;
    if(regexPass)
    {
        // push to db
        DbConnect::getInstance()->updateItem(orgItemName, thisRow);
        qDebug() << "Push to db";

    }
    // ***************
    qDebug() <<
    (rx::isItemName( ui->lineEdit_itemName->text()) ? "REGEX SUCCESS" : "REGEX FAIL" );
    // ***************


    ui->lineEdit_itemName->clear();
    ui->lineEdit_cat->clear();
    ui->lineEdit_box->clear();
    ui->spinBox_quantity->clear();
    ui->spinBox_targetQ->clear();
    clearTable();
    initTableInv();
    fillTableInv();
}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_checkBox_editsOn_clicked()
{
    if(ui->checkBox_editsOn->isChecked())
    {
        ui->pushButton_edit->setEnabled(true);
    }
    else
    {
        ui->pushButton_edit->setEnabled(false);
    }

}
//*********************************************************************************

//*********************************************************************************
void ReportsView::clearTable()
{
    ui->tableWidget_inv->clear();
    ui->tableWidget_inv->setRowCount(0);
}

QString ReportsView::getOrgItemNameFromToolBox()
{
    return ui->lineEdit_itemName->text();
}

Row ReportsView::getNewRowFromToolBox()
{
    Row r2;
    r2.itemName = ui->lineEdit_itemName->text();
    r2.quantity = ui->spinBox_quantity->value();
    r2.effectiveOnHand = ui->spinBox_quantity->value();

    return r2;
}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_comboBox_currentIndexChanged(int index)
{

}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_comboBox_addDel_activated(int index)
{
    if(index == 0 /* 0 = "add" */)
    {
        ui->lineEdit_itemNameNew->setEnabled(true);
        ui->lineEdit_catNew->setEnabled(true);
        ui->lineEdit_boxNew->setEnabled(true);
        ui->spinBox_quantityNew->setEnabled(true);
        ui->spinBox_targetQNew->setEnabled(true);
    }
    else if(index == 1 /* 1 = "remove" */)
    {
        ui->lineEdit_itemNameNew->setEnabled(true);
        ui->lineEdit_catNew->setEnabled(false);
        ui->lineEdit_boxNew->setEnabled(false);
        ui->spinBox_quantityNew->setEnabled(false);
        ui->spinBox_targetQNew->setEnabled(false);
    }
}
//*********************************************************************************
