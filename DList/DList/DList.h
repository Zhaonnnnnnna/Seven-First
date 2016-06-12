#ifndef __DLIST_H__
#define __DLIST_H__

typedef int DataType;
#include<iostream>
using namespace std;

struct Node
{
	Node(const DataType& d)
	:_data(d)
	, _next(NULL)
	, _prev(NULL)
	{}
	DataType _data;
	struct Node *_next;
	struct Node *_prev;
};

class DList
{
	friend ostream& operator<<(ostream& os, const DList& s);
public:
	DList()
		:_head(NULL)
		, _tail(NULL)
	{}
	DList(const DList& s)
		:_head(NULL)
		, _tail(NULL)
	{
		Node* cur = s._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
		_tail = cur;
	}
	~DList()
	{
		if (_head == NULL)
			return;
		else
		{
			Node *cur = _head;
			while (cur)
			{
				Node *del = cur;
				cur = cur->_next;
				delete del;
			}
			_head = NULL;
			_tail = NULL;
		}
	}
	DList& operator=(DList s)
	{
		swap(_head, s._head);
		swap(_tail, s._tail);
		return *this;
	}

public:
	void PushBack(const DataType& d);
	void PushFront(const DataType& d);
	void PopBack();
	void PopFront();
	Node* Find(const DataType& d);
	void Insert(Node* pos, const DataType& d);
	void Reverse();
	void Sort();
	void Remove(const DataType& d);
	void RemoveAll(const DataType& d);

private:
	Node *_head;
	Node *_tail;
};

#endif //__DLIST_H__