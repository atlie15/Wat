#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "nerd.h"

using namespace std;

void printOutScientists(const vector<Nerd> &ComputerScientists);
void checkOptions(int &number, vector<Nerd> &ComputerScientists);
void makeHeader();
void addScientistsHeader(int &number, vector<Nerd> &ComputerScientists);
void addNerd(int &number, vector<Nerd> &ComputerScientists);
void pickOptions(int &number, vector<Nerd> &ComputerScientists);
void readNerd(vector<Nerd>& ComputerScientists);
string checkGender();
string checkYearBorn();
string checkYearDeath();

int main()
{
    vector<Nerd> ComputerScientists;
    readNerd(ComputerScientists);
    int chooseNumber;
    makeHeader();
    pickOptions(chooseNumber, ComputerScientists);
    return 0;
}

void printOutScientists(const vector<Nerd> &ComputerScientists)
{
    system("CLS");
    cout << "Number\tName                          \t\tGender\t        Year born\tYear death" << endl;
    cout << "\t----------------------------------------------------------------------------------" << endl;
    for(unsigned int i = 0; i < ComputerScientists.size(); i++)
    {
        string name = ComputerScientists[i].getName();
        name.resize(30, '\0');
        string gender = ComputerScientists[i].getGender();
        gender.resize(10, '\0');
        string yearBorn = ComputerScientists[i].getYearBorn();
        yearBorn.resize(9, '\0');
        string yearDeath = ComputerScientists[i].getYearDeath();
        yearDeath.resize(10, '\0');
        cout << i + 1 << "\t|";
        cout << " " << name;
        cout << "\t" << gender;
        cout << "\t" << yearBorn;
        cout << "\t" << yearDeath << endl;
    }
}

void addNerd(int &number, vector<Nerd> &ComputerScientists)
{
    string name;
    string sex;
    string yearBorn;
    string yearDeath;
    char ans;

    ofstream ut;

    ut.open("../../nerds.txt", std::ios_base::app);
    addScientistsHeader(number, ComputerScientists);
    do
    {
        cout << "Scientist name: ";
        cin.ignore();
        getline(cin, name);
        sex = checkGender();
        yearBorn = checkYearBorn();
        cout << "hallo" << endl;
        cout << "Death: ";
        getline(cin, yearDeath);

        ut << name << ";";
        ut << sex << ";";
        ut << yearBorn << ";";
        ut << yearDeath << endl;

        Nerd newNerd(name, sex, yearBorn, yearDeath);
        ComputerScientists.push_back(newNerd);

        cout << "\"" << name << "\" has been added to the list" << endl;
        cout << endl;
        cout << "Would you like to input more Nerds (y/n)? ";
        cin >> ans;

    }while(ans == 'y' || ans=='Y');

    ut.close();
    system("CLS");
    cout << "Redirecting to main menu" << endl;
    cout << endl;
    pickOptions(number, ComputerScientists);

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
void makeHeader()
{
    cout << "Welcome to the Ultimade guide of Computer Scientists!" << endl;
    cout << "-----------------------------------------------------" << endl;
}

void pickOptions(int &number, vector<Nerd> &ComputerScientists)
{
    cout << "\t1. Show a list of every computer scientists" << endl;
    cout << "\t2. Add computer scientist to the list" << endl;
    cout << "\t9. Quit program" << endl;
    cout << endl;
    cout << "Please select a number: ";
    cin >> number;
    cout << endl;
    checkOptions(number, ComputerScientists);
}

void checkOptions(int &number, vector<Nerd> &ComputerScientists)
{
    switch(number)
    {
        case 1:
            printOutScientists(ComputerScientists);
            break;
        case 2:
            system("CLS");
            addNerd(number, ComputerScientists);
            break;
        case 9:
            cout << "Program shut down" << endl;
            exit(1);
            break;
        default:
            cout << endl;
            cout << "Option not found, please enter another number" << endl;
            pickOptions(number, ComputerScientists);
    }
}

void addScientistsHeader(int &number, vector<Nerd> &ComputerScientists)
{
    int quit;
    cout << "Enter a Scientist" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "\t1. Add Scientist to your list" << endl;
    cout << "\t9. Return to main menu" << endl;
    cout << endl;

    cin >> quit;
    if(quit != 1)
    {
        system("CLS");
        cout << "Returning you to the main menu" << endl,
        cout << endl;
        pickOptions(number, ComputerScientists);
    }
    system("CLS");
}

void readNerd(vector<Nerd>& ComputerScientists)
{
    ifstream read;

    read.open("../../nerds.txt");

    string x;
    string y;
    string z;
    string a;

    if(read.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    std::string line;

    while(!read.eof())
    {
        while (std::getline(read, line)) // read whole line into line
        {
            std::istringstream iss(line); // string stream
            std::getline(iss, x, ';');
            std::getline(iss, y, ';');
            std::getline(iss, z, ';');
            std::getline(iss, a, ';');

            Nerd pepe(x, y, z, a);

            ComputerScientists.push_back(pepe);
        }
    }
}

string checkGender()
{
    string sex;
    cout << "Gender(m/f): ";
    getline(cin, sex);
    if(sex != "m" && sex != "f")
    {
        cout << "Invalid gender, please enter another" << endl;
        checkGender();
    }

    return sex;
}

string checkYearBorn()
{
    string yearBorn;
    cout << "Born: ";
    getline(cin, yearBorn);
    if(!isdigit(atoi(yearBorn.c_str())))
    {
        cout << "Invalid year, please enter another" << endl;
        checkYearBorn();
    }

    return yearBorn;
}
