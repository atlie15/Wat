#include <QCoreApplication>
#include <iostream>
#include "nerd.h"
#include <vector>
#include <QString>
#include <QTextStream>

using namespace std;

int main()
{
    QTextStream qtin(stdin);

    vector<Nerd> ble;

    QString nafn;

    cout << "Enter name : ";
    nafn = qtin.readLine();

    QTextStream(stdout) << "Yo name is: " << nafn << endl;

    return 0;
}

