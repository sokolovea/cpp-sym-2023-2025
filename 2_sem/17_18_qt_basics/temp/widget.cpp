#include "widget.h"

#include <QHBoxLayout>
#include <QIcon>
#include <QLineEdit>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Мое первое gui приложение");
    setMinimumSize(800, 600);
    setWindowIcon(QIcon(":/image/icon.png"));
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    QPushButton* exit = new QPushButton("Выход");
    mainLayout->addWidget(exit);
    mainLayout->addWidget(exit);
    mainLayout->addWidget(exit);
    // exit->setMaximumSize(150, 50);
    // exit->setContentsMargins(100, 100, 100, 100);
    QLineEdit qLineEdit = new QLineEdit("z")
    // connect(exit, SIGNAL(clicked()), this, SLOT(shutdown()));
    connect(exit, &QPushButton::clicked, this, &QWidget::close);
    exit->setGeometry(1000, 500, 150, 50);

    // exit.setParent(this);

}

Widget::~Widget() {}
