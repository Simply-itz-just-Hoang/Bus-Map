#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
using namespace std;

int string_to_int(string x)
{
	int y = 0;
	for (int i = 0;i < x.size();i++)
	{
		y = y * 10 + (int)(x[i])-48;
	}
	//cout<<x<<" " << y << endl;
	return y;
}