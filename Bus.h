#pragma once
#include "LList.h"
#include "Header.h"

class Bus {
public:
	string name;
	string bsx;
	double price = 3000;
	LList <int> path;
	Bus(string Name)
	{
		this->name = Name;
	}
	void getInfo() {
		cout << "\n==============================";
		cout << "\nName: " << name;
		cout << "\nBien so: " << bsx;
		cout << "\nPrice: " << price;
		cout << "\nNumbers of bus station that this bus will pass: " << path.size;
		cout << "\n==============================\n";
	}
	int Query(int i)
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
			cout<<path.Query(i)<<"->";
		}
		cout << endl;
	}
	void add_bus_station(int x)
	{
		path.Addlast(x);
	}
};