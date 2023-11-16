#pragma once
#include "Bus_Station.h"
#include "LList.h"
#include "Header.h"

class Bus {
private:
	string name;
	string bsx;
	double price = 3000;
	LList <Bus_station*> path;
public:
	Bus(string Name, string bsx)
	{
		this->name = Name;
		this->bsx = bsx;
	}
	void getInfo() {
		cout << "\n==============================";
		cout << "\nName: " << name;
		cout << "\nBien so: " << bsx;
		cout << "\nPrice: " << price;
		cout << "\nNumbers of bus station that this bus will pass: " << path.size;
		cout << "\n==============================\n";
	}
	Bus_station* Query(int i)
	{
		return path.Query(i);
	}
	int size()
	{
		return path.size;
	}
	void print_path() {
		for (int i = 1; i <= path.size; i++)
		{
			cout<<path.Query(i)->label <<' '<<path.Query(i)->name<<endl;
			//cout << "->";
		}
	}
	void add_bus_station(Bus_station* x)
	{
		path.Addlast(x);
	}
};