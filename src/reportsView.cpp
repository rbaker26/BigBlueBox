#include "reportsView.h"
#include "ui_reportsView.h"

ReportsView::ReportsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportsView)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(2);

    ui->tableWidget_inv->clear();
    ui->tableWidget_inv->setRowCount(0);

    initTableInv();
    fillTableInv();
}


ReportsView::~ReportsView()
{
    delete ui;
}


void ReportsView::on_tableWidget_inv_cellDoubleClicked(int row, int column)
{
    ui->toolBox->setCurrentIndex(2);
    QStringList rowData;
    for(int i = 0; i < ui->tableWidget_inv->columnCount(); i++)
    {
        rowData << ui->tableWidget_inv->item(row, i)->text();
    }
    qDebug() << "Row\t" << "Column\t";
    qDebug() << row << "\t" << column;
    qDebug() << rowData;

    sendRowToToolBox(rowData);
}

void ReportsView::sendRowToToolBox(QStringList row)
{
    ui->lineEdit_itemName->setText(row.at(0));
    ui->spinBox_quantity->setValue(QString(row.at(1)).toInt());
    ui->spinBox_targetQ->setValue(QString((row.at(2))).toInt());
    QString catString = Category::categoryToQString(QString(row.at(3)).toInt()-1);
    ui->lineEdit_cat->setText(catString);
    ui->lineEdit_box->setText(row.at(4));

}

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


void ReportsView::fillTableInv()
{
    QVector<Item> inv = DbConnect::getInstance()->getFullInvAsVector();
    QVector<Item>::iterator it = inv.begin();
    const QVector<Item>::iterator EXIT_FLAG = inv.end();

    int rowCount = 0;
    while(it != EXIT_FLAG)
        { // Start While loop
            ui->tableWidget_inv->insertRow(ui->tableWidget_inv->rowCount());

            ui->tableWidget_inv->setItem(rowCount ,0, new QTableWidgetItem(it->itemName));
            ui->tableWidget_inv->setItem(rowCount ,1, new QTableWidgetItem(QString::number((it->quantity))));
            ui->tableWidget_inv->setItem(rowCount ,2, new QTableWidgetItem(QString::number(it->effectiveOnHand)));
            ui->tableWidget_inv->setItem(rowCount ,3, new QTableWidgetItem(QString::number(it->category)));
            ui->tableWidget_inv->setItem(rowCount ,4, new QTableWidgetItem(QString::number(it->boxNum)));
            rowCount++;
            it++;
        }// end while-loop
}
