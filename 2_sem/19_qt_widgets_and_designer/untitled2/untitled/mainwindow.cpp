#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <DialogAbout.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExit, &QAction::triggered, this, &QApplication::quit);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::startAbout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startAbout()
{
    DialogAbout* dialogAbout = new DialogAbout();
    dialogAbout->exec();
}
