#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLocale::setDefault(QLocale(QLocale::C));
    myDoubleValidator = new QDoubleValidator(-5000000000000000000.0, 100000000000000000000.0, 10, nullptr);
    this->myDoubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEditDouble->setValidator(this->myDoubleValidator);
    ui->lineEditPhone->setValidator(&this->myTelephoneValidator);

}

MainWindow::~MainWindow()
{
    delete ui;
}

