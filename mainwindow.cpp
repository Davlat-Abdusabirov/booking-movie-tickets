#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QListWidgetItem>
#include <QDir>

#include "cinemahall.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->dateEdit->setDate(QDate(2024, 8, 27));

    getMoviesFromDb(ui->dateEdit->date());
    addMoviesToListWidget();
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::selectedMovie);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addMoviesToListWidget()
{
    ui->listWidget->setIconSize(QSize(354 * 0.8, 472 * 0.8));

    for(int i = 0; i < nameOfMovie.size(); ++i)
    {
        pitem = new QListWidgetItem(nameOfMovie.at(i) + "\n" + timeOfMovie.at(i), ui->listWidget);

        QString path = QDir::homePath() + "/dev/qt/cinema_booking/img/cache/", extension = ".jpg";

        pitem->setIcon(QPixmap(path + nameOfMovie.at(i) + extension));
    }
}

void MainWindow::selectedMovie(QListWidgetItem *item)
{
    CinemaHall* hall = new CinemaHall(this);
    hall->setWindowTitle(item->text());
    hall->show();
}

void MainWindow::dateChanged(const QDate &date)
{
    getMoviesFromDb(date);
    addMoviesToListWidget();
}

void MainWindow::getMoviesFromDb(const QDate &date)
{
    nameOfMovie << "Harry Potter" << "El Camino" << "Spirited Away" <<
        "Howl's Moving Castle" << "Interstellar" << "Inception";
    timeOfMovie << "12:00" << "23:30" << "9:30" << "19:10" << "22:30" << "10:30";
}

