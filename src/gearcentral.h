#ifndef GEARCENTRAL_H
#define GEARCENTRAL_H

#include <QWidget>

namespace Ui {
class GearCentral;
}

class GearCentral : public QWidget
{
    Q_OBJECT

public:
    explicit GearCentral(QWidget *parent = 0);
    ~GearCentral();

private:
    Ui::GearCentral *ui;
};

#endif // GEARCENTRAL_H
