#include <QCoreApplication>
#include <iostream>
#include "nerd.h"
#include <vector>
#include <QString>
#include <QTextStream>
#include <string>

using namespace std;

void fillVector(vector<Nerd> &ComputerScientists);
void printOutScientists(const vector<Nerd> &ComputerScientists);

int main()
{
    vector<Nerd> ComputerScientists;

    fillVector(ComputerScientists);
    printOutScientists(ComputerScientists);
    return 0;
}

void fillVector(vector<Nerd> &ComputerScientists)
{
    string name;
    char sex;
    int yearBorn;
    int yearDeath;

    int size;
    cout << "How many Computer Scientists do you want to add? ";
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        cout << "Scientist name: ";
        cin >> name;
        cout << "Gender: ";
        cin >> sex;
        cout << "Born: ";
        cin >> yearBorn;
        cout << "Death: ";
        cin >> yearDeath;

        Nerd newComputerScientist(name, sex, yearBorn, yearDeath);
        ComputerScientists.push_back(newComputerScientist);
        cout << endl;
    }
}

void printOutScientists(const vector<Nerd> &ComputerScientists)
{
    //cout << "\t name \t" << "sex" << endl;

    for(int i = 0; i < ComputerScientists.size(); i++)
    {
        cout << "Name: " << ComputerScientists[i].getName() << endl;
        cout << "Sex: " << ComputerScientists[i].getGender() << endl;
        cout << "Year born: " << ComputerScientists[i].getYearBorn() << endl;
        cout << "Year death: " << ComputerScientists[i].getYearDeath() << endl;
    }
}
