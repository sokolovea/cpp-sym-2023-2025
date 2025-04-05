#include "widget.h"

#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

void Widget::updateCounter(int delta)
{
    counter += delta;
    labelCounter->setText("Счетчик = " + QString::number(counter));
}

void Widget::incCounter()
{
    updateCounter(1);
}

void Widget::decCounter()
{
    updateCounter(-1);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Учебное приложение");
    setWindowIcon(QIcon(":/images/my_icon.png"));
    setMinimumSize(800, 600);
    resize(800, 600);


    QVBoxLayout* qVBoxLayout = new QVBoxLayout();
    this->setLayout(qVBoxLayout);

    QHBoxLayout* qHBoxLayout = new QHBoxLayout();


    QLabel* info = new QLabel();
    info->setText("Счетчик нажатий на кнопку");
    info->setFont(QFont("MS Gothic", 14));
    info->setAlignment(Qt::AlignmentFlag::AlignCenter);
    // info->move(120, 250);
    // info->setParent(this);
    qVBoxLayout->addWidget(info);

    labelCounter = new QLabel();
    labelCounter->setText("Счетчик = 0");
    labelCounter->setFont(QFont("Calibri", 13));
    // labelCounter->move(350, 300);
    labelCounter->resize(300, 30);
    labelCounter->setAlignment(Qt::AlignmentFlag::AlignCenter);

    qVBoxLayout->addWidget(labelCounter);
    // labelCounter->setParent(this);

    QPushButton* pushButtonInc = new QPushButton();
    pushButtonInc->setText("Увеличить счетчик");
    pushButtonInc->setFont(QFont("Calibri", 13));
    // pushButtonInc->move(315, 350);
    // pushButtonInc->setParent(this);


    QPushButton* pushButtonDec = new QPushButton();
    pushButtonDec->setText("Уменьшить счетчик");
    pushButtonDec->setFont(QFont("Calibri", 13));
    // pushButtonDec->move(510, 350);
    // pushButtonDec->setParent(this);

    qHBoxLayout->addWidget(pushButtonInc);
    qHBoxLayout->addWidget(pushButtonDec);

    qVBoxLayout->addLayout(qHBoxLayout);

    // connect(pushButton, SIGNAL(clicked(bool)), this, SLOT(updateCounter()));
    connect(pushButtonInc, &QPushButton::clicked, this, &Widget::incCounter);
    connect(pushButtonDec, &QPushButton::clicked, this, &Widget::decCounter);

}

Widget::~Widget() {}
