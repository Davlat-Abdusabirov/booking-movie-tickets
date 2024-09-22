#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selectedMovie(QListWidgetItem *item);

    void dateChanged(const QDate &date);

private:
    Ui::MainWindow *ui;
    QStringList nameOfMovie;
    QStringList timeOfMovie;
    QListWidgetItem* pitem = 0;

    void addMoviesToListWidget();
    void getMoviesFromDb(const QDate &date);
};
#endif // MAINWINDOW_H
