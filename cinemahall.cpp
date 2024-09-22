#include "cinemahall.h"
#include "ui_cinemahall.h"
#include <QPushButton>
#include <QLayout>
#include <QDebug>

CinemaHall::CinemaHall(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CinemaHall)
{
    ui->setupUi(this);
    qDebug() << "CinemaHall";


    QGridLayout* topLeft = new QGridLayout;

    for (int i = 0; i < 10; i++)
    {
        topLeft->addWidget(new QPushButton(), i, 1);
        this->setLayout(topLeft);
    }
}

CinemaHall::~CinemaHall()
{
    delete ui;
}
