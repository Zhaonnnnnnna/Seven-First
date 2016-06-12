#include"DList.h"

void DList::PushBack(const DataType& d)
{
	Node *newNode = new Node(d);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = newNode;
	}
	else
	{
		_tail->_next = newNode;
		newNode->_prev = _tail;
		_tail = newNode;
	}
}
void DList::PushFront(const DataType& d)
{
	Node *newNode = new Node(d);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = newNode;
	}
	else
	{
		newNode->_next = _head;
		_head->_prev = newNode;
		_head = newNode;
	}
}
void DList::PopBack()
{
	Node *del = _tail;
	_tail = _tail->_prev;
	_tail->_next = NULL;
	delete del;
}
void DList::PopFront()
{
	Node *del = _head;
	_head = _head->_next;
	_head->_prev = NULL;
	delete del;
}
Node* DList::Find(const DataType& d)
{
	if (_head == NULL)
		return NULL;
	else
	{
		Node *cur = _head;
		while (cur)
		{
			if (cur->_data == d)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}
}
void DList::Insert(Node* pos, const DataType& d)
{
	Node *newNode = new Node(d);
	newNode->_next = pos->_next;
	newNode->_prev = pos;
	pos->_next = newNode;
}
void DList::Reverse()
{
	Node *p1 = NULL;
	Node *p2 = _head;
	Node *newhead = NULL;
	while (p2)
	{
		p1 = p2;
		p2 = p2->_next;
		p1->_next = newhead;
		p1->_prev = p2;
		newhead = p1;
		//newhead->_prev = p1;

	}
	_head = newhead;
}
void DList::Sort()
{
	Node *cur = _head;
	Node *end = NULL;
	while (cur != end)
	{
		while (cur->_next != end)
		{
			if (cur->_data > cur->_next->_data)
			{
				DataType tmp = cur->_data;
				cur->_data = cur->_next->_data;
				cur->_next->_data = tmp;
			}
			cur = cur->_next;
		}
		end = cur;
		cur = _head;
	}
}
void DList::Remove(const DataType& d)
{
	Node *cur = _head;
	while (cur)
	{
		if (cur->_data == d)
		{
			Node *del = cur;
			Node *tmp = cur->_prev;
			tmp->_next = cur->_next;
			cur->_next->_prev = tmp;
			delete del;
			return;
		}
		cur = cur->_next;
	}
}
void DList::RemoveAll(const DataType& d)
{
	Node *cur = _head;
	while (cur)
	{
		if (cur->_data == d)
		{
			Node *del = cur;
			Node *tmp = cur->_prev;
			tmp->_next = cur->_next;
			cur->_next->_prev = tmp;
			cur = cur->_next;
			delete del;
		}
		else
			cur = cur->_next;
	}
	return;
}

ostream& operator<<(ostream& os, const DList& s)
{
	Node *cur = s._head;
	while (cur)
	{
		os << cur->_data << "<-->";
		cur = cur->_next;
	}
	cout << "over";
	cout << endl;
	return os;
}