#include <QCoreApplication>
#include <iostream>

using namespace std;

void printStringInfo(QString& qString);

void updateValue(QString& qString, int& counter) {
    counter += 1;
    qString = "Value = " + QString::number(counter);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str;
    int counter = -1;
    updateValue(str, counter);
    //---
    updateValue(str, counter);
    cout << str.toStdString() << endl;


    return a.exec();
}

void printStringInfo(QString& qString)
{
    cout << "string = " << qString.toStdString() << endl
         << "size = " << qString.size() << endl //length, count
         << "capacity = " << qString.capacity() << endl
         << "isEmpty = " << qString.isEmpty() << endl
         << "isNull = " << qString.isNull() << endl;
}
