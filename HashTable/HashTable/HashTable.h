#pragma once
#include<string>
#include<iostream>
using namespace std;


namespace frist
{
	enum States
	{
		EMPTY,
		EXITS,
		DELETE,
	};

	template<class K>
	class HashTable
	{
	public:
		HashTable(size_t capacity = 10)
			:_tables(new K[capacity])
			, _states(new States[capacity])
			, _size(0)
			, _capacity(capacity)
		{

			size_t i = 0;
			for (i = 0; i < _capacity; i++)
			{
				_states[i] = EMPTY;
			}
		}

		HashTable(const HashTable<K>& ht)
			:_capacity(ht._capacity)
			, _size(0)
			, _states(new States[_capacity])
			, _tables(new K[_capacity])
		{

			size_t index = 0;

			for (index = 0; index < ht._size; index++)
			{
				if (ht._states[index] == EXITS)
				{
					Insert(ht._tables[index]);
				}
			}
		}

		HashTable& operator=(HashTable ht)
		{
			this->Swap(ht);
			return *this;
		}

	public:
		bool Insert(const K& key)
		{
			_CheckCapacity();

			//线性探测
			int index = _HashFunc(key);
			int flag = index;
			while (_states[index] == EXITS)
			{
				if (index == _capacity - 1)
				{
					index = 0;
				}
				index++;
				if (index == flag)
				{
					return false;
				}
			}

			_tables[index] = key;
			_states[index] = EXITS;
			_size++;
			return true;
		}

		bool Find(const K& key)
		{
			int index = _HashFunc(key);
			int flag = index;

			while (_states[index] != EXITS)
			{
				if (index == _capacity - 1)
				{
					index = 0;
				}

				index++;
				if (index == flag)
				{
					return false;
				}
			}

			if (_tables[index] == key)
			{
				return true;
			}
			return false;

		}

		bool Remove(const K& key)
		{
			int index = _HashFunc(key);
			int flag = index;

			while (_states[index] != EXITS)
			{
				if (index == _capacity - 1)
				{
					index = 0;
				}
				index++;
				if (index == flag)
				{
					return false;
				}
			}

			if (_tables[index] == key)
			{
				_states[index] = DELETE;
				_size--;
				return true;
			}

			return false;
		}

		size_t _HashFunc(const K& key)
		{
			return key%_capacity;
		}

		void Print()
		{
			K* cur = _tables;
			size_t index = 0;
			while (index < _capacity)
			{
				//printf("[%s:%d]->", _states[index], _tables[index]);
				if (_states[index] == EXITS)
				{
					cout << "[" << "EXITS"<< ":" << _tables[index] << "]" << "->";
				}
				else if (_states[index] == DELETE)
				{
					cout << "[" << "DELETE" << ":" << _tables[index] << "]" << "->";
				}
				else
				{
					cout << "[" << "EMPTY" << ":" << _tables[index] << "]" << "->";
				}
			
				index++;
			}
			cout << "over";
			cout << endl;
		}

		void Swap(HashTable<K> ht)
		{
			swap(_tables, ht._tables);
			swap(_states, ht._states);
			swap(_size, ht._size);
			swap(_capacity, ht._capacity);
		}

	protected:
		void _CheckCapacity()
		{
			if (_size * 10 / _capacity >= 7)
			{
				HashTable<K> tmp(2 * _capacity);

				int index = 0;
				while (index < tmp._capacity)
				{
					if (_states[index] == EXITS)
					{
						Insert(_tables[index]);
					}
					index++;
				}

				this->Swap(tmp);
			}


		}

	protected:
		K* _tables;//哈希表
		States* _states;//状态表

		size_t _size;
		size_t _capacity;
	};
};

namespace second
{
	enum States
	{
		EMPTY,
		EXITS,
		DELETE,
	};

	template<class K,class V>
	struct HashTableNode
	{
		K _key;
		V _value;
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
		size_t operator()(const string& s,size_t size)
		{
			int Size = s.size();
			int sum = 0;
			int i = 0;
			while (i<Size)
			{
				sum += s[i++];
			}

			return sum%size;
		}
	};


	//实现哈希表的key/value形式的二次探测
	template<class K, class V, class _HashFunc = _HashFunc<K> >
	class HashTable
	{
		typedef HashTableNode<K,V> Node;

	public:
		HashTable(size_t capacity = 10)
			:_tables(new Node[capacity])
			, _states(new States[capacity])
			, _capacity(10)
			,_size(0)
		{
			int index = 0;
			for (index = 0; index < _capacity; index++)
			{
				_states[index] = EMPTY;
			}
		}

		HashTable(const HashTable<K,V>& ht)
			:_capacity(ht._capacity)
			, _size(ht._size)
			, _tables(new Node[ht._capacity])
			, _states(new States[ht._capacity])
		{
			int index = 0;

			for (index = 0; index < _capacity; index++)
			{
				_states[index] = EMPTY;
			}

			index = 0;
			while (index < _capacity)
			{
				if (ht._states[index] == EXITS)
				{
					Insert(ht._tables[index]._key,ht._tables[index]._value);
				}
				index++;
			}
		}

		HashTable& operator=(HashTable<K,V> ht)
		{
			this->Swap(ht);
			return *this;
		}

	public:
		void Swap(HashTable<K, V> ht)
		{
			swap(_tables, ht._tables);
			swap(_states, ht._states);
			swap(_size, ht._size);
			swap(_capacity, ht._capacity);
		}

		bool Insert(const K& key, const V& value)
		{
			_CheckCapacity();

			_HashFunc fun;
			int index = fun(key,_capacity);
			int flag = index;
			int i = 1;

			while (_states[index] == EXITS)
			{
				if (index == _capacity - 1)
				{
					index = 0;
				}

				index = (flag + i*i) % _capacity;
				i++;

			}
			
			_tables[index]._value = value;
			_states[index] = EXITS;
			_tables[index]._key = key;
			_size++;
			return true;

		}

		Node* Find(const K& key)
		{
			_HashFunc fun;
			int index = fun(key,_capacity);
			int flag = index;

			while (_states[index] != EXITS)
			{
				if (index == _capacity)
				{
					index = 0;
				}
				index++;
				if (index == flag)
				{
                    return NULL;
				}
			}

			if (_tables[index]._value == key)
			{
				return _tables[index];
			}

			return NULL;
		}

		bool Remove(const K& key)
		{
			_HashFunc fun;
			int index = fun(key, _capacity);
			int flag = index;

			while (_states[index] != EXITS)
			{
				if (index == _capacity - 1)
				{
					index = 0;
				}
				index++;
				if (index == flag)
				{
					return false;
				}
			}

			_states[index] = DELETE;
			_size--;
			return true;
		}

		void Print()
		{
		
			int index = 0;
			while (index < _capacity)
			{
				if (_states[index] == EXITS)
				{
					cout << "[" << "EXITS:key" << _tables[index]._key << ":value"
						<< _tables[index]._value << "]" << "->";
				}
				else if (_states[index] == DELETE)
				{
					cout << "[" << "DELETE:key" <<" "<< ":value"
						<< " " << "]" << "->";
				}
				else
				{
					cout << "[" << "EMPTY:key" <<" " << ":value"
						<< " "<< "]" << "->";
				}
				cout << endl;
				index++;
			}
			cout << "over" << endl;
		}

	protected:
		void _CheckCapacity()
		{
			if (_size * 10 / _capacity > 6)
			{
				HashTable<K, V> tmp(2 * _capacity);

				int index = 0;
				while (index < tmp._capacity)
				{
					if (_states[index] == EXITS)
					{
						Insert(_tables[index]._key, _tables[index]._value);
					}
				}

				this->Swap(tmp);

			}
		}


	protected:
		Node* _tables;
		States* _states;
		
		size_t _size;
		size_t _capacity;
	};

}