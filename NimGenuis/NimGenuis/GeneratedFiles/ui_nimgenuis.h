/********************************************************************************
** Form generated from reading UI file 'nimgenuis.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIMGENUIS_H
#define UI_NIMGENUIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NimGenuisClass
{
public:
    QWidget *centralWidget;
    QLabel *label_Log;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QRadioButton *radioTas3;
    QRadioButton *radioTas4;
    QRadioButton *radioTas2;
    QRadioButton *radioTas1;
    QSpinBox *spinMatches;
    QLabel *label_5;
    QPushButton *pushEnlever;
    QLabel *label_scientist;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_tas2;
    QLabel *label_tas3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_tas4;
    QLabel *label;
    QLabel *label_tas1;
    QPushButton *pushGo;
    QPushButton *pushRules;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NimGenuisClass)
    {
        if (NimGenuisClass->objectName().isEmpty())
            NimGenuisClass->setObjectName(QStringLiteral("NimGenuisClass"));
        NimGenuisClass->resize(568, 331);
        centralWidget = new QWidget(NimGenuisClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_Log = new QLabel(centralWidget);
        label_Log->setObjectName(QStringLiteral("label_Log"));
        label_Log->setGeometry(QRect(240, 90, 291, 34));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_Log->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(250, 10, 241, 71));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioTas3 = new QRadioButton(layoutWidget);
        radioTas3->setObjectName(QStringLiteral("radioTas3"));
        radioTas3->setMaximumSize(QSize(50, 25));

        gridLayout_2->addWidget(radioTas3, 0, 4, 1, 1);

        radioTas4 = new QRadioButton(layoutWidget);
        radioTas4->setObjectName(QStringLiteral("radioTas4"));
        radioTas4->setMaximumSize(QSize(50, 25));

        gridLayout_2->addWidget(radioTas4, 0, 5, 1, 1);

        radioTas2 = new QRadioButton(layoutWidget);
        radioTas2->setObjectName(QStringLiteral("radioTas2"));
        radioTas2->setMaximumSize(QSize(50, 25));

        gridLayout_2->addWidget(radioTas2, 0, 3, 1, 1);

        radioTas1 = new QRadioButton(layoutWidget);
        radioTas1->setObjectName(QStringLiteral("radioTas1"));
        radioTas1->setMaximumSize(QSize(50, 25));

        gridLayout_2->addWidget(radioTas1, 0, 2, 1, 1);

        spinMatches = new QSpinBox(layoutWidget);
        spinMatches->setObjectName(QStringLiteral("spinMatches"));
        spinMatches->setMaximumSize(QSize(50, 25));

        gridLayout_2->addWidget(spinMatches, 1, 3, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(50, 25));

        gridLayout_2->addWidget(label_5, 1, 2, 1, 1);

        pushEnlever = new QPushButton(layoutWidget);
        pushEnlever->setObjectName(QStringLiteral("pushEnlever"));
        pushEnlever->setMaximumSize(QSize(50, 25));

        gridLayout_2->addWidget(pushEnlever, 1, 4, 1, 1);

        label_scientist = new QLabel(centralWidget);
        label_scientist->setObjectName(QStringLiteral("label_scientist"));
        label_scientist->setGeometry(QRect(240, 130, 47, 13));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 221, 241));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_tas2 = new QLabel(gridLayoutWidget);
        label_tas2->setObjectName(QStringLiteral("label_tas2"));

        gridLayout->addWidget(label_tas2, 1, 1, 1, 1);

        label_tas3 = new QLabel(gridLayoutWidget);
        label_tas3->setObjectName(QStringLiteral("label_tas3"));

        gridLayout->addWidget(label_tas3, 2, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_tas4 = new QLabel(gridLayoutWidget);
        label_tas4->setObjectName(QStringLiteral("label_tas4"));

        gridLayout->addWidget(label_tas4, 3, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_tas1 = new QLabel(gridLayoutWidget);
        label_tas1->setObjectName(QStringLiteral("label_tas1"));

        gridLayout->addWidget(label_tas1, 0, 1, 1, 1);

        pushGo = new QPushButton(gridLayoutWidget);
        pushGo->setObjectName(QStringLiteral("pushGo"));
        pushGo->setMaximumSize(QSize(100, 16777215));
        pushGo->setLayoutDirection(Qt::LeftToRight);
        pushGo->setFlat(false);

        gridLayout->addWidget(pushGo, 4, 0, 1, 1);

        pushRules = new QPushButton(gridLayoutWidget);
        pushRules->setObjectName(QStringLiteral("pushRules"));

        gridLayout->addWidget(pushRules, 4, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        NimGenuisClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(NimGenuisClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NimGenuisClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NimGenuisClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NimGenuisClass->setStatusBar(statusBar);

        retranslateUi(NimGenuisClass);

        pushGo->setDefault(false);


        QMetaObject::connectSlotsByName(NimGenuisClass);
    } // setupUi

    void retranslateUi(QMainWindow *NimGenuisClass)
    {
        NimGenuisClass->setWindowTitle(QApplication::translate("NimGenuisClass", "NimGenuis", 0));
        label_Log->setText(QApplication::translate("NimGenuisClass", "Salut, lance la partie ou apprend les r\303\251gles le nul !", 0));
        radioTas3->setText(QApplication::translate("NimGenuisClass", "Tas 3", 0));
        radioTas4->setText(QApplication::translate("NimGenuisClass", "Tas 4", 0));
        radioTas2->setText(QApplication::translate("NimGenuisClass", "Tas 2", 0));
        radioTas1->setText(QApplication::translate("NimGenuisClass", "Tas 1", 0));
        label_5->setText(QApplication::translate("NimGenuisClass", "Nombre", 0));
        pushEnlever->setText(QApplication::translate("NimGenuisClass", "Enlever", 0));
        label_scientist->setText(QString());
        label_2->setText(QApplication::translate("NimGenuisClass", "Tas 2", 0));
        label_tas2->setText(QString());
        label_tas3->setText(QString());
        label_3->setText(QApplication::translate("NimGenuisClass", "Tas 3", 0));
        label_4->setText(QApplication::translate("NimGenuisClass", "Tas 4", 0));
        label_tas4->setText(QString());
        label->setText(QApplication::translate("NimGenuisClass", "Tas 1", 0));
        label_tas1->setText(QString());
        pushGo->setText(QApplication::translate("NimGenuisClass", "Lancer la partie", 0));
        pushRules->setText(QApplication::translate("NimGenuisClass", "Comment Jouer ?", 0));
    } // retranslateUi

};

namespace Ui {
    class NimGenuisClass: public Ui_NimGenuisClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIMGENUIS_H
