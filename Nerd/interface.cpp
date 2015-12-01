#include "interface.h"

interface::interface()
{

}

void interface::pickOptions(string &number, vector<Nerd> &ComputerScientists)
{
    cout << "Welcome to the Ultimade guide of Computer Scientists!" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "\t1. Show a list of every computer scientists" << endl;
    cout << "\t2. Add computer scientist to the list" << endl;
    cout << "\t3. Remove computer scientist from the list" << endl;
    cout << "\t4. Search for scientists in the list" << endl;
    cout << "\t9. Quit program" << endl;
    cout << endl;
    cout << "Please select a number: ";
    getline(cin, number);
    cout << endl;
    checkOptions(number, ComputerScientists);
}
