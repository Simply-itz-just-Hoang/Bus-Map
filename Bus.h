#pragma once
#include <iostream>
#include "LList.h"
#include <fstream>
#include <iomanip>
#include "Bus_station.h"

using namespace std;
//class Bus_station {
//	
//	private:
//		string name;
//	public:
//		 Bus_station(string name)
//		{
//			this->name = name;
//		}
//		void getName() 
//		{
//			cout << name;
//		}
//};

class Bus {
private:
	string contact;
	string bsx;
	double price;
	LList <Bus_station*> path;
public:
	Bus(string contact, string bsx, double price)
	{
		this->contact = contact;
		this->bsx = bsx;
		this->price = price;
	}
	void getInfo() {
		cout << "\n==============================";
		cout << "\nContact " << contact;
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
			path.Query(i)->getName();
			cout << "->";
		}
	}
	void add_bus_station(Bus_station* x) 
	{
		path.Addlast(x);
	}
};