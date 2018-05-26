#ifndef GEARCENTER_H
#define GEARCENTER_H

#include <QWidget>
#include <QtSvg>
#include <QThread>
#include <QDialogButtonBox>


// for testing
#include <QString>
#include <QFile>
#include <QEvent>
#include "qr/QrInterface.h"
#include "dbconnect.h"

#include "_filewriter.h"


namespace Ui {
class GearCenter;
}

class GearCenter : public QWidget
{
    Q_OBJECT

public:
    explicit GearCenter(QWidget *parent = 0);
    ~GearCenter();

    void initTable();
    
    void clearTable();

private:
    bool itemScanned;
    bool pidScanned;
    uint decCatId;
    uint decIdvId;
private slots:

    void on_pushButton_checkInOut_clicked();

    void on_pushButton_checkinOut_clicked();

    void on_lineEdit_scanCode_returnPressed();

    void on_pushButton_enterCode_clicked();

    void on_comboBox_troopNames_currentIndexChanged(int index);

    void on_pushButton_addNote_clicked();

    void on_toolButton_defaultNoteList_clicked();

private:
    Ui::GearCenter *ui;
};

#endif // GEARCENTER_H
