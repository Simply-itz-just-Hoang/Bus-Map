#pragma once
#include "Header.h"
#include "Bus.h"
#include "Bus_station.h"

class Manage_Bus_station
{
public:
	LList<Bus*> Manage_b; // Quản lý xe buýt
	LList<Bus_station*> Manage_bs;
	int Num_of_B = 0;
	int Num_of_BS = 0;
	//Hàm tìm con trỏ chị vào giá trị x của mảng
	Bus* find_Bus(string name)
	{
		Node<Bus*>* p = Manage_b.head;
		for (int i = 1;i <= Num_of_B;i++)
		{
			p = p->next;
			if (p->data->name == name)
				break;
		}
		return p->data;
	}
	Bus_station* find_Bus_station(int label)
	{
		Node<Bus_station*>* p = Manage_bs.head;
		for (int i = 1;i <= Num_of_BS;i++)
		{
			p = p->next;
			if (p->data->label == label)
				break;
		}
		return p->data;
	}
	//các hàm tạo file
	void Print_bus_infile(string s);
	//các hàm ghi file
	void add_bus(string name, int path[],int n);
	void add_bus_station();

	// các hàm đọc file
	void readfile1(string s)
	{
		ifstream fi(s);
		string line;
		string label,name;
		int x;
		if (!fi.is_open())
		{
			cout << "can't read the file that record the connections of bus station\n";
		}
		else
		{
			while(getline(fi, line))
			{
				stringstream ss(line);
				Num_of_BS++;
				getline(ss, label, '|');
				x = string_to_int(label);
				getline(ss, name, '|');
				Bus_station* p = new Bus_station(x);
				p->name = name;
				//cout << p->label << " " << p->name << endl;
				Manage_bs.Addlast(p);
			}
		}
	}

	void readfile2(string s)
	{
		ifstream fi(s);
		string line;
		if (!fi.is_open())
		{
			cout << "Khong the mo file " << s << endl;
			return;
		}
		while (getline(fi, line))
		{
			string name;
			stringstream ss(line);
			getline(ss, name, '|');
			//cout << name << endl;
			Bus_station* p = find_Bus_station(string_to_int(name));
			string solve;
			while (getline(ss, solve, '|'))
			{
				//cout << "    " << solve << endl;
				stringstream sss(solve);
				string s1, s2;
				getline(sss, s1, ',');
				getline(sss, s2);
				//cout << "  " << s1 << "," << s2 << endl;
				p->add_path(string_to_int(s1), string_to_int(s2));
			}
		}
	}
	void readfile3(string s)
	{
		ifstream fi(s);
		string line;
		if (!fi.is_open())
		{
			cout << "Khong the mo file " << s << endl;
			return;
		}
		while (getline(fi, line))
		{
			string name;
			stringstream ss(line);
			getline(ss, name, '|');
			//cout << name << endl;
			Bus* b = new Bus(name);
			Manage_b.Addlast(b);
			Num_of_B++;
			string node;
			while (getline(ss, node, '|'))
			{
				//cout << node << " ";
				b->add_bus_station(string_to_int(node));
				Bus_station* bs = find_Bus_station(string_to_int(node));
				bs->add_bus(name);
			}
			//cout << endl;
		}
	}
	void print()
	{
		Node<Bus_station*>* bs = Manage_bs.head;
		int x;
		for (int i = 1;i <= Num_of_BS;i++)
		{
			bs = bs->next;
			cout << bs->data->label << " " << bs->data->name << endl;
			bs->data->print_Buses();
			//bs->data->print_near();
		}
		cout << endl;
		Node<Bus*>* b = Manage_b.head;
		for (int i = 1;i <= Num_of_B;i++)
		{
			b = b->next;
			b->data->getInfo();
			b->data->print_path();
		}
	}
};