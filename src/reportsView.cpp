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
    bool isChecked = (row.at(5) == "Yes" ? true : false);

    int index = bbb::Category::intFromString(catString); // for cat combo boxes
    //***********************************************
    //* Adjust tool box
    //***********************************************
    ui->lineEdit_itemName->setText(name);
    ui->spinBox_quantity->setValue(quantity);
    ui->spinBox_targetQ->setValue(target);
    //ui->lineEdit_cat->setText(catString);
    ui->comboBox_adjCat->setCurrentIndex(index);
    ui->lineEdit_box->setText(boxNum);
    // this sets the checkbox depending on the Yes/"" string
    ui->checkBox_canExp_adj->setCheckState( (isChecked ? Qt::CheckState::Checked : Qt::CheckState::Unchecked) );
    //***********************************************

    //***********************************************
    //* Add / Delete tool box
    //***********************************************
    ui->lineEdit_itemNameNew->setText(name);
    ui->spinBox_quantityNew->setValue(quantity);
    ui->spinBox_targetQNew->setValue(target);
    //ui->lineEdit_catNew->setText(catString);
    ui->comboBox_addDelCat->setCurrentIndex(index);
    ui->lineEdit_boxNew->setText(boxNum);
    ui->checkBox_canExpireNew->setCheckState( (isChecked ? Qt::CheckState::Checked : Qt::CheckState::Unchecked) );
    //***********************************************

}
//*********************************************************************************

//*********************************************************************************
void ReportsView::initTableInv()
{
    QStringList header;
    header << "Name" << "Quantity" << "Target Quantity" << "Category" << "BOX#" << "Can Expire";
    ui->tableWidget_inv->setColumnCount(6);
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
    fullInventory = bbb::DbConnect::getInstance()->getFullInvAsVector();
    QVector<bbb::Item>::iterator it              = fullInventory.begin();
    const QVector<bbb::Item>::iterator EXIT_FLAG = fullInventory.end();

    ui->tableWidget_inv->setSortingEnabled(false);
    QString canExp;
    int rowCount = 0;
    while(it != EXIT_FLAG)
    { // Start While loop
        ui->tableWidget_inv->insertRow(ui->tableWidget_inv->rowCount());

        ui->tableWidget_inv->setItem(rowCount ,0, new QTableWidgetItem(it->itemName));
        ui->tableWidget_inv->setItem(rowCount ,1, new QTableWidgetItem(QString::number((it->quantity))));
        ui->tableWidget_inv->setItem(rowCount ,2, new QTableWidgetItem(QString::number(it->effectiveOnHand)));
        QString catagoryS = bbb::Category::categoryToQString(QString::number(it->category).toInt());
        //qDebug() << catagoryS;
        // good code below, only does ints
        //ui->tableWidget_inv->setItem(rowCount ,3, new QTableWidgetItem(QString::number(static_cast<int>(it->category))));

        ui->tableWidget_inv->setItem(rowCount ,3, new QTableWidgetItem(catagoryS));
        ui->tableWidget_inv->setItem(rowCount ,4, new QTableWidgetItem(it->boxStr));

        canExp = (it->canExpire ? "Yes" : "");
        ui->tableWidget_inv->setItem(rowCount ,5, new QTableWidgetItem(canExp));
        rowCount++;
        it++;
    }// end while-loop
    //ui->tableWidget_inv->setSortingEnabled(true);
    // no sorting for now. The order it is sorting in for nums is (0, 1, 10, 11, 2, 20, 22, ..)
}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_pushButton_edit_clicked()
{
    typedef bbb::_Regex rx;
    bool regexPass = ( rx::isItemName( ui->lineEdit_itemName->text()) &&
                       rx::isBoxName(ui->lineEdit_box->text())  );

    bbb::Row thisRow;
    thisRow.itemName = ui->lineEdit_itemName->text();
    thisRow.quantity = ui->spinBox_quantity->value();
    //thisRow.category = static_cast<bbb::Category::categoryType>(ui->lineEdit_cat->text().toInt());
    thisRow.category = static_cast<bbb::Category::categoryType>(ui->comboBox_adjCat->currentIndex());
    thisRow.effectiveOnHand = ui->spinBox_targetQ->value();
    thisRow.boxNum = ui->lineEdit_box->text().toInt();                                              // mark for delete
    thisRow.boxStr = ui->lineEdit_box->text();
    //qDebug() << thisRow.boxStr;
    thisRow.dateModified = QDateTime::currentDateTime();
    //thisRow.modifiedBy // do something                                                               // todo

    thisRow.canExpire = ui->checkBox_canExp_adj->isChecked();
    //qDebug() << thisRow.canExpire;

    // ***************
    qDebug() <<
    (rx::isItemName( ui->lineEdit_itemName->text()) ? "REGEX SUCCESS" : "REGEX FAIL" );
    // ***************
    if(regexPass)
    {
        // push to db
        bbb::DbConnect::getInstance()->updateItem(orgItemName, thisRow);
        qDebug() << "Push to db";
    }

    ui->lineEdit_itemName->clear();
    //ui->lineEdit_cat->clear();
    ui->comboBox_adjCat->setCurrentIndex(0);
    ui->lineEdit_box->clear();
    ui->spinBox_quantity->clear();
    ui->spinBox_targetQ->clear();
    ui->checkBox_canExp_adj->setCheckState(Qt::CheckState::Unchecked);
    // these update the ui table after the edit
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

bbb::Row ReportsView::getNewRowFromToolBox()
{
    bbb::Row r2;
    r2.itemName = ui->lineEdit_itemName->text();
    r2.quantity = ui->spinBox_quantity->value();
    r2.effectiveOnHand = ui->spinBox_quantity->value();

    return r2;
}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_comboBox_currentIndexChanged(int index)
{
    // mark_for_delete
}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_comboBox_addDel_activated(int index)
{
    if(index == 0 /* 0 = "add" */)
    {
        ui->lineEdit_itemNameNew->setEnabled(true);
        //ui->lineEdit_catNew->setEnabled(true);
        ui->comboBox_addDelCat->setEnabled(true);
        ui->lineEdit_boxNew->setEnabled(true);
        ui->spinBox_quantityNew->setEnabled(true);
        ui->spinBox_targetQNew->setEnabled(true);
        ui->checkBox_canExpireNew->setEnabled(true);
    }
    else if(index == 1 /* 1 = "remove" */)
    {
        ui->lineEdit_itemNameNew->setEnabled(true);
        //ui->lineEdit_catNew->setEnabled(false);
        ui->comboBox_addDelCat->setEnabled(false);
        ui->lineEdit_boxNew->setEnabled(false);
        ui->spinBox_quantityNew->setEnabled(false);
        ui->spinBox_targetQNew->setEnabled(false);
        ui->checkBox_canExpireNew->setEnabled(false);
    }
}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_pushButton_makeReport_clicked()
{
    typedef  bbb::_FileWriter fw;

    // sets the type based on the radio buttons on the Reports Tab
    fw::ReportType type = fw::ReportType::Full;

    if(ui->radioButton_FullR->isChecked())      {type = fw::Full;}
    else if(ui->radioButton_LowR->isChecked())  {type = fw::Low;}
    else if(ui->radioButton_CLowR->isChecked()) {type = fw::Critical;}
    else if(ui->radioButton_ExpR->isChecked())  {type = fw::Expirable;}

    // Uses the combo box to decided what file format to use.
    // _FileWriter will write to a default location.
    // The Default loc should be %desktop%.
    if(ui->comboBox_fileFormat->currentText() == "txt")
    {
        fw::getInstance()->makeTxtInvReport(fullInventory, type);
    }
    else if(ui->comboBox_fileFormat->currentText() == "XML")
    {
        fw::getInstance()->makeXmlInvReport(fullInventory, type);
    }

}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_comboBox_addDel_currentIndexChanged(const QString &arg1)
{
    ui->pushButton_addDelete->setText(arg1);
}
//*********************************************************************************

//*********************************************************************************
void ReportsView::on_pushButton_addDelete_clicked()
{
    if(ui->comboBox_addDel->currentIndex() == 0)
    {
        addItem();
    }
    else if(ui->comboBox_addDel->currentIndex() == 1)
    {
        QMessageBox msgBox;
        msgBox.setText("Are you sure you want to delete this item?\n"
                       "Deleting is not the same as setting the quantity to zero.");
        msgBox.setInformativeText("Do you want to save these changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Discard);
        int ret = msgBox.exec();

        switch (ret)
        {
        case QMessageBox::Save :
            deleteItem();
            break;
        case QMessageBox::Discard :
            break;
        }

    }

    // reset all the fields after query
    ui->lineEdit_boxNew->clear();
    ui->lineEdit_itemNameNew->clear();
    ui->comboBox_addDelCat->setCurrentIndex(0);
    ui->spinBox_quantityNew->setValue(0);
    ui->spinBox_targetQNew->setValue(0);
    ui->checkBox_canExpireNew->setCheckState(Qt::CheckState::Unchecked);

    clearTable();
    initTableInv();
    fillTableInv();

}
//*********************************************************************************

//*********************************************************************************
void ReportsView::addItem()
{
    bbb::Item item;

    item.itemName = ui->lineEdit_itemNameNew->text();
    item.quantity = ui->spinBox_quantityNew->value();
    item.effectiveOnHand = ui->spinBox_targetQNew->value();
    item.category = static_cast<bbb::Category::categoryType>( ui->comboBox_addDelCat->currentIndex() );
    item.canExpire = ui->checkBox_canExpireNew->isChecked();
    item.boxStr = ui->lineEdit_boxNew->text();
    item.dateModified = QDateTime::currentDateTime();
    item.modifiedBy = "sys-add";

    bbb::DbConnect::getInstance()->addNewItem(item);

}
//*********************************************************************************

//*********************************************************************************
void ReportsView::deleteItem()
{
    QString itemName = ui->lineEdit_itemNameNew->text();
    bbb::DbConnect::getInstance()->deleteItem(itemName);
}
//*********************************************************************************
