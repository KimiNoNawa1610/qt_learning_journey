#include "widget.h"
#include "ui_widget.h"
#include "indicator.h"
#include "watertank.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Indicator * indicator = new Indicator(this);
    WaterTank * waterTank = new WaterTank(this);

    // connect the signals and slots
    connect(waterTank,&WaterTank::normal,indicator,&Indicator::normal);
    connect(waterTank,&WaterTank::danger,indicator,&Indicator::danger);
    connect(waterTank,&WaterTank::warning,indicator,&Indicator::warning);

    ui->horizontalLayout->addWidget(waterTank);
    ui->horizontalLayout->addWidget(indicator);

}

Widget::~Widget()
{
    delete ui;
}
