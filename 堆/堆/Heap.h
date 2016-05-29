#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>


template<class T>
class Heap
{
public:

	Heap()
	{}
	Heap(const T* a, size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			_a.push_back(a[i]);
		}
		//½¨¶Ñ
		for (int i = ((_a.size() - 2) / 2); i < _a.size(); i--)
		{
			_AdjustDown(i);
		}
	}
public:

	void Push(const T& d)
	{
		_a.push_back(d);
		_AdjustUp(_a.size() - 1);
	}

	void Pop()
	{
		assert(!_a.empty());
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);
	}
protected:

	void _AdjustDown(int parent)
	{
		int child = parent * 2 + 1;
		while (child < _a.size())
		{
			if (((child + 1) < _a.size()) && (_a[child] < _a[child + 1]))
			{
				swap(_a[child], _a[child + 1]);
			}

			if (_a[child]>_a[parent])
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

	void _AdjustUp(int child)
	{
		size_t parent = 0;
		while (child > 0)
		{
			if (child % 2 == 0)
			{
				parent = (child - 2) / 2;
			}
			else
			{
				parent = (child - 1) / 2;
			}

			if (_a[child] > _a[parent])
			{
				swap(_a[child], _a[parent]);
				child = parent;
			}
		}		
	}

protected:
	vector<T> _a;
};