#include "colorpicker.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

ColorPicker::ColorPicker(QWidget *parent): QWidget{parent}
{
    populateColors();
    setupUi();
}

void ColorPicker::colorButtonClicked(int num)
{
    qDebug()<<"Button Color "<<num<<" pushed";
    QString css = QString("background-color:%1").arg(colorList.at(num).name());
    label ->setStyleSheet(css);
    emit colorChanged(colorList[num]);
}

QColor ColorPicker::getColor() const
{
    return color;
}

void ColorPicker::setColor(const QColor &newColor)
{
    color = newColor;
}

void ColorPicker::populateColors()
{
    colorList.append(Qt::red);
    colorList.append(Qt::blue);
    colorList.append(Qt::cyan);
    colorList.append(Qt::darkRed);
    colorList.append(Qt::darkGray);
    colorList.append(Qt::gray);
    colorList.append(Qt::yellow);
    colorList.append(Qt::darkYellow);
}

void ColorPicker::setupUi()
{
    // Creating the layout
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    gridLayout = new QGridLayout();

    // Loop through color_list and create buttons
    for (int i = 0; i < colorList.size(); ++i) {
        QPushButton *button = new QPushButton(colorList.at(i).name(), this);
        button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

        // Set button background color based on colorList
        QString css = QString("background-color:%1").arg(colorList.at(i).name());
        button->setStyleSheet(css);

        // Connect button click signal to a slot (you can customize this)
        // Connect button click signal to a lambda function
        connect(button, &QPushButton::clicked, [this, i]() {
            ColorPicker::colorButtonClicked(i);
        });

        // Add button to the grid layout
        gridLayout->addWidget(button, i / 2, i % 2);  // Adjust layout as needed

    }

    label = new QLabel("Color");
    QString labelCss = QString("background-color:#eeeab6");
    label->setFixedHeight(50);
    label->setStyleSheet(labelCss);

    // Add the grid layout to the main layout
    vlayout->addWidget(label);
    vlayout->addLayout(gridLayout);
}
