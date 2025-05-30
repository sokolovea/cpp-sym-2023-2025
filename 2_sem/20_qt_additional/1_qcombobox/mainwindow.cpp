#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_comboBox_currentIndexChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->lineEdit->setText(QString::number(index + 1) + ": " + ui->comboBox->itemText(index));
}


void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}

