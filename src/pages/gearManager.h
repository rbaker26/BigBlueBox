#ifndef GEARMANAGER_H
#define GEARMANAGER_H

#include <QWidget>

namespace Ui {
class GearManager;
}

class GearManager : public QWidget
{
    Q_OBJECT

public:
    explicit GearManager(QWidget *parent = 0);
    ~GearManager();

private:
    Ui::GearManager *ui;
};

#endif // GEARMANAGER_H
