#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QMatrix>
#include <QTransform>
#include <QDebug>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->angle = 0;
    this->shear = 0.0;
    ui->setupUi(this);
    this->scene = new QGraphicsScene(0, 0, 590, 590, ui->graphicsView);
    ui->graphicsView->setScene(this->scene);
    this->transform(this->angle, this->shear);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::transform(int angle, float shear)
{
    QTransform transform;
    transform.shear(0, shear);
    QPixmap p(":/mouse.png");
    p = p.scaled(p.width()/3, p.height()/3, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    p = p.transformed(transform);
    auto item = new QGraphicsPixmapItem(p);
    item->setTransformOriginPoint(p.rect().center());
    item->setRotation(angle);
    item->setPos(ui->graphicsView->width()/2 - p.width()/2, ui->graphicsView->height()/2 - p.height()/2);
    this->scene->clear();
    int width = this->scene->width();
    int height = this->height();
    this->scene->addLine(width/2, 0, width/2, height, QPen(Qt::black, 5));
    this->scene->addLine(0, height/2, width, height/2, QPen(Qt::black, 5));
    this->scene->addItem(item);
}

void MainWindow::on_AngleSlider_valueChanged(int value)
{
    this->angle = value;
    ui->AngleLabel->setText(QString::number(value)+"°");
    this->transform(this->angle, this->shear);
}



void MainWindow::on_ShearSlider_valueChanged(int value)
{
    this->shear = value/100.0;
    ui->ShearLabel->setText(QString::number(this->shear));
    this->transform(this->angle, this->shear);
}
