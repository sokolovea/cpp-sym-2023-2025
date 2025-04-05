#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("SYM");
    QCoreApplication::setOrganizationDomain("example.com");
    QCoreApplication::setApplicationName("example_test");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
