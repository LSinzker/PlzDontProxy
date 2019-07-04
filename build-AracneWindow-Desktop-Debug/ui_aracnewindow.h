/********************************************************************************
** Form generated from reading UI file 'aracnewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARACNEWINDOW_H
#define UI_ARACNEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AracneWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AracneWindow)
    {
        if (AracneWindow->objectName().isEmpty())
            AracneWindow->setObjectName(QString::fromUtf8("AracneWindow"));
        AracneWindow->resize(1188, 887);
        centralWidget = new QWidget(AracneWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1040, 0, 105, 39));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(910, 0, 105, 39));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 70, 551, 731));
        plainTextEdit_2 = new QPlainTextEdit(centralWidget);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(590, 70, 561, 731));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 30, 105, 39));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(590, 30, 105, 39));
        AracneWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AracneWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1188, 35));
        AracneWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AracneWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AracneWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AracneWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AracneWindow->setStatusBar(statusBar);

        retranslateUi(AracneWindow);

        QMetaObject::connectSlotsByName(AracneWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AracneWindow)
    {
        AracneWindow->setWindowTitle(QApplication::translate("AracneWindow", "Aracne - PlzDontProxy", nullptr));
        pushButton->setText(QApplication::translate("AracneWindow", "Dump", nullptr));
        pushButton_2->setText(QApplication::translate("AracneWindow", "Spider", nullptr));
        pushButton_3->setText(QApplication::translate("AracneWindow", "Request", nullptr));
        pushButton_4->setText(QApplication::translate("AracneWindow", "Reply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AracneWindow: public Ui_AracneWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARACNEWINDOW_H
