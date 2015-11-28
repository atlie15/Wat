#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

#include "nerd.h"

using namespace std;

void addScientists(vector<Nerd> &ComputerScientists);
void printOutScientists(const vector<Nerd> &ComputerScientists);
void addNerd();
void pickOptions(int &number);

int main()
{
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
    //cout << "\t name \t" << "sex" << endl;

    for(unsigned int i = 0; i < ComputerScientists.size(); i++)
    {
        cout << "Name: " << ComputerScientists[i].getName() << endl;
        cout << "Sex: " << ComputerScientists[i].getGender() << endl;
        cout << "Year born: " << ComputerScientists[i].getYearBorn() << endl;
        cout << "Year death: " << ComputerScientists[i].getYearDeath() << endl;
    }
}

void addNerd()
{
    string name;
    char sex;
    int yearBorn;
    int yearDeath;
    char ans;

    ofstream ut;

    ut.open("../../nerds.txt", std::ios_base::app);

    do
    {
        cout << "Scientist name: ";
        cin >> name;
        cout << "Gender: ";
        cin >> sex;
        cout << "Born: ";
        cin >> yearBorn;
        cout << "Death: ";
        cin >> yearDeath;

        ut << name << ";";
        ut << sex << ";";
        ut << yearBorn << ";";
        ut << yearDeath << endl;

        cout << "Would you like to input more Nerds (y/n)? ";
        cin >> ans;

    }while(ans == 'y' || ans=='Y');

    ut.close();

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
