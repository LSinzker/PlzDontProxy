#include "portresult.h"
#include "ui_portresult.h"

PortResult::PortResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortResult)
{
    ui->setupUi(this);
}

PortResult::~PortResult()
{
    delete ui;
}
