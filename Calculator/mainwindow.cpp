#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDatabase>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int id = QFontDatabase::addApplicationFont(":/resourses/fonts/VenrynSans-Medium.ttf"); // Подключаем шрифт из файла ресурсов.

    inf = new ratesdata;
    connect(inf, &ratesdata::signal, this,  &MainWindow::slot_changetext); // Соединяем сигнал получения данных от сервера со слотом изменения TextLabel
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slot_changetext(QVector<QVector<double>> rate) // Слот изменения TextLabel
{

    ui -> BTC_R -> setText(QString::number(rate[0][ui -> SelectCurrency -> currentIndex()],'g',10) + " " + ui -> SelectCurrency -> currentText());
    ui -> ETH_R -> setText(QString::number(rate[1][ui -> SelectCurrency -> currentIndex()],'g',10) + " " +ui -> SelectCurrency -> currentText());
    ui -> USDT_R -> setText(QString::number(rate[2][ui -> SelectCurrency -> currentIndex()],'g',10) + " " +ui -> SelectCurrency -> currentText());
    ui -> BNB_R -> setText(QString::number(rate[3][ui -> SelectCurrency -> currentIndex()],'g',10) + " " + ui -> SelectCurrency -> currentText());
    ui -> USDC_R -> setText(QString::number(rate[4][ui -> SelectCurrency -> currentIndex()],'g',10) + " " + ui -> SelectCurrency -> currentText());
    ui -> XRP_R -> setText(QString::number(rate[5][ui -> SelectCurrency -> currentIndex()],'g',10) + " " + ui -> SelectCurrency -> currentText());
    ui -> ADA_R -> setText(QString::number(rate[6][ui -> SelectCurrency -> currentIndex()],'g',10) + " " +  ui -> SelectCurrency -> currentText());
    ui -> SOL_R -> setText(QString::number(rate[7][ui -> SelectCurrency -> currentIndex()],'g',10) + " " + ui -> SelectCurrency -> currentText());
    ui -> NEXO_R -> setText(QString::number(rate[8][ui -> SelectCurrency -> currentIndex()],'g',10) + " " + ui -> SelectCurrency -> currentText());
    ui -> NEAR_R -> setText(QString::number(rate[9][ui -> SelectCurrency -> currentIndex()],'g',10) + " " + ui -> SelectCurrency -> currentText());
    ui -> DOT_R -> setText(QString::number(rate[10][ui -> SelectCurrency -> currentIndex()],'g',10) + " " + ui -> SelectCurrency -> currentText());
    ui -> TRX_R -> setText(QString::number(rate[11][ui -> SelectCurrency -> currentIndex()],'g',10) + " " + ui -> SelectCurrency -> currentText());

}


void MainWindow::on_pushButton_plus_clicked() // Слот нажатия на кнопку "+"
{
    double temp_1;
    double temp_2;
    double result;

    if (ui -> comboBox_ResultValue -> currentIndex() < 3) {
        temp_1 = inf -> RateData[ui -> EnterCurrency_1 -> currentIndex()][ui->comboBox_ResultValue->currentIndex()];
        temp_2 = inf -> RateData[ui -> EnterCurrency_2 -> currentIndex()][ui -> comboBox_ResultValue -> currentIndex()];
        result = temp_1 * ui ->EnterCoin_1 -> value() + temp_2 * ui -> EnterCoin_2 -> value();
        ui -> CalculationResult -> setText(QString::number(result,'g',10) + ui -> comboBox_ResultValue -> currentText());
    }
    else {
        temp_1 = inf -> RateData[ui -> EnterCurrency_1 -> currentIndex()][0];
        temp_2 = inf -> RateData[ui -> EnterCurrency_2 -> currentIndex()][0];
        result = (temp_1 * ui -> EnterCoin_1 -> value() + temp_2 * ui -> EnterCoin_2 -> value()) / 
            (inf -> RateData [ ui -> comboBox_ResultValue -> currentIndex() - 3][0]);
        ui -> CalculationResult -> setText(QString::number(result,'g',10) + ui -> comboBox_ResultValue -> currentText());
    }
}


void MainWindow::on_pushButton_minus_clicked() // Слот нажатия на кнопку "-"
{
    double temp_1;
    double temp_2;
    double result;

    if (ui -> comboBox_ResultValue -> currentIndex() < 3) {
        temp_1 = inf -> RateData[ui -> EnterCurrency_1 -> currentIndex()][ui->comboBox_ResultValue->currentIndex()];
        temp_2 = inf -> RateData[ui -> EnterCurrency_2 -> currentIndex()][ui -> comboBox_ResultValue -> currentIndex()];
        result = temp_1 * ui ->EnterCoin_1 -> value() - temp_2 * ui -> EnterCoin_2 -> value();
        ui -> CalculationResult -> setText(QString::number(result,'g',10) + ui -> comboBox_ResultValue -> currentText());
    }
    else {
        temp_1 = inf -> RateData[ui -> EnterCurrency_1 -> currentIndex()][0];
        temp_2 = inf -> RateData[ui -> EnterCurrency_2 -> currentIndex()][0];
        result = (temp_1 * ui -> EnterCoin_1 -> value() - temp_2 * ui -> EnterCoin_2 -> value()) / 
            (inf -> RateData [ ui -> comboBox_ResultValue -> currentIndex() - 3][0]);
        ui -> CalculationResult -> setText(QString::number(result,'g',10) + ui -> comboBox_ResultValue -> currentText());
    }

}


void MainWindow::on_pushButton_multiply_clicked() // Слот нажатия на кнопку "*"
{
    double temp_1;
    double temp_2;
    double result;

    if (ui -> comboBox_ResultValue -> currentIndex() < 3)
    {
        temp_1 = inf -> RateData[ui -> EnterCurrency_1 -> currentIndex()][ui->comboBox_ResultValue->currentIndex()];
        temp_2 = inf -> RateData[ui -> EnterCurrency_2 -> currentIndex()][ui -> comboBox_ResultValue -> currentIndex()];
        result = temp_1 * ui ->EnterCoin_1 -> value() * temp_2 * ui -> EnterCoin_2 -> value();
        ui -> CalculationResult -> setText(QString::number(result,'g',10) + ui -> comboBox_ResultValue -> currentText());
    }
    else
    {
        temp_1 = inf -> RateData[ui -> EnterCurrency_1 -> currentIndex()][0];
        temp_2 = inf -> RateData[ui -> EnterCurrency_2 -> currentIndex()][0];
        result = (ui -> EnterCoin_1 -> value() * ui -> EnterCoin_2 -> value()) * temp_1 * temp_2 / 
            (inf -> RateData [ ui -> comboBox_ResultValue -> currentIndex() - 3][0]);
        ui -> CalculationResult -> setText(QString::number(result,'g',10) + ui -> comboBox_ResultValue -> currentText());
    }

}


void MainWindow::on_pushButton_divide_clicked() // Слот нажатия на кнопку "÷"
{

    double temp_1;
    double temp_2;
    double result;

    if (ui -> comboBox_ResultValue -> currentIndex() < 3) {
        temp_1 = inf -> RateData[ui -> EnterCurrency_1 -> currentIndex()][ui->comboBox_ResultValue->currentIndex()];
        temp_2 = inf -> RateData[ui -> EnterCurrency_2 -> currentIndex()][ui -> comboBox_ResultValue -> currentIndex()];
        if (ui -> EnterCoin_2 -> value() != 0) {
            result = temp_1 * ui ->EnterCoin_1 -> value() / temp_2 * ui -> EnterCoin_2 -> value();
            ui -> CalculationResult -> setText(QString::number(result,'g',10) + ui -> comboBox_ResultValue -> currentText());
        } else {
            ui -> CalculationResult -> setText("Error! Division by 0 is not allowed");
        }
    } else {
        temp_1 = inf -> RateData[ui -> EnterCurrency_1 -> currentIndex()][0];
        temp_2 = inf -> RateData[ui -> EnterCurrency_2 -> currentIndex()][0];
        if (ui -> EnterCoin_2 -> value() != 0) {
            result = (ui -> EnterCoin_1 -> value() * ui -> EnterCoin_2 -> value()) / temp_1 * temp_2 / 
                (inf -> RateData [ ui -> comboBox_ResultValue -> currentIndex() - 3][0]);
            ui -> CalculationResult -> setText(QString::number(result,'g',10) + ui -> comboBox_ResultValue -> currentText());
        }
        else
        {
            ui -> CalculationResult -> setText("Error! Division by 0 is not allowed");
        }
    }
}


void MainWindow::on_pushButton_plus_2_clicked() // Слот нажатия на кнопку очистки данных в калькуляторе
{
    ui -> EnterCoin_1 -> setValue(0);
    ui -> EnterCoin_2 -> setValue(0);
    ui -> CalculationResult -> setText("");
    ui -> EnterCurrency_1 -> setCurrentIndex(0);
    ui -> EnterCurrency_2 -> setCurrentIndex(0);
    ui -> comboBox_ResultValue -> setCurrentIndex(0);
}

