#include "aracnewindow.h"
#include "ui_aracnewindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

AracneWindow::AracneWindow(uint16_t port_number, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AracneWindow)
{
    ui->setupUi(this);
}

AracneWindow::~AracneWindow()
{
    delete ui;
}

void AracneWindow::on_pushButton_clicked()  //SPIDER BUTTON
{
    QMessageBox::information(this, "Spider", "Spider here.");
}

void AracneWindow::on_pushButton_2_clicked()    //DUMP BUTTON
{
    QMessageBox::information(this, "Dump", "Dump here.");
}
