#pragma once
#include<iostream>
using namespace std;
#include<cmath>

template<class K,class V>
struct BSTreeNode
{
	K _key;
	V _value;
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;

	BSTreeNode(const K& key, const V& value)
		:_left(NULL)
		, _right(NULL)
		, _key(key)
		, _value(value)
	{}
};


template<class K,class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()
		:_root(NULL)
	{}

	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}

		Node* parent = NULL;
		Node* cur = _root;
		Node* node = new Node(key, value);
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

		if (parent->_key>key)
			parent->_left = node;
		else
			parent->_right = node;
		return true;
	}
	bool InsertR(const K& key, const V& value)
	{
		return _InsertR(_root, key, value);
	}

	bool _InsertR(Node*& root, const K& key, const V& value)
	{
		if (root == NULL)
		{
			root = new Node(key, value);
			return true;
		}
         
		if (root->_key > key)
			_InsertR(root->_left, key, value);
		else if (root->_key < key)
			_InsertR(root->_right, key, value);
		else
			return false;
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

	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	Node* _FindR(Node* root, const K& key)
	{
		if (root == NULL)
			return NULL;

		if (root->_key > key)
		{
			_FindR(root->_left, key);
		}
		else if (root->_key < key)
		{
			_FindR(root->_right, key);
		}
		else
			return root;

	}

	bool Remove(const K& key)
	{
		if (_root == NULL)
			return false;

		Node* parent = NULL;
		Node* cur = _root;

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
					if (parent == NULL)
						_root = cur->_right;
					else
					{
						if (parent->_left == cur)
							parent->_left = subR;
						else if (parent->_right == cur)
							parent->_right = subR;
					}
				}
				else if (cur->_right == NULL)
				{
					Node* subL = cur->_left;
					if (parent == NULL)
						_root = cur->_left;
					else
					{
						if (parent->_left == cur)
							parent->_left = subL;
						else
							parent->_right = subL;
					}		
				}
				else
				{
					Node* subR = cur->_right;
					parent = cur;
					while (subR->_left)
					{
						parent = subR;
						subR = subR->_left;
					}

					cur->_key = subR->_key;
					cur->_value = subR->_value;

					Node* subRR = subR->_right;
					if (parent->_left == subR)
						parent->_left = subRR;
					else
						parent->_right = subRR;
					cur = subR;
				}
				delete cur;
				return true;
			}
		}

		return false;
	}

	bool RemoveR(const K& key)
	{
		return _RemoveR(_root, key);
	}

	bool _RemoveR(Node*& root, const K& key)
	{
		if (root == NULL)
			return false;

		if (root->_key > key)
		{
			_RemoveR(root->_left, key);
		}
		else if (root->_key < key)
		{
			_RemoveR(root->_right, key);
		}
		else
		{
			Node* cur = root;
			if (cur->_left == NULL)
			{
				root = root->_right;
				delete cur;
				return true;
			}
			
			else if (root->_right == NULL)
			{
				root = root->_left;
				delete cur;
				return true;
			}
			else
			{
				Node* subR = root->_right;
				while (subR && subR->_left)
				{
					cur = subR;
					subR = subR->_left;
				}
				root->_key = subR->_key;
				root->_value = subR->_value;
				if (cur->_left == subR)
					cur->_left = subR->_right;
				else
					cur->_right = subR->_right;
				
				delete subR;
				return true;
			}
		}
	}

	int Height(Node* root)
	{
		if (root == NULL)
			return 0;

		return (Height(root->_left) > Height(root->_right)) ? (Height(root->_left) + 1) : (Height(root->_right) + 1);

	}

	Node* GteRoot()
	{
		return _root;
	}

	bool IsBlanceTree()
	{
		return _IsBlanceTree(_root);
	}

	bool _IsBlanceTree(Node* root)
	{
		if (root == NULL)
			return true;

		int left = Height(root->_left);
		int right = Height(root->_right);

		if (abs(left-right) < 1)
			return true;
		else
			return false;
	}

	void ToMirror()
	{
		_ToMirror(_root);
	}

	void _ToMirror(Node* root)
	{
		if (root == NULL)
			return ;

		if (root->_left == NULL&&root->_right == NULL)
			return ;

		_ToMirror(root->_left);
		_ToMirror(root->_right);

		swap(root->_left, root->_right);

	}

	void InOrder()
	{
		_InOrder(_root);
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout << root->_key <<"   ";
		_InOrder(root->_right);
	}

protected:
	Node* _root;
};
