#include "nerd.h"

Nerd::Nerd()
{
    name = "";
    sex = "";
    yearBorn = "";
    yearDeath = "";
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

void Nerd::init()
{
    vector<Nerd> ComputerScientists;
    readNerd(ComputerScientists);

    string chooseNumber = "";

    pickOptions(chooseNumber, ComputerScientists);
}

void Nerd::printOutScientists(const vector<Nerd> &ComputerScientists)
{
    system("CLS");

    cout << "Number\tName                          \t\tGender\t        Year born\tYear death" << endl;
    cout << "\t----------------------------------------------------------------------------------" << endl;

    for(unsigned int i = 0; i < ComputerScientists.size(); i++)
    {
        string name = ComputerScientists[i].getName();
        name.resize(30, '\0');

        string gender = ComputerScientists[i].getGender();
        if(gender == "m" || gender == "M")
        {
            gender = "Male";
        }
        else if(gender == "f" || gender == "F")
        {
            gender = "Female";
        }
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

void Nerd::addNerd(string &number, vector<Nerd> &ComputerScientists)
{
    string name;
    string sex;
    string yearBorn;
    string yearDeath;
    char ans;

    ofstream ut;

    ut.open("../nerds.csv", std::ios_base::app);

    addScientistsHeader(number, ComputerScientists);
    do
    {
        name = checkName();
        sex = checkGender();
        yearBorn = checkYearBorn();
        yearDeath = checkYearDeath(yearBorn);

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
        cin.ignore();

    }while(ans == 'y' || ans=='Y');

    ut.close();

    system("CLS");

    cout << "Redirecting to main menu" << endl;
    cout << endl;

    pickOptions(number, ComputerScientists);
}

void Nerd::pickOptions(string &number, vector<Nerd> &ComputerScientists)
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

void Nerd::checkOptions(string &number, vector<Nerd> &ComputerScientists)
{
    if(number == "1")
    {
            system("CLS");
            chooseView(ComputerScientists);
            cout << endl << "Press Enter to return to main menu.";
            cin.get();
            system("CLS");
            pickOptions(number, ComputerScientists);
    }
    else if(number == "2")
    {
           system("CLS");
           addNerd(number, ComputerScientists);
    }
    else if(number == "3")
    {
        system("CLS");
        killNerd(ComputerScientists);
        ComputerScientists.clear();
        readNerd(ComputerScientists);
        cout << endl << "Press Enter to return to main menu.";
        cin.get();
        system("CLS");
        pickOptions(number, ComputerScientists);
    }
     else if(number == "4")
    {
            system("CLS");
            findNerd(ComputerScientists);
            cout << endl << "Press Enter to continue.";
            cin.get();
            system("CLS");
            pickOptions(number, ComputerScientists);
    }
    else if(number == "9")
    {
            cout << "Program shut down" << endl;
            exit(1);
    }
    else
    {
            system("CLS");
            cout << "Option not found, please enter another number" << endl;
            cout << endl;
            pickOptions(number, ComputerScientists);
    }
}

void Nerd::addScientistsHeader(string &number, vector<Nerd> &ComputerScientists)
{
    string quit;

    cout << "Enter a Scientist" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "\t1. Add Scientist to your list" << endl;
    cout << "\t9. Return to main menu" << endl;
    cout << endl;

    getline(cin, quit);
    if(quit != "1")
    {
        system("CLS");
        cout << "Invalid option, returning you to main menu" << endl << endl;
        pickOptions(number, ComputerScientists);
    }
    system("CLS");
}

void Nerd::readNerd(vector<Nerd>& ComputerScientists)
{
    ifstream read;

    read.open("../nerds.csv");

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

string Nerd::checkGender()
{
    string sex;

    cout << "Gender(m/f): ";
    getline(cin, sex);

    if(sex != "m" && sex != "M" && sex != "f" && sex != "F")
    {
        cout << "Invalid gender, please enter another" << endl;
        return checkGender();
    }

    return sex;
}

string Nerd::checkYearBorn()
{
    string yearBorn;

    cout << "Born: ";
    getline(cin, yearBorn);

    for(unsigned int i = 0; i < yearBorn.size(); i++)
    {
        if(!isdigit(yearBorn[i]))
        {
            cout << "Not a valid year, please enter another" << endl;
            return checkYearBorn();
        }
    }

    int value = atoi(yearBorn.c_str());

    if(value <= 0 ||value >= 2015)
    {
        cout << "Not a valid year, please enter another" << endl;
        return checkYearBorn();
    }

    return yearBorn;
}

void Nerd::insertion_born_desc(vector<Nerd>& ComputerScientists)
{
    cout << "sorting yearBorn: descending " << endl;
    cout << endl;

    for (unsigned int i(0); i<(ComputerScientists.size()-1); i++)
    {
        int j=i;
        Nerd temp;

        while(j>=0 && atoi(ComputerScientists[j].yearBorn.c_str()) > atoi(ComputerScientists[j+1].yearBorn.c_str()))
        {
            temp = ComputerScientists[j];
            ComputerScientists[j] = ComputerScientists[j+1];
            ComputerScientists[j+1] = temp;
            j--;
        }

    }
}

void Nerd::insertion_born_asc(vector<Nerd>& ComputerScientists)
{
    cout << "sorting yearBorn: ascending " << endl;
    cout << endl;

    for (unsigned int i(0); i<(ComputerScientists.size()-1); i++)
    {
        int j=i;
        Nerd temp;

        while(j>=0 && atoi(ComputerScientists[j].yearBorn.c_str()) < atoi(ComputerScientists[j+1].yearBorn.c_str()))
        {
            temp = ComputerScientists[j];
            ComputerScientists[j] = ComputerScientists[j+1];
            ComputerScientists[j+1] = temp;
            j--;
        }

    }
}

void Nerd::insertion_name_az(vector<Nerd>& ComputerScientists)
{
    cout << "sorting name: A-Z " << endl;
    cout << endl;

    for (unsigned int i(0); i<(ComputerScientists.size()-1); i++)
    {
        int j=i;
        Nerd temp;

        while(j>=0 && ComputerScientists[j].name > ComputerScientists[j+1].name)
        {
            temp = ComputerScientists[j];
            ComputerScientists[j] = ComputerScientists[j+1];
            ComputerScientists[j+1] = temp;
            j--;
        }
    }
}

void Nerd::insertion_name_za(vector<Nerd>& ComputerScientists)
{
    cout << "sorting name: Z-A " << endl;
    cout << endl;

    for (unsigned int i(0); i<(ComputerScientists.size()-1); i++)
    {
        int j=i;
        Nerd temp;

        while(j>=0 && ComputerScientists[j].name < ComputerScientists[j+1].name)
        {
            temp = ComputerScientists[j];
            ComputerScientists[j] = ComputerScientists[j+1];
            ComputerScientists[j+1] = temp;
            j--;
        }
    }
}

void Nerd::chooseView(vector<Nerd>& ComputerScientists)
{
    string number = "";

    cout << "How would you like to view the list?" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "\t1. Name in alphabetical order [A-Z]" << endl;
    cout << "\t2. Name in alphabetical order [Z-A]" << endl;
    cout << "\t3. Year of birth [descending]" << endl;
    cout << "\t4. Year of birth [ascending]" << endl;
    cout << "\t5. Default" << endl;
    cout << "\t9. Back to main menu." << endl;
    cout << endl;

    cout << "Please select a number: ";
    getline(cin, number);
    cout << endl;

    if (number == "1")
    {
        insertion_name_az(ComputerScientists);
        printOutScientists(ComputerScientists);
    }
    else if(number == "2")
    {
        insertion_name_za(ComputerScientists);
        printOutScientists(ComputerScientists);
    }
    else if(number == "3")
    {
        insertion_born_desc(ComputerScientists);
        printOutScientists(ComputerScientists);
    }
    else if(number == "4")
    {
        insertion_born_asc(ComputerScientists);
        printOutScientists(ComputerScientists);
    }
    else if(number == "5")
    {
        printOutScientists(ComputerScientists);
    }
    else if(number == "9")
    {
        system("CLS");
        pickOptions(number, ComputerScientists);
    }
    else
    {
        system("CLS");
        cout << "You've entered a invalid option, please try again" << endl;
        cout << endl;
        chooseView(ComputerScientists);
    }
}

string Nerd::checkYearDeath(string yearBorn)
{
    string yearDeath;

    cout << "Write \"alive\" if the scientist has not passed away" << endl;
    cout << "Death: ";
    getline(cin, yearDeath);

    if(yearDeath == "alive" || yearDeath == "Alive")
    {
        return yearDeath;
    }
    for(unsigned int i = 0; i < yearDeath.size(); i++)
    {
        if(!isdigit(yearDeath[i]))
        {
            cout << "Not a valid year, please enter another" << endl;
            return checkYearDeath(yearBorn);
        }
    }

    int value = atoi(yearDeath.c_str());
    int yb = atoi(yearBorn.c_str());

    if(value <= 0 ||value >= 2015)
    {
        cout << "Not a valid year, please enter another" << endl;
        return checkYearDeath(yearBorn);
    }

    if(value <= yb)
    {
        cout << "Invalid year, the scientis didn't die before he was born? did he?" << endl;
        return checkYearDeath(yearBorn);
    }

    return yearDeath;
}

string Nerd::checkName()
{
    string name =  "";

    cout << "Scientist name: ";
    getline(cin, name);

    for(unsigned int i = 0; i < name.size(); i++)
    {
        if(isdigit(name[i]))
        {
            cout << "Invalid name, please enter a name without numbers" << endl;
            return checkName();
        }
    }
    return name;
}

void Nerd::findNerd(const vector<Nerd> ComputerScientists)
{
    int counter = 0;
    vector<Nerd> temp;

    cout << "Search a Scientist" << endl;
    cout << "-----------------------------------------------------" << endl;

    string ans;
    cout << "Search for scientist's name: ";
    getline(cin, ans);

    for(unsigned int i(0); i<ComputerScientists.size(); i++)
    {
        std::size_t found = ComputerScientists[i].name.find(ans);

        if (found <= 30)
        {
            temp.push_back(ComputerScientists[i]);
            counter++;
        }
    }

    if(counter == 0)
    {
        cout << endl << "No search resault found" << endl;
    }
    else
    {
        printOutScientists(temp);
    }
}

void Nerd::killNerd(const vector<Nerd> x)
{
    int counter = 0;

    vector<Nerd> ComputerScientists;
    ComputerScientists = x;
    vector<Nerd> temp;

    string ans;
    cout << "Remove a Scientist" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Who would you like to erase ? ";

    getline(cin, ans);

    for(unsigned int i(0); i<ComputerScientists.size(); i++)
    {
        std::size_t found = ComputerScientists[i].name.find(ans);

        if(found < 100)
        {
            temp.push_back(ComputerScientists[i]);
            ComputerScientists.erase(ComputerScientists.begin()+i);
            i--;
            counter++;
        }
    }

    if(counter == 0)
    {
        cout << endl <<"No scientists found, returning you to main menu" << endl;
    }
    else
    {
        cout << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Erasing these nerds." << endl;

        for(unsigned int i(0); i<temp.size(); i++)
        {
            cout << "\t" << temp[i].name << endl;
        }

        cout << "---------------------------------------------" << endl;
        cout << endl;
        cout << "Do you confirm ? (y/n)" << endl;

        string confirmed;
        getline(cin, confirmed);

        if (confirmed == "y")
        {
            ofstream killer;

            killer.open("../nerds.csv");

            for (unsigned int i(0); i<ComputerScientists.size(); i++)
            {
                killer << ComputerScientists[i].name << ";";
                killer << ComputerScientists[i].sex << ";";
                killer << ComputerScientists[i].yearBorn << ";";
                killer << ComputerScientists[i].yearDeath << endl;
            }

            killer.close();
        }
    }
}
