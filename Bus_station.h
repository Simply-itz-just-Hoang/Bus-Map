#pragma once
#include "Header.h"
#include "Bus.h"
#include "LListCouble.h"
class Bus_station
{
public:
	string name;
	char label;
	LListcouble<Bus_station*> near;
	int Num_of_near = 0;
	int Num_of_bus = 0;
	string times;
	//Bus* bus_cross[];
public:
	Bus_station(char Label)
	{
		label = Label;
	}
	void printLabel()
	{
		cout << label <<' ';
	}
	void add_path(Bus_station* x, int distance)
	{
		near.Addlast(distance, x);
		Num_of_near++;
	}
	/*void add_bus(Bus* x)
	{
		Buses.Addlast(x);
	}*/
	/*void print_near()
	{
		couble<Bus_station*> x;
		for (int i = 1; i <= Num_of_near; i++)
		{
			x = near.Query(i);
			cout << name << " -> " << x.first->name << " : " << x.second << " km\n";
		}
	}*/
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


