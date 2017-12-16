/********************************************************************************
** Form generated from reading UI file 'reportsView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTSVIEW_H
#define UI_REPORTSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportsView
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget_inv;
    QToolBox *toolBox;
    QWidget *toolBoxPage1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QWidget *toolBoxPage2;
    QVBoxLayout *verticalLayout_4;
    QTimeEdit *timeEdit;
    QWidget *page;
    QWidget *toolBoxPage3;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_editItemInfo;
    QLabel *label_4;
    QLineEdit *lineEdit_itemName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_quantity;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBox_targetQ;
    QLineEdit *lineEdit_cat;
    QLineEdit *lineEdit_box;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_edit;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox_editsOn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *ReportsView)
    {
        if (ReportsView->objectName().isEmpty())
            ReportsView->setObjectName(QStringLiteral("ReportsView"));
        ReportsView->resize(1168, 615);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReportsView->sizePolicy().hasHeightForWidth());
        ReportsView->setSizePolicy(sizePolicy);
        ReportsView->setAutoFillBackground(false);
        ReportsView->setStyleSheet(QStringLiteral("font: 8pt \"Segoe UI\";"));
        verticalLayout_3 = new QVBoxLayout(ReportsView);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ReportsView);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QStringLiteral("font: 10pt \"Segoe UI\";"));
        label->setFrameShape(QFrame::NoFrame);
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget_inv = new QTableWidget(ReportsView);
        tableWidget_inv->setObjectName(QStringLiteral("tableWidget_inv"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(11);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget_inv->sizePolicy().hasHeightForWidth());
        tableWidget_inv->setSizePolicy(sizePolicy1);
        tableWidget_inv->setFrameShape(QFrame::Box);
        tableWidget_inv->setFrameShadow(QFrame::Sunken);
        tableWidget_inv->setLineWidth(3);
        tableWidget_inv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_inv->setAlternatingRowColors(true);

        horizontalLayout->addWidget(tableWidget_inv);

        toolBox = new QToolBox(ReportsView);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy2);
        toolBox->setFrameShape(QFrame::Box);
        toolBox->setFrameShadow(QFrame::Raised);
        toolBox->setLineWidth(3);
        toolBoxPage1 = new QWidget();
        toolBoxPage1->setObjectName(QStringLiteral("toolBoxPage1"));
        toolBoxPage1->setGeometry(QRect(0, 0, 232, 450));
        toolBoxPage1->setAcceptDrops(false);
        verticalLayoutWidget = new QWidget(toolBoxPage1);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 201, 31));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(toolBoxPage1);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 150, 82, 17));
        radioButton_2 = new QRadioButton(toolBoxPage1);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(120, 150, 82, 17));
        radioButton_3 = new QRadioButton(toolBoxPage1);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 170, 82, 17));
        toolBox->addItem(toolBoxPage1, QStringLiteral("Filter List"));
        toolBoxPage2 = new QWidget();
        toolBoxPage2->setObjectName(QStringLiteral("toolBoxPage2"));
        toolBoxPage2->setGeometry(QRect(0, 0, 232, 450));
        verticalLayout_4 = new QVBoxLayout(toolBoxPage2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        timeEdit = new QTimeEdit(toolBoxPage2);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        verticalLayout_4->addWidget(timeEdit);

        toolBox->addItem(toolBoxPage2, QStringLiteral("Repots"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        toolBox->addItem(page, QStringLiteral("Add New Item to Inventory"));
        toolBoxPage3 = new QWidget();
        toolBoxPage3->setObjectName(QStringLiteral("toolBoxPage3"));
        toolBoxPage3->setGeometry(QRect(0, 0, 232, 450));
        verticalLayout_5 = new QVBoxLayout(toolBoxPage3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_editItemInfo = new QVBoxLayout();
        verticalLayout_editItemInfo->setObjectName(QStringLiteral("verticalLayout_editItemInfo"));
        verticalLayout_editItemInfo->setSizeConstraint(QLayout::SetNoConstraint);
        label_4 = new QLabel(toolBoxPage3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_editItemInfo->addWidget(label_4);

        lineEdit_itemName = new QLineEdit(toolBoxPage3);
        lineEdit_itemName->setObjectName(QStringLiteral("lineEdit_itemName"));

        verticalLayout_editItemInfo->addWidget(lineEdit_itemName);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(toolBoxPage3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox_quantity = new QSpinBox(toolBoxPage3);
        spinBox_quantity->setObjectName(QStringLiteral("spinBox_quantity"));
        spinBox_quantity->setMaximum(1000);

        horizontalLayout_2->addWidget(spinBox_quantity);


        verticalLayout_editItemInfo->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(toolBoxPage3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBox_targetQ = new QSpinBox(toolBoxPage3);
        spinBox_targetQ->setObjectName(QStringLiteral("spinBox_targetQ"));
        spinBox_targetQ->setMaximum(1000);

        horizontalLayout_3->addWidget(spinBox_targetQ);


        verticalLayout_editItemInfo->addLayout(horizontalLayout_3);

        lineEdit_cat = new QLineEdit(toolBoxPage3);
        lineEdit_cat->setObjectName(QStringLiteral("lineEdit_cat"));

        verticalLayout_editItemInfo->addWidget(lineEdit_cat);

        lineEdit_box = new QLineEdit(toolBoxPage3);
        lineEdit_box->setObjectName(QStringLiteral("lineEdit_box"));

        verticalLayout_editItemInfo->addWidget(lineEdit_box);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_edit = new QPushButton(toolBoxPage3);
        pushButton_edit->setObjectName(QStringLiteral("pushButton_edit"));

        horizontalLayout_4->addWidget(pushButton_edit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_editItemInfo->addLayout(horizontalLayout_4);

        line = new QFrame(toolBoxPage3);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_editItemInfo->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_editItemInfo->addItem(verticalSpacer);

        textBrowser = new QTextBrowser(toolBoxPage3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy3);
        textBrowser->setMaximumSize(QSize(16777215, 75));
        textBrowser->setAutoFillBackground(true);
        textBrowser->setStyleSheet(QStringLiteral("background: transparent;"));
        textBrowser->setFrameShape(QFrame::NoFrame);

        verticalLayout_editItemInfo->addWidget(textBrowser);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        checkBox_editsOn = new QCheckBox(toolBoxPage3);
        checkBox_editsOn->setObjectName(QStringLiteral("checkBox_editsOn"));
        checkBox_editsOn->setCheckable(true);

        horizontalLayout_5->addWidget(checkBox_editsOn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_editItemInfo->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(verticalLayout_editItemInfo);

        toolBox->addItem(toolBoxPage3, QStringLiteral("Adjust Inventory"));

        horizontalLayout->addWidget(toolBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(ReportsView);

        QMetaObject::connectSlotsByName(ReportsView);
    } // setupUi

    void retranslateUi(QWidget *ReportsView)
    {
        ReportsView->setWindowTitle(QApplication::translate("ReportsView", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ReportsView", "Inventory Management Panel", Q_NULLPTR));
        radioButton->setText(QApplication::translate("ReportsView", "Name", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("ReportsView", "RadioButton", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("ReportsView", "RadioButton", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(toolBoxPage1), QApplication::translate("ReportsView", "Filter List", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(toolBoxPage2), QApplication::translate("ReportsView", "Repots", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("ReportsView", "Add New Item to Inventory", Q_NULLPTR));
        label_4->setText(QApplication::translate("ReportsView", "Item Information", Q_NULLPTR));
        lineEdit_itemName->setPlaceholderText(QApplication::translate("ReportsView", "name", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReportsView", "Quantity", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReportsView", "Target", Q_NULLPTR));
        lineEdit_cat->setPlaceholderText(QApplication::translate("ReportsView", "catagory", Q_NULLPTR));
        lineEdit_box->setPlaceholderText(QApplication::translate("ReportsView", "box number", Q_NULLPTR));
        pushButton_edit->setText(QApplication::translate("ReportsView", "Edit", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("ReportsView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; text-decoration: underline;\">Warning</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Editing item information is permanent and cannot be undone.</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Check the below box to enable inventory adjustment.</p></body></html>", Q_NULLPTR));
        checkBox_editsOn->setText(QApplication::translate("ReportsView", "Edits on", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(toolBoxPage3), QApplication::translate("ReportsView", "Adjust Inventory", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportsView: public Ui_ReportsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTSVIEW_H
