#ifndef ARACNEWINDOW_H
#define ARACNEWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <cstring>
#include "NetSocket.hpp"
#include "AppSocket.hpp"
#include "startport.h"

namespace Ui {
class AracneWindow;
}

class AracneWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AracneWindow(QWidget *parent = nullptr);
    ~AracneWindow();

public slots:

    void portSet(int port);

private slots:
    void on_requestButton_clicked();

    void on_replyButton_clicked();

    void on_SpiderButton_clicked();

    void on_DumpButton_clicked();

    void on_setPort_triggered();

    void on_pushButton_clicked();

private:
    Ui::AracneWindow *ui;
    AppSocket app;
    NetSocket net;
    char buffer[1024*1024];
    void bindPort();
    void begin(int);
    void listenCall();
    void getRequest();
    void sendRequest(HTTPrequest);
    void sendReply();
    int answer_size;


    StartPort* sp;
};

#endif // ARACNEWINDOW_H
