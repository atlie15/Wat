#include "nerd.h"
#include <QString>
#include <string>
Nerd::Nerd()
{
    sex = ' ';
    yearBorn = 0;
    yearDeath = 0;
}

Nerd::Nerd(string newName, char newSex, int newYearBorn, int newYearDeath)
{
    name = newName;
    sex = newSex;
    yearBorn = newYearBorn;
    yearDeath = newYearDeath;
}

void Nerd::setName(string x)
{
    name = x;
}

void Nerd::setGender(char s){
    sex = s;
}

void Nerd::setYearBorn(int yB)
{
    yearBorn = yB;
}

void Nerd::setYearDeath(int yD)
{
    yearDeath = yD;
}

string Nerd::getName() const
{
    return name;
}

char Nerd::getGender() const
{
    return sex;
}

int Nerd::getYearBorn() const
{
    return yearBorn;
}

int Nerd::getYearDeath() const
{
    return yearDeath;
}

/*
void make(vector<Nerd> a)
{
    char ans('\0');
    int i = 0;
    do
    {
        cout << "Name: ";
        cin >> a[i].name;
        cout << "Gender ('f' for female, 'm' for male): ";
        cin >> a[i].sex;
        cout << "Year of birth: ";
        cin >> a[i].yearBorn;
        cout << "Year of death: ";
        cin >> a[i].yearDeath;


        cout << "Would you like to make another Nerd (y/n)? ";
        cin >> ans;

        i++;
    }
    while (ans == 'Y' || ans == 'y');
}
*/
