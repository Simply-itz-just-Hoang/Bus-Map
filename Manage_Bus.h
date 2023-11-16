#pragma once
#include "Header.h"
#include "Bus.h"
#include "Bus_station.h"
class Manage_Bus
{
public:
	LList<Bus*> Manage; // Quản lý tất cả trạm xe buýt
	void readfile2(string s)
	{
		ifstream file(s);
		if (!file.is_open())
		{
			cout << "Khong the mo file " << s << endl;
			return;
		}
		string line;
		char ll;
		string k;
		while (getline(file, line))
		{
			
			stringstream ss(line);
			ll = line[0];
			int vt = 0;
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == '|') vt = i;
			}
			k = line.substr(vt+1, line.length() - vt);
			Node<Bus*>* l = Manage.head;
			l = l->next;
			while (l != nullptr)
			{
				for (int i = 1; i <= l->data->size(); i++)
				{
					if (l->data->Query(i)->label == ll)
					{
						l->data->Query(i)->name = k;
						break;
					}
				}
				l = l->next;
			}
		}
	}
	void readfile1(string s)
	{
		ifstream file(s);
		if (!file.is_open())
		{
			cout << "Khong the mo file " << s << endl;
			return;
		}
		string line;
		string Name;
		string bsx;
		string verticle;
		while (getline(file, line))
		{

			stringstream ss(line);
			getline(ss, Name, '|');
			getline(ss, bsx, '|');
			getline(ss, verticle);
			//cout << Name << ' ' << bsx << ' ' << verticle << endl;
			Bus* p = new Bus(Name, bsx);
			for (int i = 0; i < verticle.length(); i++)
			{
				Bus_station* x = new Bus_station(verticle[i]);
				p->add_bus_station(x);
			}
			//p->getInfo();
			Manage.Addlast(p);
		}
	}
	void out()
	{
		//Manage.print();
		
		//p->data->getInfo();
		Node<Bus*>* p = Manage.head;
		p = p->next;
		while (p != nullptr)
		{
			p->data->getInfo();
			p->data->print_path();
			p = p->next;
		}
		//Manage.print();
	}
	/*Bus_station* FInd(char x)
	{
		Bus_station* p=new Bus_station(x);
	}*/
	/*void print_()
	{
		Bus_station* p = new Bus_station("");
		while(p!=NULL)
		{
			cout << Manage[i]->name << endl;
			for (int j = 0; j < Manage[i]->Buses.size(); j++)
			{
				cout << Manage[i]->Buses[j] << ' ';
			}
			cout << endl;
		}
	}*/
};