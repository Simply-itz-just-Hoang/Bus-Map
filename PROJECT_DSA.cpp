#include "Header.h"
#include "Manage_Bus.h"
int main()
{
    Manage_Bus* a = new Manage_Bus();
    a->readfile0("read/filedoc3.txt");
    a->readfile1("read/filedoc1.txt");
    a->readfile2("read/filedoc2.txt");
    //a->out();
    a->print();
}

