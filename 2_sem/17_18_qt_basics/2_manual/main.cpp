#include <QCoreApplication>
#include <QWidget>
#include <QApplication>
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRandomGenerator>
#include "mybutton.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/icon.ico"));
    QWidget window;
    window.setWindowTitle("Приложение 2");
    window.resize(800, 600);
    QLabel label("Какая-то метка");
    label.setText(label.text() + " для приложения 2");
    label.setParent(&window);
    QLabel labelNumber("0");
    labelNumber.setParent(&window);
    QPushButton buttonInc("Увеличить значение");
    QPushButton buttonDec("Уменьшить значение");
    buttonInc.setParent(&window);
    buttonDec.setParent(&window);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(&buttonDec);
    // buttonDec.resize(200, 40);
    buttonsLayout->addWidget(&buttonInc);


    QVBoxLayout *mainLayout = new QVBoxLayout(&window);
    mainLayout->addWidget(&label, 0, Qt::AlignCenter);
    mainLayout->addWidget(&labelNumber, 0, Qt::AlignHCenter | Qt::AlignVCenter);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->setAlignment(Qt::AlignCenter);


    QObject::connect(&buttonInc, &QPushButton::clicked, [&labelNumber]() {
        labelNumber.setText(QString::number(labelNumber.text().toInt() + 1));
    });

    QObject::connect(&buttonDec, &QPushButton::clicked, [&labelNumber]() {
        labelNumber.setText(QString::number(labelNumber.text().toInt() - 1));
    });


    MyButton button("Бегающая кнопка");
    button.resize(100, 50);
    button.setParent(&window);

    window.show();
    return app.exec();
}
