#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    qDebug() << "Key pressed:" << key;
    if ((key >= Qt::Key_0 && key <= Qt::Key_9)) {
        ui->lineEditDigits->setText(ui->lineEditDigits->text() + event->text());
    } else if (key == Qt::Key_Backspace) {
        QString qString = ui->lineEditDigits->text();
        qString.chop(1);
        ui->lineEditDigits->setText(qString);
    } else if (key == Qt::Key_Return || key == Qt::Key_Enter) {
        QMessageBox::information(nullptr, "Заголовок", "Текст: Нажат Enter!");
    }
}
