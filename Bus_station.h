#pragma once
#include "Header.h"
#include "LListCouble.h"
class Bus_station
{
public:
	string name;
	LListcouble<Bus_station*> near;
	LList<int>Buses;
	int Num_of_near=0;
	int Num_of_bus=0;
	string times;
	string sss;
	//Bus* bus_cross[];
public:
	Bus_station(string Name)
	{
		name = Name;
	}
	void getName() 
	{
		cout << name;
	}
	void add_path(Bus_station* x, int distance)
	{
		near.Addlast(distance, x);
		Num_of_near++;
	}
	void print_near()
	{
		couble<Bus_station*> x;
		for (int i = 1;i <= Num_of_near;i++)
		{
			x = near.Query(i);
			cout << name << " -> " << x.first->name << " : " << x.second << " km\n";
		}
	}
	/*void print_Buses()
	{
		cout << name << endl;
		for (int i = 0; i < Buses.size; i++)
		{
			cout << Buses.Query(i) << ' ';
		}
		cout << endl;
	}*/
	void print_time()
	{
		cout << "Time of bus station now: " << times << endl;
	}
};

