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
    void on_pushButtonDefineRoots_clicked();

    void on_pushButtonStart_clicked();

    void on_action_exit_triggered();

    void on_action_clean_triggered();

    void on_action_about_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
