#pragma once

#include<iostream>
using namespace std;

template<class T>

class SeqList
{
	friend ostream& operator<<(ostream& os, const SeqList<T>& s);

public:
	SeqList(const T* data = NULL)
		:_data(NULL)
		, _size(0)
		, _capacity(0)
	{
		CheckCapacity();
	}

	SeqList(const SeqList<T>& s)
		:_size(s._size)
		, _capacity(s._capacity)
	{
		_data = new T[_capacity];
		memcpy(_data, s._data, sizeof(T)*_szie);
	}

	~SeqList()
	{
		if (_data != NULL)
		{
			delete[] _data;
		}
	}
public:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			T* tmp = new T[2 * _capacity + 3];
			memcpy(tmp, _data, sizeof(T)*_size);
			delete[] _data;
			_data = tmp;
			_capacity = 2 * _capacity + 3;
		}
	}
	void PushBack(const T& d)
	{
		CheckCapacity();
		_data[_size] = d;
		_size++;
	}
	void PopBack()
	{
		if (_szie == 0)
			return;
		else
		{
			delete _data[_size - 1];
			_size--;
		}
	}
	void PushFront(const T& d)
	{
		CheckCapacity();
		int i = _size;
		while (i)
		{
			_data[i] = _data[i - 1];
			i--;
		}
		_data[0] = d;
		_size++;
	}
	void PopFront()
	{
		if (_size == 0)
			return;
		else
		{
			int i = 0;
			while (i < (_size - 1))
			{
				_data[i] = _data[i + 1];
				i++;
			}
			delete _data[_size - 1];
			_size--;
		}

	}
	void Sort()
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < _size - 1; i++)
		{
			for (j = 0; j < _size - 1 - i; j++)
			{
				if (_data[j]>_data[j + 1])
				{
					T tmp = _data[j];
					_data[j] = _data[j + 1];
					_data[j + 1] = tmp;
				}
			}
		}
	}
	void Insert(int pos, const T& d)
	{
		CheckCapacity();
		int i = _size;
		while (i <= pos)
		{
			_data[i] = _data[i - 1];
			i++;
		}
		_data[pos - 1] = d;
		_size++;
	}

private:
	T* _data;
	int _size;
	int _capacity;
};

template<class T>
ostream& operator<<(ostream& os, const SeqList<T>& s)
{
	int i = 0;
	while (i < s._size)
	{
		os << s._data[i] << "->";
		i++;
	}
	cout << "over";
	cout << endl;
	return os;
}


