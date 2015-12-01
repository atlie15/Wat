#include "nerd.h"
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

