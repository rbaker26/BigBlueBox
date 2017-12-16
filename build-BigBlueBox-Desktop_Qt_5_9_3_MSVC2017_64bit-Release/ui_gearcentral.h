/********************************************************************************
** Form generated from reading UI file 'gearcentral.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEARCENTRAL_H
#define UI_GEARCENTRAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GearCentral
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *GearCentral)
    {
        if (GearCentral->objectName().isEmpty())
            GearCentral->setObjectName(QStringLiteral("GearCentral"));
        GearCentral->resize(400, 300);
        pushButton = new QPushButton(GearCentral);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 120, 75, 23));

        retranslateUi(GearCentral);

        QMetaObject::connectSlotsByName(GearCentral);
    } // setupUi

    void retranslateUi(QWidget *GearCentral)
    {
        GearCentral->setWindowTitle(QApplication::translate("GearCentral", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GearCentral", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GearCentral: public Ui_GearCentral {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEARCENTRAL_H
