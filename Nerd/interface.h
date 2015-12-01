#ifndef INTERFACE_H
#define INTERFACE_H

#include "nerd.h"


class interface: private Nerd
{
public:
    interface();
    void pickOptions(string &number, vector<Nerd> &ComputerScientists);
};

#endif // INTERFACE_H
