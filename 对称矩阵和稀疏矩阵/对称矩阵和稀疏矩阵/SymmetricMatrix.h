#pragma once;
#include<iostream>
using namespace std;
#include<vector>

template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(T* a, size_t size, size_t n)
		:_data(new T[n*(n + 1) / 2])
		, _size(size)
		, _n(n)
	{
		size_t index = 0;
		for (size_t i = 0; i < _n; i++)
		{
			for (size_t j = 0; j < _n; j++)
			{
				if (i >= j)
				{
					_data[index++] = a[i*n + j];
				}
				else
				{
					break;
				}
			}
		}
	}
public:
	void Display()
	{
		size_t index = 0;
		for (size_t i = 0; i < _n; i++)
		{
			for (size_t j = 0; j < _n; j++)
			{
				if (i >= j)
				{
					cout << _data[i*(i + 1) / 2 + j]<<" ";
				}
				else
				{
					cout << _data[j*(j + 1) / 2 + i]<<" ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	T& Access(size_t i, size_t j)
	{
		if (i < j)
		{
			swap(i, j);
		}
		return _data[i*(i + 1) / 2 + j];
	}
protected:
	T* _data;
	size_t _size;
	size_t _n;
};

template<class T>
struct Triple
{
	T _value;
	size_t _col;
	size_t _row;
	Triple(const T& value = T(), size_t row = 0, size_t col = 0)
		:_value(value)
		, _row(row)
		,_col(col)
	{}
};

template<class T>
class SparseMatrix
{
public:
	SparseMatrix(T* a, size_t m, size_t n, const T& invalid)
		:_rowSize(m)
		, _colSize(n)
		, _invalid(invalid)
	{
		for (size_t i = 0; i < _rowSize; i++)
		{
			for (size_t j = 0; j < _colSize; j++)
			{
				if (a[i*n + j] != _invalid)
				{
					_a.push_back(Triple<T>(a[i*n + j], i, j));
				}
			}
		}
	}
	SparseMatrix()
		:_rowSize(0)
		, _colSize(0)
		, _invalid(0)
	{}

public:
	void Display()
	{
		size_t index = 0;
		for (size_t i = 0; i < _rowSize; i++)
		{
			for (size_t j = 0; j < _colSize; j++)
			{
				if (index < _a.size()&&_a[index]._row == i&&_a[index]._col == j)
				{
					cout << _a[index]._value << " ";
					index++;
				}
				else
				{
					cout << _invalid << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}


	SparseMatrix<T> Transport()
	{
		SparseMatrix<T> tmp;
		tmp._colSize = _rowSize;
		tmp._rowSize = _colSize;
		tmp._invalid = _invalid;
		
		
		for (size_t i = 0; i < _colSize; i++)
		{
			size_t index = 0;
			while (index < _a.size())
			{
				if (_a[index]._col == i)
				{
					Triple<T> t;
					t._col = _a[index]._row;
					t._row = _a[index]._col;
					t._value = _a[index]._value;
					tmp._a.push_back(t);
				}
				index++;
			}

		}
		return tmp;
	}
	
	
	SparseMatrix<T> FastTransport()
	{
		SparseMatrix<T> tmp;
		tmp._colSize = _rowSize;
		tmp._rowSize = _colSize;
		tmp._invalid = _invalid;
		tmp._a.resize(_a.size());

		int *RowCounts = new int[_colSize];
		int *RowStart = new int[_colSize];
		memset(RowCounts, 0, sizeof(int)*_colSize);
		memset(RowStart, 0, sizeof(int)*_colSize);

		//统计个数
		size_t index = 0;
		while (index < _a.size())
		{
			RowCounts[_a[index]._col]++;
			index++;
		}
		RowStart[0] = 0;
		for (size_t i = 1; i < _colSize; i++)
		{
			RowStart[i] = RowStart[i - 1] + RowCounts[i - 1];
		}

		//定位位置
		index = 0;
		while (index < _a.size())
		{
			int rowindex = _a[index]._col;
			int& start = RowStart[rowindex];
			Triple<T> t;
			t._col = _a[index]._row;
			t._row = _a[index]._col;
			t._value = _a[index]._value;
			tmp._a[start] = t;
			start++;
			index++;
		}
		delete[] RowCounts;
		delete[] RowStart;

		return tmp;
	}



protected:
	vector<Triple<T>> _a;
	size_t _rowSize;
	size_t _colSize;
	T _invalid;
};

