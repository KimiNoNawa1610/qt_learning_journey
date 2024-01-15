#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colorpicker.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ColorPicker * colorPicker = new ColorPicker(this);

    connect(colorPicker, &ColorPicker::colorChanged,this,&MainWindow::colorChanged);
    ui->verticalLayout->addWidget(colorPicker);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::colorChanged(QColor newColor)
{
    qDebug()<<"Color Changed to: "<<newColor.name();
}
