#pragma once
#include<iostream>
using namespace std;
#include<vector>

class BitMap
{
public:
	BitMap(size_t n)
	{
		_a.resize((n >> 5) + 1);
	}
public:
	void Set(size_t n)
	{
		size_t index = n / 32;
		size_t num = n % 32;

		_a[index] |= (1 << num);
		_size++;
	}

	void Reset(size_t n)
	{
		size_t index = n / 32;
		size_t num = n % 32;
		
		_a[index] &= ~(1 << num);
		_size--;
	}

	bool Test(size_t n)
	{
		size_t index = n / 32;
		size_t num = n % 32;

		return (_a[index] & (1 << num));
	}

protected:
	vector<int> _a;
	size_t _size;

};

struct __HashFunc1
{
	static size_t BKDRHash(const char * str)
	{
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}

	size_t operator()(const string& s)
	{
		return 	 BKDRHash((char*)s.c_str());
	}
};

struct __HashFunc2
{
	size_t SDBMHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
			//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
		}
		return hash;
	}

	size_t operator()(const string& s)
	{
		return 	 SDBMHash((char*)s.c_str());
	}
};

struct __HashFunc3
{
	size_t RSHash(const char *str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}

	size_t operator()(const string& s)
	{
		return 	 RSHash((char*)s.c_str());
	}
};

struct __HashFunc4
{
	size_t APHash(const char *str)
	{
		register size_t hash = 0;
		size_t ch;
		for (long i = 0; ch = (size_t)*str++; i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}

	size_t operator()(const string& s)
	{
		return 	 APHash((char*)s.c_str());
	}
};

struct __HashFunc5
{
	size_t JSHash(const char *str)
	{
		if (!*str)        // 这是由本人添加，以保证空字符串返回哈希值0  
			return 0;
		register size_t hash = 1315423911;
		while (size_t ch = (size_t)*str++)
		{
			hash ^= ((hash << 5) + ch + (hash >> 2));
		}
		return hash;
	}

	size_t operator()(const string& s)
	{
		return 	 JSHash((char*)s.c_str());
	}
};

	
class BloomFilter
{	  
public:
	BloomFilter(size_t n)
		:_capacity(n)
		,_bm(n)
	{}

public:
	void Set(char* s)
	{
		int index1 = __HashFunc1()(s) % _capacity;
		int index2 = __HashFunc2()(s) % _capacity;
		int index3 = __HashFunc3()(s) % _capacity;
		int index4 = __HashFunc4()(s) % _capacity;
		int index5 = __HashFunc5()(s) % _capacity;

		_bm.Set(index1);
		_bm.Set(index2);
		_bm.Set(index3);
		_bm.Set(index4);
		_bm.Set(index5);

	}

	bool Test(char* s)
	{
		int index1 = __HashFunc1()(s) % _capacity;
		if (!_bm.Test(index1))
			return false;

		int index2 = __HashFunc2()(s) % _capacity;
		if (!_bm.Test(index1))
			return false;

		int index3 = __HashFunc3()(s) % _capacity;
		if (!_bm.Test(index1))
			return false;

		int index4 = __HashFunc4()(s) % _capacity;
		if (!_bm.Test(index1))
			return false;

		int index5 = __HashFunc5()(s) % _capacity;
		if (!_bm.Test(index1))
			return false;

		return true;

	}


protected:
	BitMap	_bm;
	size_t _capacity;
};
