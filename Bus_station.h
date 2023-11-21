#pragma once
#include "Header.h"
#include "LListCouble.h"
using namespace std;

class Bus_station
{
public:
	string name;
	int label;
	LList<string> Buses;
	LListcouble<int> near;
	int Num_of_near = 0;
	int Num_of_bus = 0;
	string times;
	//Bus* bus_cross[];
	
	Bus_station(int Label)
	{
		label = Label;
	}
	void printLabel()
	{
		cout << label <<' ';
	}
	void add_path(int x, int distance)
	{
		near.Addlast(distance, x);
		Num_of_near++;
	}
	int Get_num_of_near()
	{
		return Num_of_near;
	}
	int Get_num_of_bus()
	{
		return Num_of_bus;
	}
	void add_bus(string x)
	{
		Buses.Addlast(x);
	}
	void print_near()
	{
		couble<int> x;
		for (int i = 1; i <= Num_of_near; i++)
		{
			x = near.Query(i);
			cout << name << " -> " << x.first << " : " << x.second << " km\n";
		}
	}
	void print_Buses()
	{
		//cout << name << endl;
		Node<string>* p = Buses.head;
		for (int i = 1; i <= Buses.size; i++)
		{
			p = p->next;
			cout << p->data << " ";
		}
		cout << endl;
	}
	void print_time()
	{
		cout << "Time of bus station now: " << times << endl;
	}
};


