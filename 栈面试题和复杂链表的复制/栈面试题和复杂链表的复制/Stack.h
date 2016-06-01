#pragma once;
#include<iostream>
using namespace std;
#include<Stack>
#include<assert.h>

//实现一个栈，要求实现Push（出栈）、Pop（入栈）、Min（返回最小值的操作）的时间复杂度为O(1)
template<class T>
class Stack
{
	//friend ostream& operator<< <T>(ostream& os, const Stack<T>& s);
public:
	void Push(const T& d)
	{
		_s.push(d);
		if (_min.empty() || _min.top() >= d)
		{
			_min.push(d);
		}
	}
	void Pop()
	{
		assert(_s.size() > 0);
		if (_s.top() == _min.top())
		{
			_min.pop();
			_s.pop();
		}
		else
			_s.pop();
	}
	T& Min()
	{
		assert(_s.size() > 0);
		return _min.top();
	}
private:
	stack<T> _s;
	stack<T> _min;
};

//用2个栈实现队列



//复杂链表的复制
template<class T>
struct ComplexNode
{
	ComplexNode(const T& d)
	:_data(d)
	, _next(NULL)
	, _random(NULL)
	{}
	T _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
};

template<class T>
class ComplexSlist
{
public:
	ComplexSlist()
		:_head(NULL)
		, _tail(NULL)
	{}
	~ComplexSlist()
	{
		if (_head == NULL)
		{
			return;
		}
		if (_head != NULL)
		{
			ComplexNode<T>* cur = _head;
			while (cur)
			{
				ComplexNode<T>* del = cur;
				cur = cur->_next;
				delete del;
			}
		}
		_head = NULL;
		_tail = NULL;
	}
	ComplexSlist(const ComplexSlist<T>& s)
	{
	
	}
public:
	
public:
	void Push(const T& d)
	{
		ComplexNode<T>* newnode = new ComplexNode<T>(d);
		if (_head == NULL)
		{
			_head = _tail = newnode;
		}
		else
		{
			_tail->_next = newnode;
			_tail = newnode;
		}
	}
	void Pop()
	{
		if (_head == NULL)
		{
			return;
		}
		else if (_head == _tail)
		{
			delete _head;
			_head = _tail = NULL;
		}
		else
		{
			ComplexNode<T>* cur = _head;
			while (cur->_next->_next )
			{
				cur = cur->_next;
			}
			delete _tail;
			_tail = cur;
			_tail->_next = NULL;
		}
	}
	void InitRandom(const T& d1, const T& d2)
	{
		ComplexNode<T>* cur1 = _head;
		ComplexNode<T>* s1 = NULL;
		ComplexNode<T>* s2 = NULL;
		while (cur1)
		{
			if (cur1->_data == d1)
			{
			    s1 = cur1;
			}
			if (cur1->_data == d2)
			{
				s2 = cur1;
			}
			cur1 = cur1->_next;
		}
		s1->_random = s2;
	}

	ComplexSlist<T>& operator=(const ComplexSlist<T> s)
	{
		swap(_head, s._head);
		swap(_tail, s._tail);
	}
	ComplexSlist<T>& operator=(const ComplexSlist<T> s)

	void Print()
	{
		ComplexNode<T>* cur = _head;
		while (cur)
		{
			cout << cur->_data;
			if (cur->_random != NULL)
			{
			   cout << "(" << cur->_random->_data << ")";
			}
			else
			{
				cout << "(" << "NULL" << ")";
			}
			cout << "-->";
			cur = cur->_next;
		}
		cout << "over";
		cout << endl;
	}

private:
	ComplexNode<T>* _head;
	ComplexNode<T>* _tail;

	
};

template<class T>
void CloneNode(ComplexNode<T>* Phead)
{
	ComplexNode<T>* cur = Phead;
	while (cur)
	{
		ComplexNode<T>* tmp = new ComplexNode<T>();
		tmp->_data = cur->_data;
		tmp->_next = cur->_next;
		cur->_next = tmp;
		tmp->_random = NULL;
		cur = tmp->_next;
	}

}

template<class T>
void CloneRandom(ComplexNode<T>* Phead)
{
	ComplexNode<T>* cur1 = Phead;
	ComplexNode<T>* cur2 = Phead->_next;
	while (cur1->_next->_next)
	{
		cur2->_random = cur1->_random->_next;
		cur1 = cur1->_next->_next;
		cur2 = cur2->_next->_next;
	}
}

template<class T>
ComplexNode<T>* SplitComplexSlist(ComplexNode<T>* Phead)
{
	ComplexNode<T>* cur = Phead;
	ComplexNode<T>* PClonehead = Phead->_next;
	ComplexNode<T>* clonecur = PClonehead;
	while (cur)
	{
		cur->_next = clonecur->_next;
		cur = cur->_next;
		clonecur->_next = cur->_next;
		clonecur = clonecur->_next;
	}
	return PConehead;
}

template<class T>
ComplexSlist<T>* CloneSlist(ComplexNode<T>* Phead)
{
	CloneNode(Phead);
	CloneRandom(Phead);
	
	return SplitComplexSlist(Phead);
}