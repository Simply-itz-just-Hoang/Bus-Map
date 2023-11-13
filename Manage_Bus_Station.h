#pragma once
#include <iostream>
#include "Header.h"
#include "Bus_station.h"

class Manage_Bus_Station
{
public:
	vector<Bus_station*> Manage;
	vector<vector<int>>manage;
	void addbus_station(Bus_station* x)
	{
		Manage.push_back(x);
	}
	void readfile()
	{
		ifstream file;
		file.open("lib/BUS_STATION_KC.txt");
		if (!file.is_open())
		{
			cout << "Khong the mo file " << endl;
			return;
		}
		string line;
		string NAME;
		string line_find;
		while (getline(file, line))
		{
			stringstream ss(line);
			getline(ss, NAME, ',');
			for (int i = 0; i < Manage.size(); i++)
			{
				if (NAME == Manage[i]->name)
				{
					Manage[i]->sss = line;
				}
			}
		}
		/*for (int i = 0; i < Manage.size(); i++)
		{
			cout << Manage[i]->sss << endl;
		}*/
		
		for (int i = 0; i < Manage.size(); i++)
		{
			int k = 0;
			int x = Manage[i]->sss.find(',');
			//cout << Manage[i]->name << endl;
			for (int j = x + 1; j < Manage[i]->sss.length(); j++)
			{
				
				if (Manage[i]->sss[j] >= '0' && Manage[i]->sss[j] <= '9') k = k * 10 + (int)(Manage[i]->sss[j] - 48);
				if (Manage[i]->sss[j] == ' ')
				{
					//cout << k << ' ';
					Manage[i]->Buses.push_back(k);
					k = 0;
				}
				
			}
			//cout << k << endl;
			Manage[i]->Buses.push_back(k);
		}
	}
	void bfs(int u,int t)
	{
		bool l[100];
		int parent[100];
		memset(l, false, sizeof(l));
		queue<int>q;
		q.push(u);
		l[u] = true;
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			for (auto i = manage[v].begin(); i != manage[v].end(); i++) {
				
				if (!l[*i]) {
					q.push(*i);
					l[*i] = true;
					parent[(*i)] = v;
				}
			}
		}
		if (!l[t]) cout << "no road from s to t" << endl;
		else
		{
			stack<int>st;
			while (t != u)
			{
				st.push(t);
				t = parent[t];
			}
			st.push(u);
			while (!st.empty())
			{
				cout << st.top() << ' ';
				st.pop();
			}

		}
	}
	void implement()
	{
		manage.assign(6, vector<int>());
		bool P[100][100];
		memset(P, false, sizeof(P));
		for (int i = 0; i < Manage.size(); i++)
		{
			for (int j = 0; j < Manage[i]->Buses.size(); j++)
			{
				for (int k = j + 1; k < Manage[i]->Buses.size(); k++)
				{
					if (P[Manage[i]->Buses[j]][Manage[i]->Buses[k]] == false)
					{
						manage[Manage[i]->Buses[j]].push_back(Manage[i]->Buses[k]);
						manage[Manage[i]->Buses[k]].push_back(Manage[i]->Buses[j]);
						P[Manage[i]->Buses[j]][Manage[i]->Buses[k]] = true;
					}
					
					//cout << Manage[i]->Buses[j] << ' ' << Manage[i]->Buses[k] << endl;
				}
			}
		}
		/*for (int i = 1; i <= 5; i++)
		{
			cout << i << endl;
			for (auto j = manage[i].begin(); j != manage[i].end(); j++)
			{
				cout << (*j) << ' ';
			}
			cout << endl;
		}*/
			
		bfs(5,4);
		
	}
	void print_()
	{
		for (int i = 0; i < Manage.size(); i++)
		{
			cout << Manage[i]->name <<endl;
			for(int j = 0 ; j < Manage[i]->Buses.size();j++)
			{
				cout<<Manage[i]->Buses[j]<<' ';
			}
			cout << endl;
		}
	}
};