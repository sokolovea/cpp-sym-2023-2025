#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogabout.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExit, &QAction::triggered, this,
            &QApplication::quit);

    connect(ui->actionAbout, &QAction::triggered, this,
            &MainWindow::aboutProgram);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aboutProgram()
{
    DialogAbout* dialogAbout = new DialogAbout(this);
    dialogAbout->exec();
}
