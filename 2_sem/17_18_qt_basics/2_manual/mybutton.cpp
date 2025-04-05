#include "mybutton.h"
#include <QPushButton>
#include <QRandomGenerator>

MyButton::MyButton(const QString &text, QWidget *parent) : QPushButton(text, parent) {}

void MyButton::enterEvent(QEvent *event) {
    QPushButton::enterEvent(event);
    int newX = QRandomGenerator::global()->bounded(400);
    int newY = QRandomGenerator::global()->bounded(400);
    move(newX, newY);
}
