/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *cboxSerialPort;
    QLabel *label_2;
    QComboBox *cboxBaudrate;
    QLabel *label_3;
    QComboBox *cboxParity;
    QLabel *label_4;
    QComboBox *cboxDataBits;
    QLabel *label_5;
    QComboBox *cboxStopBits;
    QPushButton *btnOpen;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QTextEdit *textEditReceiver;
    QTextEdit *textEditSend;
    QPushButton *btnSend;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnClean;
    QCheckBox *hexReceive;
    QCheckBox *hexSend;
    QPushButton *btnReadLog;
    QPushButton *btnSave;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(815, 563);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 171, 301));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cboxSerialPort = new QComboBox(groupBox);
        cboxSerialPort->setObjectName(QString::fromUtf8("cboxSerialPort"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cboxSerialPort);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cboxBaudrate = new QComboBox(groupBox);
        cboxBaudrate->addItem(QString());
        cboxBaudrate->addItem(QString());
        cboxBaudrate->addItem(QString());
        cboxBaudrate->setObjectName(QString::fromUtf8("cboxBaudrate"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cboxBaudrate);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        cboxParity = new QComboBox(groupBox);
        cboxParity->addItem(QString());
        cboxParity->addItem(QString());
        cboxParity->addItem(QString());
        cboxParity->addItem(QString());
        cboxParity->addItem(QString());
        cboxParity->setObjectName(QString::fromUtf8("cboxParity"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cboxParity);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        cboxDataBits = new QComboBox(groupBox);
        cboxDataBits->addItem(QString());
        cboxDataBits->addItem(QString());
        cboxDataBits->addItem(QString());
        cboxDataBits->addItem(QString());
        cboxDataBits->setObjectName(QString::fromUtf8("cboxDataBits"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cboxDataBits);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        cboxStopBits = new QComboBox(groupBox);
        cboxStopBits->addItem(QString());
        cboxStopBits->addItem(QString());
        cboxStopBits->addItem(QString());
        cboxStopBits->setObjectName(QString::fromUtf8("cboxStopBits"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cboxStopBits);

        btnOpen = new QPushButton(groupBox);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));

        formLayout->setWidget(6, QFormLayout::SpanningRole, btnOpen);

        verticalSpacer = new QSpacerItem(17, 131, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(5, QFormLayout::LabelRole, verticalSpacer);

        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(199, 9, 601, 541));
        textEditReceiver = new QTextEdit(groupBox_2);
        textEditReceiver->setObjectName(QString::fromUtf8("textEditReceiver"));
        textEditReceiver->setGeometry(QRect(10, 20, 581, 341));
        textEditSend = new QTextEdit(groupBox_2);
        textEditSend->setObjectName(QString::fromUtf8("textEditSend"));
        textEditSend->setGeometry(QRect(11, 371, 481, 161));
        btnSend = new QPushButton(groupBox_2);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(500, 400, 91, 91));
        groupBox_3 = new QGroupBox(Dialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 310, 171, 241));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 131, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnClean = new QPushButton(layoutWidget);
        btnClean->setObjectName(QString::fromUtf8("btnClean"));

        verticalLayout->addWidget(btnClean);

        hexReceive = new QCheckBox(layoutWidget);
        hexReceive->setObjectName(QString::fromUtf8("hexReceive"));

        verticalLayout->addWidget(hexReceive);

        hexSend = new QCheckBox(layoutWidget);
        hexSend->setObjectName(QString::fromUtf8("hexSend"));

        verticalLayout->addWidget(hexSend);

        btnReadLog = new QPushButton(layoutWidget);
        btnReadLog->setObjectName(QString::fromUtf8("btnReadLog"));

        verticalLayout->addWidget(btnReadLog);

        btnSave = new QPushButton(layoutWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        verticalLayout->addWidget(btnSave);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\344\270\262\345\217\243\345\212\251\346\211\213", nullptr));
        groupBox->setTitle(QApplication::translate("Dialog", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("Dialog", " \344\270\262\345\217\243\345\217\267", nullptr));
        label_2->setText(QApplication::translate("Dialog", " \346\263\242\347\211\271\347\216\207", nullptr));
        cboxBaudrate->setItemText(0, QApplication::translate("Dialog", "9600", nullptr));
        cboxBaudrate->setItemText(1, QApplication::translate("Dialog", "19200", nullptr));
        cboxBaudrate->setItemText(2, QApplication::translate("Dialog", "115200", nullptr));

        label_3->setText(QApplication::translate("Dialog", " \346\240\241\351\252\214\344\275\215", nullptr));
        cboxParity->setItemText(0, QApplication::translate("Dialog", "None", nullptr));
        cboxParity->setItemText(1, QApplication::translate("Dialog", "Odd", nullptr));
        cboxParity->setItemText(2, QApplication::translate("Dialog", "Even", nullptr));
        cboxParity->setItemText(3, QApplication::translate("Dialog", "Mark", nullptr));
        cboxParity->setItemText(4, QApplication::translate("Dialog", "Space", nullptr));

        label_4->setText(QApplication::translate("Dialog", " \346\225\260\346\215\256\344\275\215", nullptr));
        cboxDataBits->setItemText(0, QApplication::translate("Dialog", "8", nullptr));
        cboxDataBits->setItemText(1, QApplication::translate("Dialog", "7", nullptr));
        cboxDataBits->setItemText(2, QApplication::translate("Dialog", "6", nullptr));
        cboxDataBits->setItemText(3, QApplication::translate("Dialog", "5", nullptr));

        label_5->setText(QApplication::translate("Dialog", " \345\201\234\346\255\242\344\275\215", nullptr));
        cboxStopBits->setItemText(0, QApplication::translate("Dialog", "1", nullptr));
        cboxStopBits->setItemText(1, QApplication::translate("Dialog", "1.5", nullptr));
        cboxStopBits->setItemText(2, QApplication::translate("Dialog", "2", nullptr));

        btnOpen->setText(QApplication::translate("Dialog", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        groupBox_2->setTitle(QApplication::translate("Dialog", "\346\225\260\346\215\256\347\252\227\345\217\243", nullptr));
        btnSend->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201", nullptr));
        groupBox_3->setTitle(QApplication::translate("Dialog", "\345\212\237\350\203\275\346\214\211\351\222\256", nullptr));
        btnClean->setText(QApplication::translate("Dialog", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        hexReceive->setText(QApplication::translate("Dialog", "16\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        hexSend->setText(QApplication::translate("Dialog", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        btnReadLog->setText(QApplication::translate("Dialog", "\350\275\275\345\205\245\346\227\245\345\277\227", nullptr));
        btnSave->setText(QApplication::translate("Dialog", "\344\277\235\345\255\230\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
