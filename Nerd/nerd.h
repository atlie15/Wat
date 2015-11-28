#ifndef NERD_H
#define NERD_H

#include <QString>
#include <iostream>
#include <vector>

using namespace std;

class Nerd
{
public:
    Nerd();
    friend void make(vector<Nerd> a);
private:
    QString name;
    char sex;
    int yearBorn;
    int yearDeath;
};

#endif // NERD_H
