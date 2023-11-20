#include"Header.h"
#include"LList.h"


template <typename T>
struct couble
{
	T first;
	int second;
};

template <typename T>
struct LListcouble
{
	LList<couble<T>> a;
	int size = 0;
	void Addfirst(int x, T y)
	{
		couble<T> b;
		b.first = y;
		b.second = x;
		a.Addfirst(b);
		size++;
	}
	void Addlast(int x, T y)
	{
		couble<T> b;
		b.first = y;
		b.second = x;
		a.Addlast(b);
		size++;
	}
	/*T Query(int i)
	{
		couble<T> x= a.Query(i);
		return x.first;
	}*/
	Node<couble<T>>* Gethead()
	{
		return a.head;
	}
	
	void print()
	{
		for (int i = 1; i <= size; i++)
		{
			couble<T> x = a.Query(i);
			cout << x.first << " " << x.second << endl;;
		}
		cout << endl;
	}
};