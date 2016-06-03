#pragma once
#define  _CRT_SECURE_NO_WARNINGS


#include<iostream>
using namespace std;

class String
{
	friend ostream& operator<<(ostream& os, const String& str);
public:
	String(char *str = "")
		:_str(new char[strlen(str) + 1 + 4])
	{
		*((int *)_str) = 1;
		_str = _str + 4;
		strcpy(_str, str);
	}
	String(const String& str)
	{
		_str = str._str;
		(*((int *)(_str - 4)))++;
	}
	~String()
	{
		if (*_str != NULL)
		{
			if (((*((int *)(_str - 4)))--) == 0)
			{
				delete[](_str - 4);
			}
		}
	}
public:
	String& operator=(const String& str)
	{
		if (this != &str)
		{
			if (((*((int *)(_str - 4)))--) == 0)
			{
				delete[](_str - 4);
			}
			_str = str._str;
			(*(int *)(str._str - 4))++;
			return *this;
		}
	}
	char& operator[](int index)
	{
		char *tmp = _str;
		if (((*(int *)(_str - 4)) - 1) != 0)
		{
			(*(int *)(_str - 4))--;
			_str = new char[strlen(_str) + 5];
			(*(int *)(_str + 4)) = 1;
			_str = _str - 4;
			strcpy(_str, tmp);
		}
		return _str[index];
	}
private:
	char *_str;
};

ostream& operator<<(ostream& os, const String& str)
{
	os << str._str << endl;
	return os;
}


