/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *canvaslayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *penwidthbox;
    QLabel *label_3;
    QComboBox *stylebox;
    QLabel *label_4;
    QComboBox *capbox;
    QLabel *label_5;
    QComboBox *joinbox;
    QLabel *label_6;
    QComboBox *brushbox;
    QCheckBox *checkBox;
    QComboBox *shapebox;
    QCheckBox *checkBox_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        canvaslayout = new QVBoxLayout();
        canvaslayout->setObjectName(QString::fromUtf8("canvaslayout"));

        verticalLayout->addLayout(canvaslayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        penwidthbox = new QSpinBox(Widget);
        penwidthbox->setObjectName(QString::fromUtf8("penwidthbox"));

        gridLayout->addWidget(penwidthbox, 1, 1, 1, 1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        stylebox = new QComboBox(Widget);
        stylebox->setObjectName(QString::fromUtf8("stylebox"));

        gridLayout->addWidget(stylebox, 2, 1, 1, 1);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        capbox = new QComboBox(Widget);
        capbox->setObjectName(QString::fromUtf8("capbox"));

        gridLayout->addWidget(capbox, 3, 1, 1, 1);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        joinbox = new QComboBox(Widget);
        joinbox->setObjectName(QString::fromUtf8("joinbox"));

        gridLayout->addWidget(joinbox, 4, 1, 1, 1);

        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        brushbox = new QComboBox(Widget);
        brushbox->setObjectName(QString::fromUtf8("brushbox"));

        gridLayout->addWidget(brushbox, 5, 1, 1, 1);

        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 6, 0, 1, 2);

        shapebox = new QComboBox(Widget);
        shapebox->setObjectName(QString::fromUtf8("shapebox"));

        gridLayout->addWidget(shapebox, 0, 1, 1, 1);

        checkBox_2 = new QCheckBox(Widget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 7, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Shape", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Pen Width", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Pen Style", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Pen Cap", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Pen Join", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Brush Style", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "Antializing", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "Transform", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
