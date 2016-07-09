#pragma once

#include<iostream>
using namespace std;

#include<assert.h>

enum color
{
	BLACK,
	RED
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	K _key;
	V _value;
	color _col;

	RBTreeNode(const K& key, const V& value)
		:_left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _key(key)
		, _value(value)
		, _col(RED)
	{}
};


template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(NULL)
	{}

	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_col = BLACK;
			return true;
		}

		Node* node = new Node(key, value);
		Node* cur = _root;
		Node* parent = NULL;

		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		if (parent->_key > key)
		{
			parent->_left = node;
			node->_parent = parent;
		}
		else
		{
			parent->_right = node;
			node->_parent = parent;
		}

		cur = node;
		while (cur != _root&&parent->_col == RED)
		{
			Node* grandparent = parent->_parent;
			if (parent == grandparent->_left)
			{
				Node* uncle = grandparent->_right;
				//第一种情况
				if (cur->_col == RED && uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandparent->_col = RED;
				}
				//第二种或者第三种情况
				else
				{
					if (cur->_col == RED && cur == parent->_left 
						&& (uncle == NULL || uncle->_col == BLACK))
					{
						RotateR(grandparent);
						swap(grandparent, parent);

						parent->_col = RED;
						grandparent->_col = BLACK;
					}
					if (cur->_col == RED && cur == parent->_right 
						&& (uncle == NULL || uncle->_col == BLACK))
					{
						RotateL(parent);
						swap(cur, parent);

						RotateR(grandparent);
						swap(parent, grandparent);

						parent->_col = RED;
						grandparent->_col = BLACK;
					}

					
				}
				cur = grandparent;
				parent = cur->_parent;

			}
			else
			{
				Node* uncle = grandparent->_left;
			   //第一种情况
				if (cur->_col == RED && uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandparent->_col = RED;
					
				}

				//第二种或者第三种情况
				else
				{
					if (cur->_col == RED && cur == parent->_right
						&& (uncle == NULL || uncle->_col == BLACK))
					{
						RotateL(grandparent);
						swap(grandparent, parent);

						grandparent->_col = BLACK;
						parent->_col = RED;
					}

					if (cur->_col == RED && cur == parent->_left 
						&& (uncle == NULL || uncle->_col == BLACK))
					{
						RotateR(parent);
						swap(parent, cur);
						RotateL(grandparent);
						swap(grandparent, parent);

						grandparent->_col = BLACK;
						parent->_col = RED;
					}				
				}

				//当连续两个红色节点时
				/*if (grandparent->_col == RED&&grandparent->_parent->_col == RED)
				{*/
					cur = grandparent;
					if (cur)
					parent = cur->_parent;
				/*}*/
				
			}
		}

		_root->_col = BLACK;
		return true;
	}


	Node* Find(const K& key)
	{
		if (_root == NULL)
			return NULL;

		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return NULL;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		if (ppNode == NULL)
			_root = subR;

		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;
		}

		subR->_parent = ppNode;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (ppNode == NULL)
			_root = subL;
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;
		} 

		subL->_parent = ppNode;
	}

	bool CheckRETree()
	{
		if (_root == NULL)
			return true;
		if (_root&&_root->_col == RED)
			return false;

		//计算一条路径上黑色节点的数量
		int Bcount = 0;
		Node* cur = _root;
		while(cur)
		{
			if (cur->_col == BLACK)
				Bcount++;

			cur = cur->_left;
		}

		int count = 0;
		return _CheckRETree(_root, Bcount, count);

	}

	bool _CheckRETree(Node* root, int Bcount, int count)
	{
		if (root == NULL)
			return true;
		
		if (root->_col == BLACK)
			count++;

		//检查规则四
		if (root->_left == NULL&root->_right == NULL&&Bcount != count)
		{
			cout << "违反规则四" << root->_key << endl;
			return false;
		}

		//检查规则三
		if (root->_col == RED&&root->_parent->_col == RED)
		{
			cout << "违反规则三" << root->_key << endl;
			return false;
		}

		return _CheckRETree(root->_left, Bcount, count) 
			&& _CheckRETree(root->_right, Bcount, count);
	}
protected:
	 Node* _root;
};								 