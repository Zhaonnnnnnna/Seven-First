#ifndef BIGDATA_H
#define BIGDATA_H
#include<iostream>
using namespace std;
#include<string>
#include<assert.h>

typedef long long INT64;
#define VALUE 0xCCCCCCCCCCCCCCCC
#define MAX 0x7FFFFFFFFFFFFFFF
#define MIN 0x8000000000000000
#define DEFAULT NULL

class BigData
{
public:
	BigData(INT64 value = VALUE);
	BigData(const char* a);
	//BigData(string s);

	friend ostream& operator<<(ostream& os, const BigData& bigData);

protected:
	bool IsINT64Overflow()const;

public:
	BigData operator+(const BigData& bigData);
	BigData operator-(const BigData& bigData);
	BigData operator*(const BigData& bigData);
	BigData operator/(const BigData& bigData);
	
protected:
	string ADD(string left, string right);
	string SUB(string left, string right);
	string MUL(string left, string right);
	string DIV(string left, string right);


	int DivSub(string& tmp, string& pRight);
	bool IsLessThanDiv(string& pRight, string& tmp);

protected:
	INT64 _value;
	string _str;
};

#endif BIGDATA_H