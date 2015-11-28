#include <QCoreApplication>
#include <iostream>
#include "nerd.h"
#include <vector>
#include <string>

using namespace std;

void addScientists(vector<Nerd> &ComputerScientists);
void printOutScientists(const vector<Nerd> &ComputerScientists);
void pickOptions(int &number);

int main()
{
    vector<Nerd> ComputerScientists;
    int chooseNumber;
    pickOptions(chooseNumber);



    //addScientists(ComputerScientists);
    //printOutScientists(ComputerScientists);
    cout << endl;
    return 0;
}

void addScientists(vector<Nerd> &ComputerScientists)
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
    for(unsigned int i = 0; i < ComputerScientists.size(); i++)
    {
        cout << "Name: " << ComputerScientists[i].getName() << endl;
        cout << "Sex: " << ComputerScientists[i].getGender() << endl;
        cout << "Year born: " << ComputerScientists[i].getYearBorn() << endl;
        cout << "Year death: " << ComputerScientists[i].getYearDeath() << endl;
    }
}

void pickOptions(int &number)
{
    cout << "Welcome to the Ultimade guide of Computer Scientists!" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "\t1. Show a list of every computer scientists" << endl;
    cout << "\t2. Add computer scientist to the list" << endl;
    cout << "\tPlease select a number: ";
    cin >> number;
}
