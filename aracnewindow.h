#ifndef ARACNEWINDOW_H
#define ARACNEWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <cstring>
#include "AppSocket.hpp"
#include "NetSocket.hpp"

namespace Ui {
class AracneWindow;
}

class AracneWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AracneWindow(uint16_t port_number, QWidget *parent = nullptr);
    ~AracneWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AracneWindow *ui;
    AppSocket app;
    NetSocket net;
};

#endif // ARACNEWINDOW_H
