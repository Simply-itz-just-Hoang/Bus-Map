#pragma once
#include "Header.h"

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node(T a)
	{
		data = a;
		next = nullptr;
	}
};
template <typename T>
struct LList
{
	Node<T>* head;
	int size;
	LList()
	{
		head = new Node<T>(T());
		head->next = nullptr;
		size = 0;
	}
	void Addfirst(T a)
	{
		Node<T>* Newnode = new Node<T>(a);
		Newnode->next = head->next;
		head->next = Newnode;
		size++;
	}
	void Addlast(T a)
	{
		Node<T>* Newnode = new Node<T>(a);
		Newnode->next = nullptr;
		Node<T>* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = Newnode;
		size++;
	}
	Node<T>* Gethead()
	{
		return head;
	}
	T Query(int n)
	{
		if (0 < n && n <= size)
		{
			Node<T>* p = head;
			for (int i = 1; i <= n; i++)
			{
				p = p->next;
			}
			return p->data;
		}
	}
	void print()
	{
		Node<T>* p = head->next;
		while (p != nullptr)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};