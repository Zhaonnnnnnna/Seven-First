#pragma once
#include<iostream>
using namespace std;

enum PointerTag
{
	THREAD,
	LINK
};

template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	PointerTag _leftTag;//左孩子线索标志
	PointerTag _rightTag;//右孩子线索标志
	BinaryTreeNode(const T& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
	{
		_leftTag = LINK;
		_rightTag = LINK;
	}
};

template<class T>
class BinaryTreeThd
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTreeThd()
		:_root(NULL)
	{}

	BinaryTreeThd(const T* a, size_t size, const T& invaild)
	{
		size_t index = 0;
		_root = _CreateTree(a, size, index, invaild);
	}

	void InOrderThreading()    //中序线索化
	{
		Node* prev = NULL;
		_InOrderThreading(_root, prev);
	}

	void PrevOrderThreading()   //前序线索化
	{
		Node* prev = NULL;
		_PrevOrderThreading(_root, prev);
	}

	void PostOrderThreading()     //后序线索化
	{
		Node* prev = NULL;
		_PostOrderThreading(_root, prev);
	}

	void InOrderThd()     //中序遍历
	{
		Node* cur = _root;
		while (cur)
		{
			while (cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			while (cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			cur = cur->_right;
		}
		cout << endl;
	}

	void PrevOrderThd()   //前序遍历
	{
		Node* cur = _root;
		while (cur)
		{
			cout << cur->_data << " ";
			while (cur->_leftTag == LINK)
			{
				cur = cur->_left;
				cout << cur->_data << " ";
			}
			cur = cur->_right;
		}
		cout << endl;
	}

	void PostOrderThd()     //后序遍历
	{
		Node* cur = _root;
		while (cur)
		{
			while (cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			while (cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			cur = cur->_right;
		}
		cout << endl;
	}
protected:
	Node* _CreateTree(const T* a, size_t size, size_t& index, const T& invaild)
	{
		Node* root = NULL;
		if ((a[index] != invaild) && (index < size))
		{
			root = new BinaryTreeNode<T>(a[index]);
			root->_left = _CreateTree(a, size, ++index, invaild);
			root->_right = _CreateTree(a, size, ++index, invaild);
		}
		return root;
	}

	void _InOrderThreading(Node* root, Node*& prev)  //
	{
		if (root == NULL)
		{
			return;
		}
		_InOrderThreading(root->_left, prev);
		if (root->_left == NULL)
		{
			root->_leftTag = THREAD;
			root->_left = prev;
		}
		if (prev && (prev->_right == NULL))
		{
			prev->_rightTag = THREAD;
			prev->_right = root;
		}
		prev = root;
		_InOrderThreading(root->_right, prev);
	}

	void _PrevOrderThreading(Node* root, Node*& prev)
	{
		Node* cur = root;
		if (cur == NULL)
		{
			return;
		}
		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if (prev&&prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;
		if (cur->_leftTag == LINK)
		{
			_PrevOrderThreading(cur->_left, prev);
		}
		if (cur->_rightTag == LINK)
		{
			_PrevOrderThreading(cur->_right, prev);
		}
	}

	/*void _PostOrderThreading(Node* root, Node* prev)
	{
	Node* cur = root;
	if (cur == NULL)
	{
	return;
	}
	_PostOrderThreading(cur->_left, prev);
	_PostOrderThreading(cur->_right, prev);
	if (cur->_left == NULL)
	{
	cur->_leftTag = THREAD;
	cur->_left = prev;
	}
	if (prev&&prev->_right == NULL)
	{
	prev->_rightTag = THREAD;
	prev->_right = cur;
	}
	prev = cur;
	}*/
protected:
	Node* _root;
};