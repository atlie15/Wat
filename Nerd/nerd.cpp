#include "nerd.h"

Nerd::Nerd()
{
    name = "";
    sex = '\0';
    yearBorn = 0;
    yearDeath = 0;
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
