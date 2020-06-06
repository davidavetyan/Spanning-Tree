/********************************************************************************
** Form generated from reading UI file 'SpanTree.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPANTREE_H
#define UI_SPANTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpanTreeClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *canvasWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *colSpinBox;
    QCheckBox *stCheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *rowSpinBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SpanTreeClass)
    {
        if (SpanTreeClass->objectName().isEmpty())
            SpanTreeClass->setObjectName(QStringLiteral("SpanTreeClass"));
        SpanTreeClass->setWindowModality(Qt::WindowModal);
        SpanTreeClass->resize(821, 658);
        centralWidget = new QWidget(SpanTreeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        canvasWidget = new QWidget(centralWidget);
        canvasWidget->setObjectName(QStringLiteral("canvasWidget"));

        gridLayout->addWidget(canvasWidget, 1, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        colSpinBox = new QSpinBox(centralWidget);
        colSpinBox->setObjectName(QStringLiteral("colSpinBox"));

        horizontalLayout_2->addWidget(colSpinBox);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        stCheckBox = new QCheckBox(centralWidget);
        stCheckBox->setObjectName(QStringLiteral("stCheckBox"));
        stCheckBox->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(stCheckBox, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        rowSpinBox = new QSpinBox(centralWidget);
        rowSpinBox->setObjectName(QStringLiteral("rowSpinBox"));

        horizontalLayout->addWidget(rowSpinBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        SpanTreeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SpanTreeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 821, 20));
        SpanTreeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SpanTreeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SpanTreeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SpanTreeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SpanTreeClass->setStatusBar(statusBar);

        retranslateUi(SpanTreeClass);

        QMetaObject::connectSlotsByName(SpanTreeClass);
    } // setupUi

    void retranslateUi(QMainWindow *SpanTreeClass)
    {
        SpanTreeClass->setWindowTitle(QApplication::translate("SpanTreeClass", "SpanTree", nullptr));
        label_2->setText(QApplication::translate("SpanTreeClass", "Column Count", nullptr));
        stCheckBox->setText(QApplication::translate("SpanTreeClass", "Show Spanning Tree", nullptr));
        label->setText(QApplication::translate("SpanTreeClass", "Row Count", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpanTreeClass: public Ui_SpanTreeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPANTREE_H
