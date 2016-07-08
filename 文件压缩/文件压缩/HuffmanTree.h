#pragma once

#include"Heap.h"
#include<vector>
 
template<class T>
struct HuffmanTreeNode
{
	HuffmanTreeNode<T>* _left;
	HuffmanTreeNode<T>* _right;
	T _weight;

	HuffmanTreeNode(const T& d)
		:_left(NULL)
		,_right(NULL)
		,_weight(d)
	{}
	
};



template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> Node;

public:
	HuffmanTree(const T* a, size_t size,const T& invalid)
	//HuffmanTree(const T* a, size_t size, int invalid)

	{

		//把所有有效值先构造成节点
		Node** tmp = new Node*[size];
		int index = 0;

		for (int i = 0; i < size; i++)
		{
			if (a[i] != invalid)
			{
				Node* node = new Node(a[i]);
				tmp[index++] = node;
			}
		}


		//将有效节点构成小堆
		Heap<Node*, NodeCom_Less> hp(tmp, index);

		while (!hp.empty())
		{	
			
			Node* leftNode = hp.top();
			hp.Pop();  

			//节点取完了
			if (hp.empty())
			{
				_root = leftNode;
				break;
			}
			Node* rightNode = hp.top();
			hp.Pop();

			Node* RNode = new Node(leftNode->_weight + rightNode->_weight);
			RNode->_left = leftNode;
			RNode->_right = rightNode;

			hp.Push(RNode);
		}

	}

	Node* GetRoot()
	{
		return _root;
	}

protected:
	struct NodeCom_Less
	{
		bool operator()(const Node* l, const Node* r) const
		{
			return l->_weight <= r->_weight;
		}
	};

protected:
	Node* _root;
};