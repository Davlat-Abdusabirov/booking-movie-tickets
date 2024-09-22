#ifndef CINEMAHALL_H
#define CINEMAHALL_H

#include <QDialog>

namespace Ui {
class CinemaHall;
}

class CinemaHall : public QDialog
{
    Q_OBJECT

public:
    explicit CinemaHall(QWidget *parent = nullptr);
    ~CinemaHall();

private:
    Ui::CinemaHall *ui;
};

#endif // CINEMAHALL_H
