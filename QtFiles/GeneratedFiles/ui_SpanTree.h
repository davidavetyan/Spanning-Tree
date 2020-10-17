/********************************************************************************
** Form generated from reading UI file 'SpanTree.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPANTREE_H
#define UI_SPANTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpanTreeClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_3;
    QLabel *label;
    QSpinBox *rowSpinBox;
    QSplitter *splitter_2;
    QLabel *label_2;
    QSpinBox *colSpinBox;
    QSplitter *splitter;
    QLabel *label_3;
    QComboBox *orderComboBox;
    QCheckBox *stCheckBox;
    QWidget *canvasWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SpanTreeClass)
    {
        if (SpanTreeClass->objectName().isEmpty())
            SpanTreeClass->setObjectName(QString::fromUtf8("SpanTreeClass"));
        SpanTreeClass->setWindowModality(Qt::WindowModal);
        SpanTreeClass->resize(826, 637);
        centralWidget = new QWidget(SpanTreeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_3);
        label->setObjectName(QString::fromUtf8("label"));
        splitter_3->addWidget(label);
        rowSpinBox = new QSpinBox(splitter_3);
        rowSpinBox->setObjectName(QString::fromUtf8("rowSpinBox"));
        splitter_3->addWidget(rowSpinBox);

        gridLayout->addWidget(splitter_3, 0, 0, 1, 1);

        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        splitter_2->addWidget(label_2);
        colSpinBox = new QSpinBox(splitter_2);
        colSpinBox->setObjectName(QString::fromUtf8("colSpinBox"));
        splitter_2->addWidget(colSpinBox);

        gridLayout->addWidget(splitter_2, 0, 1, 1, 1);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        splitter->addWidget(label_3);
        orderComboBox = new QComboBox(splitter);
        orderComboBox->setObjectName(QString::fromUtf8("orderComboBox"));
        splitter->addWidget(orderComboBox);

        gridLayout->addWidget(splitter, 0, 2, 1, 1);

        stCheckBox = new QCheckBox(centralWidget);
        stCheckBox->setObjectName(QString::fromUtf8("stCheckBox"));
        stCheckBox->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(stCheckBox, 0, 3, 1, 1);

        canvasWidget = new QWidget(centralWidget);
        canvasWidget->setObjectName(QString::fromUtf8("canvasWidget"));

        gridLayout->addWidget(canvasWidget, 1, 0, 1, 4);

        SpanTreeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SpanTreeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 826, 20));
        SpanTreeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SpanTreeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SpanTreeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SpanTreeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SpanTreeClass->setStatusBar(statusBar);

        retranslateUi(SpanTreeClass);

        QMetaObject::connectSlotsByName(SpanTreeClass);
    } // setupUi

    void retranslateUi(QMainWindow *SpanTreeClass)
    {
        SpanTreeClass->setWindowTitle(QCoreApplication::translate("SpanTreeClass", "SpanTree", nullptr));
        label->setText(QCoreApplication::translate("SpanTreeClass", "Row Count", nullptr));
        label_2->setText(QCoreApplication::translate("SpanTreeClass", "Column Count", nullptr));
        label_3->setText(QCoreApplication::translate("SpanTreeClass", " Order", nullptr));
        stCheckBox->setText(QCoreApplication::translate("SpanTreeClass", "Show Spanning Tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpanTreeClass: public Ui_SpanTreeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPANTREE_H
