#include "startport.h"
#include "ui_startport.h"
#include <QMessageBox>

StartPort::StartPort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartPort)
{
    ui->setupUi(this);
}

StartPort::~StartPort()
{
    delete ui;
}

void StartPort::on_defaultButton_clicked()
{
    portNum = 8228;
    emit setPort(portNum);
    //closeThis();
}

void StartPort::on_tryButton_clicked()
{
    QString portStr = (ui->portText)->toPlainText();
    portNum = portStr.toUShort();
    emit setPort(portNum);
    //closeThis();
}

void StartPort::closeThis() {
    StartPort::close();
}

