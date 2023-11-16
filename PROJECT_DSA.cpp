#include "Header.h"
#include "Manage_Bus.h"
int main()
{
    Manage_Bus* a = new Manage_Bus();
    a->readfile1("D:/DAI HOC DUNG HOC DAI/SECOND/DSA/WEEK10/PROJECT_DSA/PROJECT_DSA/filedoc1.txt");
    a->readfile2("D:/DAI HOC DUNG HOC DAI/SECOND/DSA/WEEK10/PROJECT_DSA/PROJECT_DSA/filedoc2.txt");
    a->out();
}

