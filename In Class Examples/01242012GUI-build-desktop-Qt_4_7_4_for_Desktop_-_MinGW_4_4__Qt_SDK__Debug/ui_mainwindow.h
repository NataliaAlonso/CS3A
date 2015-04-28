/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jan 31 12:44:55 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcdNumber;
    QPushButton *One;
    QPushButton *Zero;
    QPushButton *C;
    QPushButton *Equal;
    QPushButton *Plus;
    QPushButton *Minus;
    QPushButton *Divide;
    QPushButton *Times;
    QPushButton *RightParenthesis;
    QPushButton *LeftParenthesis;
    QPushButton *Seven;
    QPushButton *MC;
    QPushButton *Four;
    QPushButton *Two;
    QPushButton *Five;
    QPushButton *Three;
    QPushButton *Six;
    QPushButton *Eight;
    QPushButton *Nine;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(857, 657);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(10, 20, 391, 81));
        One = new QPushButton(centralWidget);
        One->setObjectName(QString::fromUtf8("One"));
        One->setGeometry(QRect(10, 150, 93, 28));
        Zero = new QPushButton(centralWidget);
        Zero->setObjectName(QString::fromUtf8("Zero"));
        Zero->setGeometry(QRect(110, 270, 93, 28));
        C = new QPushButton(centralWidget);
        C->setObjectName(QString::fromUtf8("C"));
        C->setGeometry(QRect(110, 110, 93, 28));
        Equal = new QPushButton(centralWidget);
        Equal->setObjectName(QString::fromUtf8("Equal"));
        Equal->setGeometry(QRect(210, 270, 93, 28));
        Plus = new QPushButton(centralWidget);
        Plus->setObjectName(QString::fromUtf8("Plus"));
        Plus->setGeometry(QRect(310, 270, 93, 28));
        Minus = new QPushButton(centralWidget);
        Minus->setObjectName(QString::fromUtf8("Minus"));
        Minus->setGeometry(QRect(310, 230, 93, 28));
        Divide = new QPushButton(centralWidget);
        Divide->setObjectName(QString::fromUtf8("Divide"));
        Divide->setGeometry(QRect(310, 190, 93, 28));
        Times = new QPushButton(centralWidget);
        Times->setObjectName(QString::fromUtf8("Times"));
        Times->setGeometry(QRect(310, 150, 93, 28));
        RightParenthesis = new QPushButton(centralWidget);
        RightParenthesis->setObjectName(QString::fromUtf8("RightParenthesis"));
        RightParenthesis->setGeometry(QRect(310, 110, 93, 28));
        LeftParenthesis = new QPushButton(centralWidget);
        LeftParenthesis->setObjectName(QString::fromUtf8("LeftParenthesis"));
        LeftParenthesis->setGeometry(QRect(210, 110, 93, 28));
        Seven = new QPushButton(centralWidget);
        Seven->setObjectName(QString::fromUtf8("Seven"));
        Seven->setGeometry(QRect(10, 230, 93, 28));
        MC = new QPushButton(centralWidget);
        MC->setObjectName(QString::fromUtf8("MC"));
        MC->setGeometry(QRect(10, 110, 93, 28));
        Four = new QPushButton(centralWidget);
        Four->setObjectName(QString::fromUtf8("Four"));
        Four->setGeometry(QRect(10, 190, 93, 28));
        Two = new QPushButton(centralWidget);
        Two->setObjectName(QString::fromUtf8("Two"));
        Two->setGeometry(QRect(110, 150, 93, 28));
        Five = new QPushButton(centralWidget);
        Five->setObjectName(QString::fromUtf8("Five"));
        Five->setGeometry(QRect(110, 190, 93, 28));
        Three = new QPushButton(centralWidget);
        Three->setObjectName(QString::fromUtf8("Three"));
        Three->setGeometry(QRect(210, 150, 93, 28));
        Six = new QPushButton(centralWidget);
        Six->setObjectName(QString::fromUtf8("Six"));
        Six->setGeometry(QRect(210, 190, 93, 28));
        Eight = new QPushButton(centralWidget);
        Eight->setObjectName(QString::fromUtf8("Eight"));
        Eight->setGeometry(QRect(110, 230, 93, 28));
        Nine = new QPushButton(centralWidget);
        Nine->setObjectName(QString::fromUtf8("Nine"));
        Nine->setGeometry(QRect(210, 230, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 857, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(C, SIGNAL(pressed()), lcdNumber, SLOT(repaint()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        One->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        Zero->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        C->setText(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        Equal->setText(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        Plus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        Minus->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        Divide->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        Times->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        RightParenthesis->setText(QApplication::translate("MainWindow", ")", 0, QApplication::UnicodeUTF8));
        LeftParenthesis->setText(QApplication::translate("MainWindow", "(", 0, QApplication::UnicodeUTF8));
        Seven->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        MC->setText(QApplication::translate("MainWindow", "MC", 0, QApplication::UnicodeUTF8));
        Four->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        Two->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        Five->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        Three->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        Six->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        Eight->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        Nine->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
