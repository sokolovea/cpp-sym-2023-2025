#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleValidator>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QLocale>

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

private:
    Ui::MainWindow *ui;
    QDoubleValidator *myDoubleValidator;

    QRegularExpression myRegExp = QRegularExpression("^\\+\\d{1,2}\\-\\d{3,5}\\-\\d{3}\\-\\d{2}\\-\\d{2}$");
    QRegularExpressionValidator myTelephoneValidator = QRegularExpressionValidator(myRegExp, nullptr);
};
#endif // MAINWINDOW_H
