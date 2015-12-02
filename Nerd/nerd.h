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
    //Constructor
    Nerd(string newName, string newSex, string newYearBorn, string newYearDeath);
    //Initialize constructor
    string getName() const;
    //Returns name
    string getGender() const;
    //Returns gender
    string getYearBorn() const;
    //Returns year born
    string getYearDeath() const;
    //Returns year of death
    void init();
    //Start setup
    void printOutScientists(const vector<Nerd> &ComputerScientists);
    //Prints out Scientists
    void checkOptions(string &number, vector<Nerd> &ComputerScientists);
    //Checks user input
    void addScientistsHeader(string &number, vector<Nerd> &ComputerScientists);
    //Header for the add scientists page
    void pickOptions(string &number, vector<Nerd> &ComputerScientists);
    //Header for the main menu
    void readNerd(vector<Nerd>& ComputerScientists);
    //Reads from the file to the vector
    string checkGender();
    //Checks if gender is valid or not
    string checkYearBorn();
    //Checks if year born is valid or not
    string checkYearDeath(string yearBorn);
    //Checks if year of death is valid or not
    string checkName();
    //Checks if name is valid or not
    void chooseView(vector<Nerd>& ComputerScientists);
    //Header for list page
    void insertion_born_desc(vector<Nerd>& ComputerScientists);
    //Sorts year born in descending order
    void insertion_born_asc(vector<Nerd>& ComputerScientists);
    //Sorts year born in ascending order
    void insertion_name_az(vector<Nerd>& ComputerScientists);
    //Sorts name from A-Z
    void insertion_name_za(vector<Nerd>& ComputerScientists);
    //Sorts name from Z-A
    void findNerd(const vector<Nerd> ComputerScientists);
    //Search for a scientists in the list
    void addNerd(string &number, vector<Nerd> &ComputerScientists);
    //Adds scientists to the list
    void killNerd(const vector<Nerd> ComputerScientists);
    //Removes scientists from the list
private:
    string name;
    string sex;
    string yearBorn;
    string yearDeath;
};

#endif // NERD_H
