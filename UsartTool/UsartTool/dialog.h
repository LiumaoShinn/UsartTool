#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

public:
    bool getSerialPotConfig(void);

private slots:
    void on_btnOpen_clicked();

    void on_btnSend_clicked();

    void on_SerialPort_readyRead();

    void on_btnClean_clicked();

    void on_hexReceive_stateChanged(int arg1);

    void on_hexSend_stateChanged(int arg1);

    void Dialog::StringToHex(QString str, QByteArray &senddata);

    char Dialog::ConvertHexChar(char ch);

private:
    Ui::Dialog *ui;

    bool ComIsOpen;//串口标志位
    QSerialPort mSerialPort;//类内成员
    QString mPortName;
    QString mBaudRate;
    QString mParity;
    QString mDataBits;
    QString mStopBits;

    bool send16;
    bool receive16;

};
#endif // DIALOG_H
