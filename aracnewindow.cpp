#include "aracnewindow.h"
#include "ui_aracnewindow.h"
#include "AppSocket.hpp"
#include "NetSocket.hpp"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <string>

#define BUF_SIZE 1024*1024

AracneWindow::AracneWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AracneWindow)
{
    ui->setupUi(this);
}

AracneWindow::~AracneWindow()
{
    app.~AppSocket();
    delete ui;
}

void AracneWindow::on_setPort_triggered()
{
    sp = new StartPort(this);
    connect(sp, SIGNAL(setPort(int)), this, SLOT(portSet(int)));
    sp->setModal(false);
    sp->exec();
}

void AracneWindow::portSet(int port) {

    ui->requestText->setPlainText("Starting.");

    sp->close();

    int flag = app.Start(port);
    if(flag == -1){
        QMessageBox::information(this, "Error", "Could not create socket.");
    } else if (flag == -2){
        QMessageBox::information(this, "Error", "Cannot bind to IP/port.");
    } else if (flag == -3) {
        QMessageBox::information(this, "Error", "Cannot listen.");
    }

    memset(buffer, 0, BUF_SIZE);

    listenCall();
}

void AracneWindow::listenCall(){
    app.AcceptCall();
    getRequest();
}

void AracneWindow::getRequest() {
    ui->requestButton->setEnabled(false);
    ui->replyButton->setEnabled(false);
    ui->requestText->clear();

    if(app.ReceiveRequest(buffer, BUF_SIZE) < 5){
        app.AcceptCall();
        app.ReceiveRequest(buffer, BUF_SIZE);
    }

    ui->requestText->setPlainText(buffer);
    ui->replyText->clear();
    ui->requestButton->setEnabled(true);

}

void AracneWindow::sendRequest(HTTPrequest request) {
    ui->requestButton->setEnabled(false);
    ui->replyButton->setEnabled(false);
    answer_size = net.SendRequest(request, buffer, BUF_SIZE);

    ui->replyText->setPlainText(buffer);    // write reply on reply field
    ui->replyButton->setEnabled(true);
    ui->requestButton->setEnabled(true);
}

void AracneWindow::sendReply() {
    ui->replyButton->setEnabled(false);
    ui->requestButton->setEnabled(false);
    app.AnswerRequest(buffer, answer_size);

    getRequest();   //keep listening
}

void AracneWindow::on_requestButton_clicked()
{
    QString requestQStr = (ui->requestText)->toPlainText();
    requestQStr = requestQStr.replace("\n", "\r\n");
    requestQStr = requestQStr.replace("\r\r\n", "\r\n");
    strcpy(buffer, requestQStr.toLocal8Bit().data());
    HTTPrequest request(buffer);
    sendRequest(request);

}

void AracneWindow::on_replyButton_clicked()
{
    QString replyQStr = (ui->replyText)->toPlainText();
    replyQStr = replyQStr.replace("\n", "\r\n");
    replyQStr = replyQStr.replace("\r\r\n", "\r\n");
    strcpy(buffer, replyQStr.toLocal8Bit().data());
    sendReply();

}

void AracneWindow::on_SpiderButton_clicked()
{
    QMessageBox::information(this, "Spider", "Spider tree");
}

void AracneWindow::on_DumpButton_clicked()
{
    QMessageBox::information(this, "Dump", "Dump message");
}


void AracneWindow::on_pushButton_clicked()
{
    ui->~AracneWindow();
}
