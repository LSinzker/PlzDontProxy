#ifndef PORTRESULT_H
#define PORTRESULT_H

#include <QDialog>

namespace Ui {
class PortResult;
}

class PortResult : public QDialog
{
    Q_OBJECT

public:
    explicit PortResult(QWidget *parent = nullptr);
    ~PortResult();

private:
    Ui::PortResult *ui;
};

#endif // PORTRESULT_H
