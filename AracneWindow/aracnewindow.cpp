#include "aracnewindow.h"
#include "ui_aracnewindow.h"

AracneWindow::AracneWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AracneWindow)
{
    ui->setupUi(this);
}

AracneWindow::~AracneWindow()
{
    delete ui;
}
