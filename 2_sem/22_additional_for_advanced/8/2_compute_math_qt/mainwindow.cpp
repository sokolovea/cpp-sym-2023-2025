#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logic.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonDefineRoots_clicked()
{
    this->ui->lineEditA->clear();
    this->ui->lineEditB->clear();
    double a, b, step;
    if (!(this->ui->labelDefineA->text().isEmpty() || this->ui->labelDefineB->text().isEmpty()) || this->ui->labelDefineStep->text().isEmpty())
    {
        a = this->ui->lineEditDefineA->text().toDouble();
        b = this->ui->lineEditDefineB->text().toDouble();
        step = this->ui->lineEditDefineStep->text().toDouble();

        if (!define_root(a, b, step))
        {
            QMessageBox::warning(this, "Предупреждение", "Положительный корень не найден!");
            return;
        }
        this->ui->lineEditA->setText(QString::number(a));
        this->ui->lineEditB->setText(QString::number(b));
    }
}


void MainWindow::on_pushButtonStart_clicked()
{
    double a, b;
    a = this->ui->lineEditA->text().toDouble();
    b = this->ui->lineEditB->text().toDouble();
    double eps = this->ui->lineEditEps->text().toDouble();
    if (eps < 1e-10)
    {
        eps = 1e-10;
    }
    QList<double> dataX;
    QList<double> dataY;

    dataX.append(solve_method_1(a, b, eps));
    dataX.append(solve_method_2(a, b, eps));
    dataX.append(solve_method_3(a, b, eps));
    dataX.append(solve_method_4(a, b, eps));
    dataX.append(solve_method_5(a, b, eps));
    dataX.append(solve_method_6(a, b, eps));

    dataY.append(f(solve_method_1(a, b, eps)));
    dataY.append(f(solve_method_2(a, b, eps)));
    dataY.append(f(solve_method_3(a, b, eps)));
    dataY.append(f(solve_method_4(a, b, eps)));
    dataY.append(f(solve_method_5(a, b, eps)));
    dataY.append(f(solve_method_6(a, b, eps)));

    for (int row = 0; row < 6; ++row)
    {
        QTableWidgetItem *itemX = new QTableWidgetItem(QString::number(dataX[row], 'f', 5));
        QTableWidgetItem *itemY = new QTableWidgetItem(QString::number(dataY[row], 'f', 5));

        ui->tableWidgetResult->setItem(row, 0, itemX);
        ui->tableWidgetResult->setItem(row, 1, itemY);
    }
}


void MainWindow::on_action_exit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_action_clean_triggered()
{
    this->ui->lineEditA->clear();
    this->ui->lineEditB->clear();
    this->ui->lineEditEps->clear();
    this->ui->lineEditDefineA->clear();
    this->ui->lineEditDefineB->clear();
    this->ui->lineEditDefineStep->clear();
}


void MainWindow::on_action_about_triggered()
{
    QString about = "Программа для уточнения корней.";
    about += "<p>Разработчик: Соколов Егор, гр. 143, 2024</p>";

    QMessageBox msgBox(QMessageBox::Information, "О программе", about, QMessageBox::Ok);
    msgBox.exec();
}

