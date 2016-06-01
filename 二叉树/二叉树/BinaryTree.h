#pragma once
#include<iostream>
using namespace std;
#include<queue>
#include<stack>


template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	BinaryTreeNode(const T& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class T>
class BinaryTree
{
public:
	BinaryTree()
		:_root(NULL)
	{}

	BinaryTree(const T* str, size_t size,const T& invalid)
	{
		size_t index = 0;
		_root = _CreateTree(str, size,index, invalid);
	}

	BinaryTree(const BinaryTree<T>& b)
	{
		_root = _Copy(b._root);
	}

	BinaryTree<T>& operator=(BinaryTree<T> b)
	{
		swap(_root, b._root);
		return *this;
	}

	~BinaryTree()
	{
		_Destory(_root);
	}

public:
	/*void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}
*/
	void PrevOrder_NonR()
	{
		stack<BinaryTreeNode<T>* > v1;
		v1.push(_root);
		BinaryTreeNode<T>* cur = _root;
		cout << v1.top()->_data << " ";
		while (!v1.empty())
		{
			v1.pop();
			if (cur->_right)
			{
				v1.push(cur->_right);
			}
			if (cur->_left)
			{
				v1.push(cur->_left);
			}
			if (v1.size() == 0)
			{
				return;
			}
			cout << v1.top()->_data << " ";
			cur = v1.top();	
		}
	}

	void InOrder_NonR()
	{
		stack<BinaryTreeNode<T>* > v2;
		BinaryTreeNode<T>* cur = _root;
		while (cur||!v2.empty())
		{
			while (cur)
			{
				v2.push(cur);
				cur = cur->_left;
			}

			cout << v2.top()->_data << " ";
			BinaryTreeNode<T>* top = v2.top();
			v2.pop();
			cur = top->_right;
		}
	}

	void PostOrder_NonR()
	{
		BinaryTreeNode<T>* cur = _root;
		BinaryTreeNode<T>* prev = NULL;
		stack<BinaryTreeNode<T>* > s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			BinaryTreeNode<T>* top = s.top();
			if (top->_right == NULL || top->_right == prev)
			{
				cout << top->_data << " ";
				s.pop();
				prev = top;
			}
			else
			{
				cur = top->_right;
			}
		}
	}
	
	void LevelOrder()
	{
		_LevelOrder(_root);
	}

	size_t Size()
	{
		size_t size = _Size(_root);
		return size;
	}

	size_t Depth()
	{
		size_t dep = _Depth(_root);
		return dep;
	}

	size_t LeafSize()
	{
		size_t count = _LeafSize(_root);
		return count;
	}

	BinaryTreeNode<T>* Find(const T& d)
	{
		return _Find(_root, d);
	}

	//第K层有多少个结点
	/*size_t GetKLevel(const size_t& k)
	{
		return _GetKLevel(_root, k);
	}*/

	size_t GetKLevel(const size_t& k)
	{
	
		size_t level = 1;
		_GetKLevel(_root, 1evel, k, size);
		return size;
	}

protected:
	BinaryTreeNode<T>* _CreateTree(const T* str, size_t size, size_t& index, const T& invalid)
	{
		BinaryTreeNode<T>* root = NULL;
		if ((index < size) && (str[index] != invalid))
		{
			root = new BinaryTreeNode<T>(str[index]);
			root->_left = _CreateTree(str, size, ++index, invalid);
			root->_right = _CreateTree(str, size, ++index, invalid);
		}
		return root;
	}

	BinaryTreeNode<T>* _Copy(const BinaryTreeNode<T>* root)
	{
		if (root)
		{
	      BinaryTreeNode<T>* newRoot = new BinaryTreeNode<T>(root->_data);
		  newRoot->_left = _Copy(root->_left);
		  newRoot->_right = _Copy(root->_right);
		  return newRoot;
		}
		return NULL;	
	}

	void _Destory(BinaryTreeNode<T>* root)
	{
		BinaryTreeNode<T>* cur = root;
		if (root)
		{
			_Destory(root->_left);
			_Destory(root->_right);
			delete cur;
			cur = NULL;
			root = NULL;
		}
		return;
	}
protected:
	void _PrevOrder(const BinaryTreeNode<T>* root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}

	void _InOrder(const BinaryTreeNode<T>* root)
	{
		if (root == NULL)
		{
			return;
	    }
		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
		return;
	}

	void _PostOrder(const BinaryTreeNode<T>* root)
	{
		if (root == NULL)
		{
			return;
		}
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}

	void _LevelOrder(BinaryTreeNode<T>* root)
	{
		queue<BinaryTreeNode<T>*> q;
		q.push(root);
		while (0 < q.size())
		{
			BinaryTreeNode<T>* tmp = q.front();
			cout << tmp->_data << " ";
			q.pop();
			if (tmp->_left != NULL)
			{
				q.push(tmp->_left);
			}
			if (tmp->_right != NULL)
			{
				q.push(tmp->_right);
			}
		}
	}

	size_t _Size(const BinaryTreeNode<T>* root)
	{
		size_t size = 1;
		if (root==NULL)
		{
			return 0;
		}
		size += _Size(root->_left);
		size += _Size(root->_right);
		return size;
	}

	size_t _Depth(const BinaryTreeNode<T>* root)
	{
		size_t dep1 = 1;
		size_t dep2 = 1;
		if (root == NULL)
		{
			return 0;
		}
		dep1 += _Depth(root->_left);
		dep2 += _Depth(root->_right);
		if (dep1 > dep2)
		{
			return dep1;
		}
		else
		{
			return dep2;
		}
	}

	size_t _LeafSize(const BinaryTreeNode<T>* root)
	{
		size_t count = 0;
		if (root == NULL)
		{
			return 0;
		}
		if ((root->_left == NULL) && (root->_right == NULL))
		{
			return 1;
		}
		count += _LeafSize(root->_left);
		count += _LeafSize(root->_right);
		return count;
	}

	BinaryTreeNode<T>* _Find(BinaryTreeNode<T>* root, const T& d)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_data == d)
		{
			return root;
		}
		BinaryTreeNode<T>* ret = _Find(root->_left, d);
		if (ret)
		{
			return ret;
		}
		return _Find(root->_right, d);
	}

	/*size_t _GetKLevel(BinaryTreeNode<T>* root, size_t k)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (k == 1)
		{
			return 1;
		}
		return _GetKLevel(root->_left, k - 1) + _GetKLevel(root->_right, k - 1);
	}*/

	void _GetKLevel(BinaryTreeNode<T>* root, size_t level, size_t k, size_t& size)
	{
		if (root == NULL)
		{
			return;
		}
		if (k == level)
		{
			size++;
			return;
		}
		_GetKLevel(root->_left, level + 1, k, size);
		_GetKLevel(root->_right, level + 1, k, size);
	}

protected:
	BinaryTreeNode<T>* _root;
};