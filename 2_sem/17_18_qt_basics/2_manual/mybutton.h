#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QPushButton>
#include <QRandomGenerator>

class MyButton : public QPushButton {
public:
    MyButton(const QString &text, QWidget *parent = nullptr);
protected:
    void enterEvent(QEvent *event);
};

#endif // MYBUTTON_H
