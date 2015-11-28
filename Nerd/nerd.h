#ifndef NERD_H
#define NERD_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Nerd
{
public:
    Nerd();
    Nerd(string newName, char newSex, int newYearBorn, int newYearDeath);
    string getName() const;
    char getGender() const;
    int getYearBorn() const;
    int getYearDeath() const;
    void setName(string n);
    void setGender(char s);
    void setYearBorn(int yB);
    void setYearDeath(int yD);
private:
    string name;
    char sex;
    int yearBorn;
    int yearDeath;
};

#endif // NERD_H
