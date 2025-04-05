#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radioButtonDefault_clicked();

    void on_radioButtonCustom_clicked();

    void on_pushButton_clicked();

    void on_pushButtonClear_clicked();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionCalculate_triggered();

    void on_actionClear_triggered();

private:
    Ui::MainWindow *ui;
    int64_t _y;
    int64_t _a;
    int64_t _miu;
    int64_t _m;

    double randomGenerator();
};
#endif // MAINWINDOW_H
