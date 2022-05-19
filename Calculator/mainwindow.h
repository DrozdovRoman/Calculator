#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ratesdata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ratesdata *inf;

public slots:
    void slot_changetext(QVector<QVector<double>>);

private slots:
    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_plus_2_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
