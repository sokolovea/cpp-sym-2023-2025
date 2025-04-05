#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
    int counter = 0;
    QLabel* labelCounter;
    void updateCounter(int delta);
private slots:
    void incCounter();
    void decCounter();
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
