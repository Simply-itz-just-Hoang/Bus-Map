#pragma once
#include "Header.h"
#include "Bus.h"
#include "Bus_station.h"
class Manage_Bus
{
public:
	LList<Bus*> Manage_b; // Quản lý xe buýt
	LList<Bus_station*> Manage_bs;
	int Num_of_B = 0;
	int Num_of_BS = 0;
	void readfile0(string s)
	{
		ifstream fi(s);
		if (!fi.is_open())
		{
			cout << "can't read the file thar record the connections of bus station\n";
		}
		else
		{
			string line;
			char ch1, ch2;
			int dis;
			string k;
			//cout << (int)'A' << " -> " << (int)'Z' << endl; //65 -> 90
			while (getline(fi, line))
			{
				//cout <<line<<" have size is: "<< line.size() << endl;
				ch1 = line[0];
				// 
				Node<Bus_station*>* bs = Manage_bs.head;
				Bus_station* p = new Bus_station(ch1);
				bool Check_exits = false;
				for (int j = 1;j <= Num_of_BS;j++)
				{
					bs = bs->next;
					if (bs->data->label == ch1)
					{
						Check_exits = true;
						p = bs->data;
						break;
					}
				}
				if (!Check_exits)
				{
					Num_of_BS++;
					Manage_bs.Addlast(p);
				}
				//
				int x = line.size(),y;
				for (int i = 1;i < x;i++)
				{
					y = (int)line[i];
					if (65 <= y && y <= 90)
					{
						ch2 = line[i];
						i++;
						//dis để lưu quãng đường
						dis = 0;
						while (line[i] != '|')
						{
							dis = dis * 10 + (int)(line[i] - 48);
							if (i < x) i++;
							else break;
						}
						//cout << ch1 << " connect " << ch2 << " by " << dis << "0m in distance "<<Num_of_BS<< "\n";
						Check_exits = false;
						Node<Bus_station*>* bs = Manage_bs.head;
						for (int j = 1;j <= Num_of_BS;j++)
						{
							bs = bs->next;
							if (bs->data->label == ch2)
							{   
								p->add_path(bs->data, dis);
								Check_exits = true;
								break;
							}
						}
						if(!Check_exits)
						{
							Bus_station* p2 = new Bus_station(ch2);
							Manage_bs.Addlast(p2);
							Num_of_BS++;
							p->add_path(p2, dis);
						}
						//cout << ch1 << " connect " << ch2 << " by " << dis << "0m in distance " << p->Get_num_of_near() << "\n";
					}
				}
			}
		}
	}

	void readfile2(string s)
	{
		ifstream file(s);
		if (!file.is_open())
		{
			cout << "Khong the mo file " << s << endl;
			return;
		}
		string line;
		char ch;
		string k;
		while (getline(file, line))
		{
			stringstream ss(line);
			ch = line[0];
			int vt = 0;
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == '|') vt = i;
			}
			k = line.substr(vt+1, line.length() - vt);
			/*
			bs: list các bus_station
			b:list các bus
			*/
			Node<Bus_station*>* bs = Manage_bs.head;
			for (int i = 1;i <= Num_of_BS;i++)
			{
				bs = bs->next;
				if (bs->data->label == ch)
				{
					bs->data->name = k;
					break;
				}
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
			cout << verticle<<endl;
			//cout << Name << ' ' << bsx << ' ' << verticle << endl;
			Bus* p = new Bus(Name, bsx);
			for (int i = 0; i < verticle.size(); i++)
			{
				Bus_station* p1 = new Bus_station(verticle[i]);
				Node<Bus_station*>* bs = Manage_bs.head;
				for (int j = 1;j <= Num_of_BS;j++)
				{
					bs = bs->next;
					if (bs->data->label == verticle[i]);
					{
						p1= bs->data;
						break;
					}
				}
				//cout << p1->label << " ";
				p->add_bus_station(p1);
				//p1->add_bus(p);
			}
			//cout << endl;
			//p->getInfo();
			Manage_b.Addlast(p);
			Num_of_B++;
		}
	}
	//void out()
	//{
	//	//Manage.print();
	//	
	//	//p->data->getInfo();
	//	Node<Bus*>* p = Manage.head;
	//	p = p->next;
	//	while (p != nullptr)
	//	{
	//		p->data->getInfo();
	//		p->data->print_path();
	//		p = p->next;
	//	}
	//	//Manage.print();
	//}
	///*Bus_station* FInd(char x)
	//{
	//	Bus_station* p=new Bus_station(x);
	//}*/
	///*void print_()
	//{
	//	Bus_station* p = new Bus_station("");
	//	while(p!=NULL)
	//	{
	//		cout << Manage[i]->name << endl;
	//		for (int j = 0; j < Manage[i]->Buses.size(); j++)
	//		{
	//			cout << Manage[i]->Buses[j] << ' ';
	//		}
	//		cout << endl;
	//	}
	//}*/
	void print()
	{
		Node<Bus_station*>* bs = Manage_bs.head;
		int x;
		for (int i = 1;i <= Num_of_BS;i++)
		{
			bs = bs->next;
			x = bs->data->Get_num_of_near();
			cout << bs->data->label << " " << bs->data->name <<" "<<x << endl;
			Node<couble<Bus_station*>>* bsn = bs->data->near.Gethead();
			for (int j = 1;j <= x;j++)
			{
				bsn = bsn->next;
				cout << "    go to " << bsn->data.first->name << " for " << bsn->data.second << "0m distance\n";
			}
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