#pragma once

#include<iostream>
#include<string.h>
using namespace std;

template <typename T>
struct Node
{
public:
	Node(const T& d)
		:_data(d)
		, _prev(NULL)
		, _next(NULL)
	{}
	T _data;
	Node<T> *_prev;
	Node<T>	*_next;
};



template <typename T>
class DList
{
	template<typename T>
	friend ostream& operator<< <T>(ostream& os, const DList<T>& dl);

	

public:
	DList()
		: _head(NULL)
		, _tail(NULL)
	{}

	DList(const DList<T>& dl)
	{
		Node<T> *cur = dl._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
		_tail = cur;
	}

	~DList()
	{
		if (_head != NULL)
		{
			Node<T> *tmp = _head;
			while (tmp)
			{
				Node<T> *del = tmp;
				tmp = tmp->_next;
				delete del;
			}
		}
		_head = NULL;
		_tail = NULL;
	}


public:
	DList<T>& operator=(const DList<T> dl);
	void PushBack(const T& d);
	void PopBack();
	void PushFront(const T& d);
	void PopFront();
	Node<T>* Find(const T& d);
	void Insert(Node<T>* pos, const T& d);
	void Sort();
	void Reverse();
	void Remove(const T& d);
	void RemoveAll(const T& d);
	void Print();
private:
	Node<T> *_head;
	Node<T> *_tail;
};





