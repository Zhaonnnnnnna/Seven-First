#pragma once

#include<iostream>
using namespace std;

#include<cmath>

template<class K,class V>
struct AVLTreeNode
{
	K _key;
	V _value;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;

	AVLTreeNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(NULL)
	{}

	~AVLTree()
	{}

public:
	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}

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
				return false;
		}

		cur = new Node(key, value);
		if (parent->_key>key)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//更新平衡因子
		while (parent)
		{
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0)
				break;
			if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
						_RotateR(parent);
					else
						_RotateLR(parent);		
				}
				else
				{
					if (cur->_bf == 1)
						_RotateL(parent);
					else
						_RotateRL(parent);
				}

				break;
			}
			cur = parent;
			parent = cur->_parent;
		}
	}

	bool Remove(const K& key)
	{
		if (_root == NULL)
			return false;;
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
				if (cur->_left == NULL)
				{
					Node* subR = cur->_right;
					if (parent->_left == cur)
					{
						parent->_left = subR;
						parent->_bf++;
					}
					else
					{
						parent->_right = subR;
						parent->_bf--;
					}
					if (subR)
						subR->_parent = parent;
				}
				else if (cur->_right == NULL)
				{
					Node* subL = cur->_left;
					if (parent->_left == cur)
					{
						parent->_left = subL;
						parent->_bf++;
					}
					else
					{
						parent->_right = subL;
						parent->_bf--;
					}
					if (subL)
						subL->_parent = parent;
				}
				else
				{
					Node* subR = cur->_right;
					while (subR->_left)
					{
						subR = subR->_left;
					}
					cur->_key = subR->_key;
					cur->_value = subR->_value;

					Node* pNode = subR->_parent;
					Node* subRR = subR->_right;
					if (pNode->_left == subR)
					{
						pNode->_left = subRR;
						pNode->_bf++;
					}
					else
					{
						pNode->_right = subRR;
						pNode->_bf--;
					}

					cur = subR;
					parent = pNode;
				}

				//更新平衡因子
				Node* ppNode = parent->_parent;
				while (ppNode)
				{
					if (ppNode->_bf == 0)
						break;
					if (ppNode->_left == parent)
						ppNode->_bf++;
					else
						ppNode->_bf--;

					ppNode = ppNode->_parent;
				}
				delete cur;
				return true;
			}
		}
	}	
	Node* Find(const K& key)
	{
		if (_root == NULL)
			return NULL;

		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
				cur = cur->_left;
			else if (cur->_key < key)
				cur = cur->_right;
			else

				return cur;
		}
		return NULL;
	}
	void InOrder()
	{
		_InOrder(_root);
	}


	bool IsBlanceTree()
	{
		return _IsBlanceTree(_root);
	}

protected:
	void _RotateL(Node* parent)
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

		subR->_bf = parent->_bf = 0;

	}

	void _RotateR(Node* parent)
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
		{			
			 _root = subL;
		}
			
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;	
		}
		subL->_parent = ppNode;

		subL->_bf = parent->_bf = 0;
	}

	void _RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		_RotateL(subL);
		_RotateR(parent);

		if (bf == 0)
			subL->_bf = parent->_bf = 0;
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
		}
		else
		{
			parent->_bf = 1;
			subL->_bf = 0;
		}
	}

	void _RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		_RotateR(subR);
		_RotateL(parent);

		if (bf == 0)
			parent->_bf = subR->_bf = 0;
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else
		{
			parent->_bf = -1;
			subR->_bf = 0;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout << root->_key << "  ";
		_InOrder(root->_right);
	}

	bool _IsBlanceTree(Node* root)
	{
		if (root == NULL)
			return true;

		int left = Height(root->_left);
		int right = Height(root->_right);

		if (abs(left - right) <= 1)
			return true;
		else
			return false;
	}

	int Height(Node* root)
	{
		return _Height(root);
	}

	int _Height(Node* root)
	{
		if (root == NULL)
			return 0;

		return _Height(root->_left) > _Height(root->_right) ?( _Height(root->_left) + 1) : (_Height(root->_right) + 1);
	}

protected:
	Node* _root;
};