#ifndef STARTPORT_H
#define STARTPORT_H
#include <QDialog>

namespace Ui {
class StartPort;
}

class StartPort : public QDialog
{
    Q_OBJECT

public:
    explicit StartPort(QWidget *parent = nullptr);
    ~StartPort();
    quint16 portNum;

signals:
    void setPort(int portNum);

private slots:
    void on_defaultButton_clicked();

    void on_tryButton_clicked();

    void closeThis();

private:
    Ui::StartPort *ui;
};

#endif // STARTPORT_H
