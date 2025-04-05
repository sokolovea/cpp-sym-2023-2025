#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_radioButtonDefault_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButtonDefault_clicked()
{
    ui->doubleSpinBoxY0->setValue(4001);
    ui->doubleSpinBoxA->setValue(16070093);
    ui->doubleSpinBoxMiu->setValue(453816693);
    ui->doubleSpinBoxM->setValue(2147483648LL);

    ui->doubleSpinBoxY0->setEnabled(false);
    ui->doubleSpinBoxA->setEnabled(false);
    ui->doubleSpinBoxMiu->setEnabled(false);
    ui->doubleSpinBoxM->setEnabled(false);
}


void MainWindow::on_radioButtonCustom_clicked()
{
    ui->doubleSpinBoxY0->setEnabled(true);
    ui->doubleSpinBoxA->setEnabled(true);
    ui->doubleSpinBoxMiu->setEnabled(true);
    ui->doubleSpinBoxM->setEnabled(true);
}

//Расчет следующего псевдослучайного числа
double MainWindow::randomGenerator() {
    _y = (_a * _y + _miu) % _m;
    return _y / (double)_m;
}


void MainWindow::on_pushButton_clicked()
{
    //Получение параметров расчета с формы
    _y = (int64_t)ui->doubleSpinBoxY0->value();
    _a = (int64_t)ui->doubleSpinBoxA->value();
    _miu = (int64_t)ui->doubleSpinBoxMiu->value();
    _m = (int64_t)ui->doubleSpinBoxM->value();

    int64_t countValues = (int64_t)ui->doubleSpinBoxCountValues->value();
    int64_t countIntervals = (int64_t)ui->doubleSpinBoxCountIntervals->value();

    //Координаты центров интервалов гистограммы
    QVector<double> intervalsHistogram(countIntervals);
    for (int64_t i = 0; i < countIntervals; i++) {
        intervalsHistogram[i] = (i + 0.5) / (double)countIntervals;
    }

    //Вектор значений случайных чисел
    QVector<double> randomValues(countValues, 0);

    //Вектор кол-ва чисел, попадающих в заданный интервал
    QVector<double> histogramValues(countIntervals);

    for (int64_t i = 0; i < countValues; i++) {
        double newValue = randomGenerator();
        int64_t section = newValue * countIntervals;
        histogramValues[section]++;
        randomValues[i] = newValue;
    }

    //Нормализация гистограммы
    for (int64_t i = 0; i < countIntervals; i++) {
        histogramValues[i] /= countValues;
    }


    //Расчет дисперсии, матожидания и начальных моментов

    double M = 0;
    for (int64_t i = 0; i < countValues; i++) {
        M += randomValues[i];
    }
    M /= countValues;
    ui->lineEditM->setText(QString::number(M));

    double D = 0;
    for (int64_t i = 0; i < countValues; i++) {
        D += (randomValues[i] - M) * (randomValues[i] - M);
    }
    D /= countValues;
    ui->lineEditD->setText(QString::number(D));

    double DCorrected = (countValues / (countValues + 1.0) * D);
    ui->lineEditDCorrected->setText(QString::number(DCorrected));

    double moment2 = 0;
    for (int64_t i = 0; i < countValues; i++) {
        moment2 += randomValues[i] * randomValues[i];
    }
    moment2 /= countValues;
    ui->lineEditMoment2->setText(QString::number(moment2));

    double moment3 = 0;
    for (int64_t i = 0; i < countValues; i++) {
        moment3 += randomValues[i] * randomValues[i] * randomValues[i];
    }
    moment3 /= countValues;
    ui->lineEditMoment3->setText(QString::number(moment3));

    //Отрисовка графиков
    QVector<double> intervalsStatisticFunction(countIntervals + 1);
    for (int64_t i = 0; i < countIntervals + 1; i++) {
        intervalsStatisticFunction[i] = i / (double)countIntervals;
    }
    QVector<double> statisticFunctionValues(countIntervals + 1, 0);
    for (int64_t i = 1; i < countIntervals + 1; i++) {
        statisticFunctionValues[i] = statisticFunctionValues[i - 1] + histogramValues[i - 1];
    }


    ui->histogram->clearPlottables();

    QCPGraph *graphHistrogram = ui->histogram->addGraph();
    graphHistrogram->setData(intervalsStatisticFunction, statisticFunctionValues);

    QCPBars *barStatisticFunction = new QCPBars(ui->histogram->xAxis, ui->histogram->yAxis);
    barStatisticFunction->setWidth(1/((double)countIntervals));
    barStatisticFunction->setData(intervalsHistogram, histogramValues);
    barStatisticFunction->setPen(QPen());
    barStatisticFunction->setBrush(QColor(10, 100, 50, 70));


    ui->histogram->rescaleAxes();
    ui->histogram->xAxis->setRange(0, 1);
    ui->histogram->yAxis->setRange(0, 1);


    graphHistrogram->setName("Статистическая функция распределения");

    barStatisticFunction->setName("Нормализованная гистограмма");

    ui->histogram->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);
    ui->histogram->legend->setVisible(true);

    ui->histogram->replot();


}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->histogram->clearGraphs();
    ui->histogram->clearItems();
    ui->histogram->clearMask();
    ui->histogram->clearPlottables();
    ui->histogram->replot();

    ui->lineEditM->clear();
    ui->lineEditD->clear();
    ui->lineEditDCorrected->clear();
    ui->lineEditMoment2->clear();
    ui->lineEditMoment3->clear();
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "О программе", "Лабораторная работа 1. Разработчик - Соколов Егор, гр. 143. Вариант 18.");
}


void MainWindow::on_actionCalculate_triggered()
{
    on_pushButton_clicked();
}


void MainWindow::on_actionClear_triggered()
{
    on_pushButtonClear_clicked();
}

