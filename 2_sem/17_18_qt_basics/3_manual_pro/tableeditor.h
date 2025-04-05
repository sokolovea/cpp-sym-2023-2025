#ifndef TABLEEDITOR_H
#define TABLEEDITOR_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class TableEditor : public QWidget {

public:
    TableEditor(QWidget *parent = nullptr);

private slots:
    void addButtonClicked();
    void deleteButtonClicked();

private:
    QTableWidget *tableWidget;
    QLineEdit *fioLineEdit;
    QLineEdit *ageLineEdit;

    void setupUI();
    void addTableRow(const QString &number, const QString &fio, const QString &age);
};

#endif // TABLEEDITOR_H
