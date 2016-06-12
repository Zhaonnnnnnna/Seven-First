#include"DList.h"

template <typename T>
DList<T>& DList<T>::operator=(const DList<T> dl)
{
	swap(_head, dl._head);
	swap(_tail.dl._tail);
	return *this;
}

template <typename T>
void DList<T>::PushBack(const T& d)
{
	Node<T> newnode = new Node<T>(d);
	if (_head == NULL)
	{
		_head = newnode;
		_tail = newnode;
	}
	else
	{
		_tail->_next = newnode;
		newnode->_prev = _tail;
		_tail = newnode;
	}
}

template <typename T>
void DList<T>::PopBack()
{
	if (_head == NULL)
	{
		return;
	}
	else
	{
		Node<T>* del = _tail;
		_tail = _tail->_prev;
		_tail->_next = NULL;
		delete del;
	}
}

template <typename T>
void DList<T>::PushFront(const T& d)
{
	Node<T> *newnode = new Node<T>(d);
	if (_head == NULL)
	{
		_head = newnode;
		_tail = newnode;
	}
	else
	{
		newnode->_next = _head;
		_head->_prev = newnode;
		_head = newnode;
	}
}

template <typename T>
void DList<T>::PopFront()
{
	Node<T> *del = _head;
	_head = _head->_next;
	_head->_prev = NULL;
	delete del;
}


template <typename T>
Node<T>*  DList<T>::Find(const T& d)
{
	Node<T> *cur = _head;
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

template <typename T>
void DList<T>::Insert(Node<T> *pos, const T& d)
{
	Node<T> *newhead = new Node<T>(d);
	newhead->_next = pos->_next;
	pos->_next = newhead;
	newhead->_prev = pos;
	pos->_next->_prev = newhead;
}

template <typename T>
void DList<T>::Sort()
{
	Node<T> *cur = _head;
	Node<T> *end = NULL;


	while (cur != end)
	{
		while (cur->_next != end)
		{
			if (cur->_data > cur->_next->_data)
			{
				T tmp = cur->_data;
				cur->_data = cur->_next->_data;
				cur->_next->_data = tmp;
			}
			cur = cur->_next;
		}
		end = cur;
	}

}

template <typename T>
void DList<T>::Reverse()
{
	Node<T> *p1 = NULL;
	Node<T> *p2 = _head;
	Node<T> *newhead = NULL;
	while (p2)
	{
		p1 = p2;
		p2 = p2->_next;
		p1->_next = newhead;
		p1->_prev = p2;
		newhead = p1;
	}
	_head = newhead;
}

template <typename T>
void DList<T>::Remove(const T& d)
{
	Node<T>* cur = NULL;
	cur = Find(d);
	if (cur == _head)
	{
		PopFront();
		return;
	}
	else   if (cur == _tail)
	{
		PopBack();
		return;
	}
	else
	{
		cur->_prev->_next = cur->_next;
		cur->_next->_prev = cur->_prev;
		delete cur;
		return;
	}


}

template <typename T>
void DList<T>::RemoveAll(const T& d)
{
	Node<T>* cur = _head;
	while ((cur = Find(d)))
	{
		Remove(d);
	}
}


template<typename T>
ostream& operator<<(ostream& os, const DList<T>& dl)
{
	Node<T> *cur = dl._head;
	while (cur)
	{
		os << cur->_data << "<-->";
		cur = cur->_next;
	}
	cout << "over" << endl;
	return os;
}

//template<typename T>
//void DList<T>::Print()
//{
//	Node<T> *cur = _head;
//	while (cur)
//	{
//		cout << cur->_data << "<-->";
//		cur = cur->_next;
//	}
//	cout << "over" << endl;
//}