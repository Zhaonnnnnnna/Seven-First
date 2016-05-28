#pragma once

#include<iostream>
using namespace std;
#include<vector>
#include<string>

template<class K,class V>
struct HashTableNode
{
	K _key;
	V _value;
	HashTableNode<K, V>* _next;

	HashTableNode(const K& key, const V& value)
		: _next(NULL)
		, _key(key)
		, _value(value)
	{}
};


template<class K>
struct _HashFunc
{
	size_t operator()(const K& key,size_t size)
	{
		return key%size;
	}
};

template<>
struct _HashFunc<string>
{
	size_t operator()(const string& s, size_t size)
	{
		int index = 0;
		int Size = s.size();
		size_t sum = 0;
		while (index < Size)
		{
			sum += s[index];
			index++;
		}

		return sum%size;
	}
};

const int _PrimeSize = 28;
static const unsigned long _PrimeList[_PrimeSize] =
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};

template<class K,class V>
class HashTableBucket
{
	typedef HashTableNode<K, V> Node;

public:
	HashTableBucket()
		:_size(0)
	{
		_tables.resize(_PrimeList[0]);
	}

	HashTableBucket(size_t size)
	{
		_tables.resize(size);
	}

	HashTableBucket(const HashTableBucket<K, V>& ht)
		:_size(0)
	{
		_tables.resize(ht._tables.size());
		Node* cur = ht._tables[0];

		int i = 0;
		for (i = 0; i < _tables.size(); i++)
		{
			cur = ht._tables[i];
			while (cur)
			{
				Insert(cur->_key, cur->_value);
				cur = cur->_next;
			}
		}
	}

	~HashTableBucket()
	{
		Node* cur = _tables[0];
		Node* prev = _tables[0];

		int i = 0;
		for (i = 0; i < _tables.size(); i++)
		{
			prev = _tables[i];
			cur = _tables[i];

			while (cur)
			{
				cur = cur->_next;
				Node* del = prev;
				delete del;
				del = NULL;
				prev = cur;
			}

			_tables[i] = NULL;
		}
	}

	HashTableBucket& operator=(HashTableBucket<K,V> ht)
	{
		_tables.swap(ht._tables);
		swap(_size, ht._size);
		return *this;
	}

public:
	bool Insert(const K& key, const V& value)
	{
		_CheckCapacity();

		_HashFunc<K> fun;
		int index = fun(key, _tables.size());

		Node* newNode = new Node(key, value);

		if (_tables[index] == NULL)
		{
			_tables[index] = newNode;
		}
		else
		{
			Node* cur = _tables[index];
			while (cur)
			{
				cur = cur->_next;
			}
			cur->_next = newNode;
		}
		_size++;

		return true;
	}

	Node* Find(const K& key)
	{
		_HashFunc<K> fun;
		int index = fun(key, _tables.size());

		Node* cur = _tables[index];
		if (cur == NULL)
		{
			return NULL;
		}
		else
		{
			while (cur)
			{
				if (cur->_key == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
		}
		return NULL;
	}

	bool Remove(const K& key)
	{
		_HashFunc<K> fun;
		int index = fun(key, _tables.size());

		Node* cur = _tables[index];
		Node* prev = _tables[index];
		if (cur == NULL)
		{
			return false;
		}
		else if (cur->_next == NULL)
		{
			if (cur->_key == key)
			{
				delete cur;
				cur = NULL;
				_tables[index] = NULL;
				return true;
			}
			else
				return false;
		}
		else
		{
			while (cur)
			{
				if (cur->_key == key)
				{
					Node* del = cur;
					cur = cur->_next;
					delete del;
					del = NULL;
					prev->_next = cur;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
		}
		
	}

	void Print()
	{
		int index = 0;
		Node* cur = NULL;
		for (index = 0; index < _tables.size(); index++)
		{
			cur = _tables[index];
			if (cur)
			{
				while (cur)
				{
					cout << "[key:" << cur->_key << " value:" << cur->_value << "]->";
					cur = cur->_next;
				}
				cout << endl;
			}
			else
			{
				cout << "NULL" << endl;
			}
		}
		cout << "over" << endl;

	}

protected:
	void _CheckCapacity()
	{
		if (_size * 10 / _tables.size() >= 10)
		{
			HashTableBucket<K, V> tmp(GetNextPrime(_tables.size()));

			int index = 0;
			Node* cur = _tables[0];

			while (index < tmp._tables.size())
			{
				while (cur)
				{
					Insert(cur->_key, cur->_value);
					cur = cur->_next;
				}
				
				index++;
			}
		}
	}

	size_t GetNextPrime(size_t size)
	{
		int i = 0;
		for (i = 0; i < 28; i++)
		{
			if (size == _PrimeList[i])
			{
				return _PrimeList[i + 1];
			}
		}
	}


protected:
	vector<Node*> _tables;
	size_t _size;
};


void test3()
{
	HashTableBucket<int, int> ht;
	ht.Insert(1, 1);
	ht.Insert(2, 2);
	ht.Insert(3, 3);
	ht.Insert(4, 4);
	ht.Print();


	HashTableNode<int ,int>* cur = ht.Find(1);
	cout << cur->_value << endl;
}
