#pragma once

#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>
#include"HuffmanTree.h"
#include"FileCompress.h"


template<class T>
struct Greater
{
	bool operator()(const T& l,const T& r)
	{
		return  l > r;
	}
};


template<class T>
struct Less
{
	bool operator()(const T& l, const T& r)
	{
		return  l < r;
	}
};


template<class T,class Com = Greater<T> >  
class Heap
{
public:
	Heap()
	{}

	Heap(const T* a, size_t size)
	{
		for (int i = 0; i < size; i++)
		{
			_a.push_back(a[i]);
		}

		 //½¨¶Ñ
		for (int i = (_a.size() - 2) / 2; i>=0; i--)
		{
			_AdujustDown(i);
		}	
	}

	T& top()
	{
	   assert(!_a.empty());
	   return _a[0];
	}

	void Pop()
	{
		assert(!_a.empty());
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdujustDown(0);
	}

	void Push(const T& d)
	{
		_a.push_back(d);
		_AdujustUp(_a.size() - 1);
	}

	bool empty()
	{
		return _a.empty();
	}

	void Print()
	{
		for (int i = 0; i < _a.size(); i++)
		{
			cout << _a[i] << "--";
		}
		cout << endl;
	}

protected:
	void _AdujustDown(int parent)
	{
		Com _com;

		int child = parent * 2 + 1;
		while (child < _a.size())
		{	
			if ((child + 1 < _a.size()) && _com(_a[child + 1],_a[child]))
			{
				child++;
			}

			if (_com(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = 2 * parent + 1;
			}

			else
			{
				break;
			}
		}		
	}

	void _AdujustUp(int child)
	{
		Com _com;

		size_t parent = (child - 2) / 2;
		while (child > 0)
		{
			if (_com(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}

			else
			{
				break;
			}

		}
	}
protected:
	vector<T> _a;
};