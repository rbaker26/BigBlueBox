#ifndef GEARCENTER_H
#define GEARCENTER_H

#include <QWidget>

namespace Ui {
class GearCenter;
}

class GearCenter : public QWidget
{
    Q_OBJECT

public:
    explicit GearCenter(QWidget *parent = 0);
    ~GearCenter();

private slots:
    void on_pushButton_checkInOut_clicked();

private:
    Ui::GearCenter *ui;
};

#endif // GEARCENTER_H
