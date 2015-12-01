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
    Nerd(string newName, string newSex, string newYearBorn, string newYearDeath);
    string getName() const;
    string getGender() const;
    string getYearBorn() const;
    string getYearDeath() const;
    void setName(string n);
    void setGender(string s);
    void setYearBorn(string yB);
    void setYearDeath(string yD);
    friend void insertion_born_desc(vector<Nerd>& ComputerScientists);
    friend void insertion_born_asc(vector<Nerd>& ComputerScientists);
    friend void insertion_name_az(vector<Nerd>& ComputerScientists);
    friend void insertion_name_za(vector<Nerd>& ComputerScientists);
    friend void findNerd(const vector<Nerd> ComputerScientists);
private:
    string name;
    string sex;
    string yearBorn;
    string yearDeath;
};

#endif // NERD_H
