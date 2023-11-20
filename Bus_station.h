#pragma once
#include "Header.h"
#include "LListCouble.h"
#include "Bus.h"

class Bus_station
{
public:
	string name;
	char label;
	LListcouble<Bus_station*> near;
	LList<Bus*> Buses;
	int Num_of_near = 0;
	int Num_of_bus = 0;
	string times;
	//Bus* bus_cross[];
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
	int Get_num_of_near()
	{
		return Num_of_near;
	}
	/*Bus_station* Query(int i)
	{
		couble<Bus_station*>* p = near.head;
		if(i<=Num_of_near)
			for (int j = 1;j <= i;j++)
			{

			}
	}*/
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


