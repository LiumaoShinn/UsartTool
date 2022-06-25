#include "dialog.h"
#include "ui_dialog.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //To do
    ComIsOpen = false;
    send16 = false;
    receive16 = false;
    //锁定发送按钮
    ui->btnSend->setEnabled(ComIsOpen);
    //识别系统可用串口号
    QList<QSerialPortInfo> serialPortInfo = QSerialPortInfo::availablePorts();
    int count = serialPortInfo.count();
    //将识别出的串口号添加进Combo Box中
    for(int i = 0;i < count;i++)
    {
        ui->cboxSerialPort->addItem(serialPortInfo.at(i).portName());
    }
    //接收数据
    connect(&mSerialPort,SIGNAL(readyRead()),this,SLOT(on_SerialPort_readyRead()));
    //保存日志
//    connect(ui->btnSave,&QPushButton::clicked,[=](){
//                QFile file("UART_Rec.txt");
//                file.open(QIODevice::Append);
//                //使用QTextStream写入文件
//                QTextStream tsm(&file);
//                tsm<<ui->textEditReceiver->toPlainText();
//                ui->textEditReceiver->clear();
//                file.close();
//                });

}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::getSerialPotConfig()
{
    //获取串口配置
    mPortName = ui->cboxSerialPort->currentText();//串口号
    mBaudRate = ui->cboxBaudrate->currentText();//波特率
    mParity = ui->cboxParity->currentText();//校验位
    mDataBits = ui->cboxDataBits->currentText();//数据位
    mStopBits = ui->cboxStopBits->currentText();//停止位

    //设置串口配置
    //串口号
    mSerialPort.setPortName(mPortName);

    //判断波特率
    if("9600" == mBaudRate)
    {
        mSerialPort.setBaudRate(QSerialPort::Baud9600);
    }
    else if("19200" == mBaudRate)
    {
        mSerialPort.setBaudRate(QSerialPort::Baud19200);
    }
    else
    {
        mSerialPort.setBaudRate(QSerialPort::Baud115200);
    }

    //判断校验位
    if("Space"  == mParity)
    {
        mSerialPort.setParity(QSerialPort::SpaceParity);
    }
    else if("Odd"  == mParity)
    {
        mSerialPort.setParity(QSerialPort::OddParity);
    }
    else if("Even"  == mParity)
    {
        mSerialPort.setParity(QSerialPort::EvenParity);
    }
    else if("Mark"  == mParity)
    {
        mSerialPort.setParity(QSerialPort::MarkParity);
    }
    else
    {
        mSerialPort.setParity(QSerialPort::NoParity);
    }

    //判断数据位
    if("5" == mDataBits)
    {
        mSerialPort.setDataBits(QSerialPort::Data5);
    }
    else if("6" == mDataBits)
    {
        mSerialPort.setDataBits(QSerialPort::Data6);
    }
    else if("7" == mDataBits)
    {
        mSerialPort.setDataBits(QSerialPort::Data7);
    }
    else
    {
        mSerialPort.setDataBits(QSerialPort::Data8);
    }

    //判断停止位
    if("1.5" == mStopBits)
    {
        mSerialPort.setStopBits(QSerialPort::OneAndHalfStop);
    }
    else if("2" == mStopBits)
    {
        mSerialPort.setStopBits(QSerialPort::TwoStop);
    }
    else
    {
        mSerialPort.setStopBits(QSerialPort::OneStop);
    }

    //串口打开结果
    return mSerialPort.open(QSerialPort::ReadWrite);
}

// 打开/关闭串口
void Dialog::on_btnOpen_clicked()
{
    if(ComIsOpen == true)
    {
        //已打开一个串口则执行关闭串口
        mSerialPort.close();
        ui->btnOpen->setText("打开");
        ComIsOpen = false;
        //解锁
        ui->cboxSerialPort->setEnabled(true);
        ui->cboxBaudrate->setEnabled(true);
        ui->cboxParity->setEnabled(true);
        ui->cboxDataBits->setEnabled(true);
        ui->cboxStopBits->setEnabled(true);

        //锁定发送按钮
        ui->btnSend->setEnabled(ComIsOpen);
    }
    else
    {
        //串口没有打开则正常执行
        if(getSerialPotConfig() == true)
        {
            ComIsOpen = true;//成功打开串口
            ui->btnOpen->setText("关闭");//改变按钮文本
            //锁定串口设置
            ui->cboxSerialPort->setEnabled(false);
            ui->cboxBaudrate->setEnabled(false);
            ui->cboxParity->setEnabled(false);
            ui->cboxDataBits->setEnabled(false);
            ui->cboxStopBits->setEnabled(false);

            //解锁发送按钮
            ui->btnSend->setEnabled(ComIsOpen);

        }

    }

}

//发送数据
void Dialog::on_btnSend_clicked()
{
    if(ComIsOpen == true)
    {
        if(send16 == false)//非16进制发送
        {
            //数据写入串口
            mSerialPort.write(ui->textEditSend->toPlainText().toStdString().c_str());
        }
        else //16进制发送
        {

            QString str = ui->textEditSend->toPlainText().toStdString().c_str();
            int len = str.length();
            if(len%2 == 1)   //如果发送的数据个数为奇数的，则在前面最后落单的字符前添加一个字符0
            {
                str = str.insert(len-1,'0'); //insert(int position, const QString & str)
            }
            QByteArray senddata;

            StringToHex(str,senddata);
            mSerialPort.write(senddata);
        }

    }

}
//读串口接收数据
void Dialog::on_SerialPort_readyRead()
{
    if(ComIsOpen == true)
    {
        //读串口
        QByteArray recvData = mSerialPort.readAll();
        if(receive16 == false) //非16进制显示
        {
            //数据显示在文本框中(追加)
            ui->textEditReceiver->append(QString(recvData));
        }
        else //16进制显示
        {
            QDataStream out(&recvData,QIODevice::ReadWrite);
            while(!out.atEnd())
            {
                   qint8 outChar = 0;
                   out>>outChar;   //每字节填充一次，直到结束
                   //十六进制的转换
                   QString str = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));
                   ui->textEditReceiver->insertPlainText(str.toUpper());//大写
                   ui->textEditReceiver->insertPlainText(" ");//每发送两个字符后添加一个空格
                   ui->textEditReceiver->moveCursor(QTextCursor::End);
            }
        }

    }

}

//清除接收区数据
void Dialog::on_btnClean_clicked()
{
    if(ComIsOpen == true)
    {
        ui->textEditReceiver->clear();
    }
}


//判断是非为16进制显示
void Dialog::on_hexReceive_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)//选中
    {
        receive16 = true;
    }
    else
    {
        receive16 = false;
    }
}

//判断是非为16进制发送
void Dialog::on_hexSend_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)//选中
    {
        send16 = true;
    }
    else
    {
       send16 = false;
    }
}


void Dialog::StringToHex(QString str, QByteArray &senddata) //字符串转换为十六进制数据0-F
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;

    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
}

char Dialog::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return ch-ch;//不在0-f范围内的会发送成0
}

//保存日志
void Dialog::on_btnSave_clicked()
{
    QString curPath = QDir::currentPath();//获取系统当前目录
    QString dlgTitle = "另存为一个文件 ";//对话框标题
    QString filter = "文本文件(*.txt);;所有文件(*.*);;h文件(*.h)";//文件过滤器
    QString aFileName = QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);
    if (aFileName.isEmpty())
        return;
    saveTextByIODevice(aFileName); //调用IOdevice保存文本的函数
}
//通过IOdevice实现将文本框内数据输出到文本中保存
bool Dialog::saveTextByIODevice(const QString &aFileName)
{
    QFile aFile(aFileName);
    if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text))//打开文件失败
        return false;
    QString str = ui->textEditReceiver->toPlainText();//读取窗口内的数据，作为字符串
    QByteArray strBytes = str.toUtf8(); //字符串转换为字节数组
    aFile.write(strBytes,strBytes.length());//写入文件
    aFile.close();
    ui->textEditReceiver->clear();//清屏

    return true;
}

//载入日志
void Dialog::on_btnReadLog_clicked()
{
    QString curPath=QDir::currentPath();//获取系统当前目录
    QString dlgTitle="打开文件 "; //对话框标题
    QString filter="文本文件(*.txt);;程序文件(*.h *.cpp);;所有文件(*.*)"; //文件过滤器
    QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);

    if (aFileName.isEmpty())//文件为空
        return;
    openTextByIODevice(aFileName);
}
//通过IOdevice实现将文本内容读取出来加载到界面文本框中
bool Dialog::openTextByIODevice(const QString &aFileName)
{
    QFile aFile(aFileName);
    if (!aFile.exists()) //文件不存在
        return false;
    if (!aFile.open(QIODevice::ReadOnly | QIODevice::Text))//打开文件失败
        return false;
    ui->textEditReceiver->insertPlainText(QString(aFile.readAll()));//数据显示在文本框中
    aFile.close();
    return  true;
}

