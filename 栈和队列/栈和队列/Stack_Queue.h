#pragma once

#include<iostream>
using namespace std;
#include<assert.h>


template<class T>
class Stack
{
	friend ostream& operator<< <T>(ostream& os, const Stack<T>& s);
public:
	Stack()
		:_data(0)
		, _top(0)
		, _capacity(0)
	{}
	~Stack()
	{
		if (_data)
		{
			delete[] _data;
		}
	}
	Stack(const Stack<T>& s)
	{
		T* tmp = new T[s._capacity];
		size_t i = 0;
		for (i = 0; i <s._top; i++)
		{
			tmp[i] = s._data[i];
		}
		_data = tmp;
		_top = s._top;
		_capacity = s._capacity;
	}
public:
	void Push(const T& d)
	{
		_CheckCapacity();
		_data[_top++] = d;
	}
	void Pop()
	{
		assert(_top > 0);
		--_top;
	}
	bool Empty()
	{
		return _top == 0;
	}
	T& Top()
	{
		assert(_top > 0);
		return _data[_top - 1];
	}
	size_t _Size()
	{
		return _top;
	}
	Stack<T>& operator=(Stack<T> s)
	{
		swap(_data, s._data);
		_top = s._top;
		_capacity = s._capacity;
	}
protected:
	void _CheckCapacity()
	{
		if (_data == NULL)
		{
			_capacity = 3;
			_data = new T[_capacity * 2];
			return;
		}
		else
		{
			_capacity = 2 * _capacity;
			T* tmp = new T[_capacity];
			size_t i = 0;
			for (i = 0; i < _top; i++)
			{
				tmp[i] = _data[i];
			}
			delete[] _data;
			_data = tmp;
			return;
		}
	}
protected:
	T* _data;
	size_t _top;
	size_t _capacity;
};





template<class T>
struct Node
{
	Node(const T& d)
	:_data(d)
	, _next(NULL)
	{}
	T _data;
	Node<T>* _next;
};

template<class T>
class Queue
{
	friend ostream& operator<< <T>(ostream& os, const Queue<T>& q);
public:
	Queue()
		:_head(NULL)
		, _tail(NULL)
	{}
	~Queue()
	{
		Node<T>* cur = _head;
		while (cur)
		{
			Node<T>* del = cur;
			cur = cur->_next;
			delete del;
		}
		_head = NULL;
		_tail = NULL;
	}
	Queue(const Queue<T>& q)
	{
		Node<T>* cur = q._head;
		Node<T>* end = NULL;
		end = q._tail;
		while (cur != end)
		{
			Push(end->_data);
			while (cur->_next != end)
			{
				cur = cur->_next;
			}
			end = cur;
			cur = q._head;
		}
		Push(cur->_data);
	}
public:
	void Push(const T& d)
	{
		Node<T> *newNode = new Node<T>(d);
		if (_head == NULL)
		{
			_head = newNode;
			_tail = newNode;
		}
		else
		{
			newNode->_next = _head;
			_head = newNode;
		}

	}
	void Pop()
	{
		assert(_head != NULL);
		if (_head == _tail)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			Node<T>* del = _tail;
			Node<T>* cur = _head;
			while (cur->_next->_next)
			{
				cur = cur->_next;
			}
			_tail = cur;
			_tail->_next = NULL;
			delete del;
		}
	}
	T& Front()
	{
		return _head->_data;
	}
	T& Rear()
	{
		return _tail->_data;
	}
	bool Empty()
	{
		return _head == NULL;
	}
public:
	Queue<T>& operator=(Queue<T> q)
	{
		swap(_head, q._head);
		swap(_tail, q._tail);
		return *this;
	}
protected:
	Node<T>* _head;
	Node<T>* _tail;
};
template<class T>
ostream& operator<<(ostream& os, const Stack<T>& s)
{
	size_t i = 0;
	for (i = 0; i < s._top; i++)
	{
		os << s._data[i] << "--";
	}
	cout << "over" << endl;
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const Queue<T>& q)
{
	Node<T>* cur = q._head;
	while (cur)
	{
		os << cur->_data << "-->";
		cur = cur->_next;
	}
	cout << "over" << endl;
	return os;
}