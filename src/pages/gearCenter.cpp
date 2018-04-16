#include "gearCenter.h"
#include "ui_gearCenter.h"

GearCenter::GearCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GearCenter)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0); // Set the stacked wgt to the first page



    //ui->lineEdit_scanCode->setFocus();
    ui->lineEdit_scanCode->setInputMask("AAA:HHHH:HHHHHH");
    //ui->lineEdit_scanCode->grabKeyboard();
    //ui->lineEdit_scanCode->
    //ui->lineEdit_scanCode->selectionStart();
    //ui->lineEdit_scanCode->setCursorPosition(0);

    itemScanned = false;
    pidScanned = false;

    // Set and fill the troop combo box
    ui->comboBox_troopNames->addItem("- Choose a Troop -");
    ui->comboBox_troopNames->addItems(bbb::DbConnect::getInstance()->getTroopNames());


    // Set and fill the item health status combo box
    ui->comboBox_itemHealth->addItems(bbb::DbConnect::getInstance()->getGearHealthStatusList());

    // Init Table
    initTable();




}

GearCenter::~GearCenter()
{
    delete ui;
}

void GearCenter::on_pushButton_checkInOut_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void GearCenter::on_pushButton_checkinOut_clicked()
{

    // Start checkin / out procedure
}

void GearCenter::on_lineEdit_scanCode_returnPressed()
{
    ui->pushButton_enterCode->click();
}

void GearCenter::clearTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
}

void GearCenter::initTable()
{
    clearTable();

    QStringList header;
    header << "Note" << "Author" << "Time Stamp";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->horizontalHeader()->resizeSection(0,550);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->setSortingEnabled(false);
}

void GearCenter::on_pushButton_enterCode_clicked()
{
    // Get the scan code from the box
    QString scanCodeString = ui->lineEdit_scanCode->text();

    // Turn the scan code into svg code
    QString svgString = QrInterface::strToSvg(scanCodeString);

    // Get the path to the appdata folder
    // If it doesn't exist, it will make the path
    QString filePath = bbb::_FileWriter::getAndCheckRoamingPath();




    // Choose the correct file based on the first three digit of the scan code
    if(scanCodeString.left(3).toUpper() == "PID")
    {
        filePath.append("/temp/pidQr.svg");

        // Set the pidScanned to true
        pidScanned = true;
    }
    else if(scanCodeString.left(3).toUpper() == "ITM")
    {
        // Send the code to the "item code" UI box.
        ui->lineEdit_itemCode_infoBox->setText(scanCodeString);


        filePath.append("/temp/ItemQr.svg");

        // Set the itemScanned to true
        itemScanned = true;

        //**********************************************************************
        // check to see if item is checked in or not, offer to check item in
        //**********************************************************************
        // check to see if the item is healthly or not. Ask person to check
        // item if it is not healthy.


        // Get sub QString
        QString catIdString = scanCodeString.mid(4,4);
        QString idvIdString = scanCodeString.mid(9,6);

        //qDebug() << scanCodeString;
        //qDebug() << catIdString;
        //qDebug() << idvIdString;

        // QString -> int
        // str_Hex -> int_Dec
        bool ok;
        uint decCatId = catIdString.toUInt(&ok,16);
        uint decIdvId = idvIdString.toUInt(&ok,16);

        //qDebug() << ok << " " << decCatId;
        //qDebug() << ok << " " << decIdvId;


        // Check to see if the item exists
        //
        //

        // Check to see if the item is already checked out
        bool isCheckedOut = bbb::DbConnect::getInstance()->isCheckedOut(decCatId, decIdvId);

//        qDebug() << "Checked in\t" << isCheckedOut;


        //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
        // Fill the notes table widget
        clearTable();
        qDebug() << decCatId << decIdvId;
        QVector<bbb::GearNote> notes = bbb::DbConnect::getInstance()->getGearNotes(decCatId, decIdvId);

        // Init table
        initTable();


        // Fill table
        QVector<bbb::GearNote>::iterator it             = notes.begin();
        const QVector<bbb::GearNote>::iterator EXIT_FLAG =  notes.end();
        int rowCount = 0;

        while(it != EXIT_FLAG)
        {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());

            ui->tableWidget->setItem(rowCount ,0, new QTableWidgetItem(it->noteText));
            ui->tableWidget->setItem(rowCount ,1, new QTableWidgetItem((it->author)));
            ui->tableWidget->setItem(rowCount ,2, new QTableWidgetItem(it->dtMade.toString("yy/MM/dd hh:mm")));

            rowCount++;
            it++;
        }

        //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
        //**********************************************************************

    }
    else
    {
        // Display error for bad scan code
        QMessageBox msg;
        msg.setText("Error: Bad Scan Code    ");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);

        msg.exec();
    }


    // Open the file and write the svg code into it.
    // Then close the file
    QFile file(filePath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream ofs(&file);
    ofs << svgString;
    file.close();

    // Load the svg file into the correct widget frame.
    if(scanCodeString.left(3).toUpper() == "PID")
    {
        ui->widget_PidQr->load(filePath);
    }
    else if(scanCodeString.left(3).toUpper() == "ITM")
    {
        ui->widget_itemQr->load(filePath);
    }

    // Clear the scan code line for new imput.
    ui->lineEdit_scanCode->clear();


    // Start Submit Process
    if(itemScanned && pidScanned)
    {
        QMessageBox msg(this);
        msg.setText("Do you want to checkout this item?");
        msg.setInformativeText("Click \"Ok\" or press the \"enter\" key to checkout the item.");
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msg.setDefaultButton(QMessageBox::Ok);
        int ret = msg.exec();

        // Find the path to the blank QrCode
        QString blankPath = bbb::_FileWriter::getAndCheckRoamingPath();
        blankPath.append("/temp/blankQr.svg");
        if (ret == QMessageBox::Ok)
        {
            // Clear the QrCode boxes
            ui->widget_itemQr->load(blankPath);
            ui->widget_PidQr->load(blankPath);

            // Un-set the scanned bools
            pidScanned = false;
            itemScanned = false;

            // Clear the item info out
            ui->lineEdit_itemCode_infoBox->clear();
            clearTable();
            initTable();
        }
    }

}


void GearCenter::on_comboBox_troopNames_currentIndexChanged(int index)
{
    // This will make sure only the correct patrol names
    //  are displayed when a troop is selected
    // It will use the pk / fk relation in the db to make this happen

    // also, after the second function is called, it should update the bool varibale and the Qr Code.

    ui->comboBox_patrolNames->clear();

    if(ui->comboBox_troopNames->currentIndex() != 0)
    {
        ui->comboBox_patrolNames->addItem("- Choose a Patrol -");
        ui->comboBox_patrolNames->addItems(bbb::DbConnect::getInstance()
                                           ->getPatrolNamesByTroop(index));

    }
    else
    {
        ui->comboBox_patrolNames->clear();
    }
}
