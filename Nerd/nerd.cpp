#include "nerd.h"
#include <QString>
#include <string>
Nerd::Nerd()
{

}

Nerd::Nerd(string newName, string newSex, string newYearBorn, string newYearDeath)
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

void Nerd::setGender(string s){
    sex = s;
}

void Nerd::setYearBorn(string yB)
{
    yearBorn = yB;
}

void Nerd::setYearDeath(string yD)
{
    yearDeath = yD;
}

string Nerd::getName() const
{
    return name;
}

string Nerd::getGender() const
{
    return sex;
}

string Nerd::getYearBorn() const
{
    return yearBorn;
}

string Nerd::getYearDeath() const
{
    return yearDeath;
}

