#ifndef NERD_H
#define NERD_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

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
    void init();
    void printOutScientists(const vector<Nerd> &ComputerScientists);
    void checkOptions(string &number, vector<Nerd> &ComputerScientists);
    void addScientistsHeader(string &number, vector<Nerd> &ComputerScientists);
    void pickOptions(string &number, vector<Nerd> &ComputerScientists);
    void readNerd(vector<Nerd>& ComputerScientists);
    string checkGender();
    string checkYearBorn();
    string checkYearDeath(string yearBorn);
    string checkName();
    void chooseView(vector<Nerd>& ComputerScientists);
    void insertion_born_desc(vector<Nerd>& ComputerScientists);
    void insertion_born_asc(vector<Nerd>& ComputerScientists);
    void insertion_name_az(vector<Nerd>& ComputerScientists);
    void insertion_name_za(vector<Nerd>& ComputerScientists);
    void findNerd(const vector<Nerd> ComputerScientists);
    void addNerd(string &number, vector<Nerd> &ComputerScientists);
    void killNerd(const vector<Nerd> ComputerScientists);
private:
    string name;
    string sex;
    string yearBorn;
    string yearDeath;
};

#endif // NERD_H
