#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "multigame.h"
#include <QImage>
#include <QPixmap>
#include "singlegame.h"
#include <iostream>
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->widget = new MultiGame(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_pushButton_clicked()
{
    if(ui->widget != NULL)
        delete ui->widget;
    ui->widget = new MultiGame(this);
    ui->widget->setVisible(true);
}

void MainWidget::on_pushButton_2_clicked()
{
    if(ui->widget != NULL)
        delete ui->widget;
    ui->widget = new SingleGame(this);
    ui->widget->setVisible(true);
}
