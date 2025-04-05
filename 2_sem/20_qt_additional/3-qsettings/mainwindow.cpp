#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSettings settings("SYM", "example_test");

    settings.beginGroup("MySettings");
    QVariant textEditSetting = settings.value("textEdit", ui->textEdit->toPlainText());
    int sliderValue = settings.value("slider", ui->horizontalSlider->value()).toInt();
    settings.endGroup();

    ui->textEdit->setPlainText(textEditSetting.toString());
    ui->horizontalSlider->setValue(sliderValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveButton_clicked()
{
    QSettings settings("SYM", "example_test");
    settings.setValue("/MySettings/textEdit", ui->textEdit->toPlainText());
    settings.setValue("/MySettings/slider", ui->horizontalSlider->value());
}

