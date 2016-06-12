#pragma once

#include<iostream>
using namespace std;

typedef   int DataType;
#define DEFAULT_CAPACITY 7

class SeqList
{
	friend ostream& operator<<(ostream& os, const SeqList& s);
public:
	SeqList(int capacity = DEFAULT_CAPACITY)
		:_capacity(capacity)
		, _size(0)
		, _pdata(0)
	{
		_pdata = new DataType[_capacity];
	}
	SeqList(const SeqList& s)
		:_size(s._size)
		, _capacity(s._capacity)
	{
		_pdata = new DataType[_capacity];
		memcpy(_pdata, s._pdata, _size*sizeof(DataType));
	}
	~SeqList()
	{
		if (_pdata != NULL)
		{
			delete[] _pdata;
		}
	}

public:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			DataType *tmp = new DataType[DEFAULT_CAPACITY + _capacity];
			memcpy(tmp, _pdata, _size*sizeof(DataType));
			delete[] _pdata;
			_pdata = tmp;
			_capacity = DEFAULT_CAPACITY + _capacity;
		}
	}
	void PushBack(const DataType& d)
	{
		CheckCapacity();
		_pdata[_size] = d;
		_size++;
	}
	void PushFront(const DataType& d)
	{
		CheckCapacity();
		int start = _size - 1;
		while (start >= 0)
		{
			_pdata[start + 1] = _pdata[start];
			start--;
		}
		_pdata[0] = d;
		_size++;
	}
	void  PopBack()
	{
		_size--;
	}
	void PopFront()
	{
		int start = 0;
		while (start < (_size - 1))
		{
			_pdata[start] = _pdata[start + 1];
			start++;
		}
		_size--;
	}
	void Remove(const DataType& d)
	{
		int i = 0;
		while (i < (_size - 1))
		{
			if (_pdata[i] == d)
			{
				int j = i;
				while (j < (_size - 1))
				{
					_pdata[j] = _pdata[j + 1];
					j++;
				}
				_size--;
			}
			i++;
		}
	}
	bool Find(const DataType& d)
	{
		int i = 0;
		while (i < (_size - 1))
		{
			if (_pdata[i] == d)
			{
				return true;
			}
			i++;
		}
		return false;
	}
	void Reverse()
	{
		DataType tmp = 0;
		int start = 0;
		int end = _size - 1;
		while (start < end)
		{
			tmp = _pdata[start];
			_pdata[start] = _pdata[end];
			_pdata[end] = tmp;
			start++;
			end--;
		}
	}
	void Insert(int pos, const DataType& d)
	{
		CheckCapacity();
		int i = _size;
		while (i > pos - 1)
		{
			_pdata[i] = _pdata[i - 1];
			i--;
		}
		_pdata[pos] = d;
		_size++;
	}
public:
	DataType& operator[](const int& index)
	{
		return _pdata[index];
	}



private:
	DataType *_pdata;
	int _size;
	int _capacity;

};

ostream& operator<<(ostream& os, const SeqList& s)
{
	int i = 0;
	for (i = 0; i < s._size; i++)
	{
		os << s._pdata[i] << " ";
	}
	cout << endl;
	return os;
}

