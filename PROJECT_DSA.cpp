#pragma once
#include "Header.h"
#include "Manage_Bus_station.h"
#include "makefile.h"
int main()
{
    Manage_Bus_station* a = new Manage_Bus_station();
    a->readfile1("read/filedoc2.txt");
    a->readfile2("read/filedoc3.txt");
    a->readfile3("read/filedoc1.txt");
    //a->out();
    a->print();
    return 0;
}

