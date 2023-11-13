#pragma once
#include "Header.h"
#include "LList.h"
#include"LListCouble.h"
#include "Bus.h"
#include"Bus_station.h"
using namespace std;

int main()
{
	
	LList<Bus*> buses;
	int n;
	ifstream fi("read/filedoc1.txt");
	//biến tạm
	string st;
	char ch;
	int x;
	if (fi.is_open())
	{
		fi >> n;
		for (int i = 1;i <= n;i++)
		{
			getline(fi, st);
			Bus* bus = new Bus(st);
			fi >> x;
			for (int j = 1;j <= x;j++)
			{
				fi >> ch;

			}

		}
	}
	fi.close();
	ifstream fi("read/filedoc2.txt")
	else
		cout << "file reading is not exist\n";

	cout << "Kien yeu Nhi\n";

	//Bus a= Bus("123456789","1234",3);
	////a.getInfo();
	//Bus_station* b = new Bus_station("abb");
	//Bus_station* c = new Bus_station("abc");
	//Bus_station* d = new Bus_station("abd");
	//b->add_path(c, 5);
	//b->add_path(d, 7);
	//b->print_near();
	//a.add_bus_station(b);
	//a.add_bus_station(c);
	//a.add_bus_station(d);
	//a.getInfo();
	//a.print_path();
}


