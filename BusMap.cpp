#pragma once
#include "Header.h"
#include "LList.h"
#include"LListCouble.h"
#include "Bus.h"
#include"Bus_station.h"
using namespace std;

int main()
{
	
	/*LList<Bus*> buses;
	int n;
	ifstream fi("read/filedoc1.txt");
	if (fi.is_open())
	{
		fi >> n;
	}
	else
		cout << "file reading is not exist\n";*/

	Bus a= Bus("123456789","1234",3);
	//a.getInfo();
	Bus_station* b = new Bus_station("abb");
	Bus_station* c = new Bus_station("abc");
	Bus_station* d = new Bus_station("abd");
	b->add_path(c, 5);
	b->add_path(d, 7);
	b->print_near();
	a.add_bus_station(b);
	a.add_bus_station(c);
	a.add_bus_station(d);
	a.getInfo();
	a.print_path();
}


