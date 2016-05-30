#pragma once;

#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>

//template<class T>
//class Heap
//{
//public:
//
//	Heap()
//	{}
//	Heap(const T* a, size_t size)
//	{
//		for (size_t i = 0; i < size; i++)
//		{
//			_a.push_back(a[i]);
//		}
//		//建堆
//		for (int i = ((_a.size() - 2) / 2); i < _a.size(); i--)
//		{
//			_AdjustDown(i);
//		}
//	}
//public:
//
//	void Push(const T& d)
//	{
//		_a.push_back(d);
//		_AdjustUp(_a.size() - 1);
//	}
//
//	void Pop()
//	{
//		assert(!_a.empty());
//		swap(_a[0], _a[_a.size() - 1]);
//		_a.pop_back();
//		_AdjustDown(0);
//	}
//	//堆排序
//	//建大堆，则对顶为最大元素，（借用快排），交换对顶与最后一个元素，然后再排序前面的N-1的数组
//
//	void HeapSort(int a[], int size)
//	{
//		//建大堆
//		for (int i = (size - 2) / 2; i >= 0; i--)
//		{
//			AdjustDown(a, size, i);
//		}
//		//判断数据
//		int n = size;
//		for (int i = 0; i < size; i++)
//		{
//			swap(a[0], a[size - 1 - i]);
//			AdjustDown(a, --n, 0);
//		}
//	}
//	
//protected:
//
//	void _AdjustDown(int parent)
//	{
//		int child = parent * 2 + 1;
//		while (child < _a.size())
//		{
//			if (((child + 1) < _a.size()) && (_a[child] < _a[child + 1]))
//			{
//				swap(_a[child], _a[child + 1]);
//			}
//
//			if (_a[child]>_a[parent])
//			{
//				swap(_a[child], _a[parent]);
//				parent = child;
//				child = parent * 2 + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	void AdjustDown(int a[], int size, int parent)
//	{
//		int child = parent * 2 + 1;
//		while (child < size)
//		{
//			if ((child + 1 < size) && (a[child + 1] > a[child]))
//			{
//				child++;
//			}
//			if (a[child] > a[parent])
//			{
//				swap(a[child], a[parent]);
//				parent = child;
//				child = parent * 2 + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//
//	void _AdjustUp(int child)
//	{
//		size_t parent = 0;
//		while (child > 0)
//		{
//			if (child % 2 == 0)
//			{
//				parent = (child - 2) / 2;
//			}
//			else
//			{
//				parent = (child - 1) / 2;
//			}
//
//			if (_a[child] > _a[parent])
//			{
//				swap(_a[child], _a[parent]);
//				child = parent;
//			}
//		}
//	}
//
//protected:
//	vector<T> _a;
//};

//仿函数实现大小堆
template<class T>
struct Less
{ 
	bool operator()(const T& l, const T& r)
	{
		return l > r;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& l,const T& r)
	{
		return l < r;
	}
};

template<class T,class Type=Greater<T>>
class Heap
{
public:
	Heap()
	{}
	Heap(const T* a, int size)
	{
		int i = 0;
		for (i = 0; i < size; i++)
		{
			_a[i] = a[i];
		}

		//建堆
		for (int i = (size - 2) / 2; i >= 0; i--)
		{
			_Adjustdown(_a, size, i);
		}
	}
protected:
	void _Adjustdown(vector<T>* a, size_t size, int parent)
	{
		int child = parent * 2 + 1;
		while (child < size)
		{
			if ((child + 1 < size) && (Greater<T>(child + 1, child)))
			//if ((child + 1 < size) && (_a[child + 1] > _a[child]))
			{
				child++;
			}
			if ((child + 1 < size) && (Less<T>(child + 1, child)))
			{
				child++;
			}

			if (Less<T>(child, parent))
			//if (_a[child] < _a[parent])
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}

			if (Greater<T>(child, parent))
				//if (_a[child] < _a[parent])
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}

			else
			{
				break;
			}
		}
	}

protected:
	vector<T>* _a;
};

////在100w个数中拿出最大的前K个数
//const int N = 1000000;
//const int K = 100;
//
//void Adjustdown1(int TopK[], int K, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < K)
//	{
//		if ((child + 1 < K) && (TopK[child + 1] < TopK[child]))
//		{
//			child++;
//		}
//
//		if (TopK[child] < TopK[parent])
//		{
//			swap(TopK[child], TopK[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//
//void GetTopK(int a[])
//{
//	assert(a);
//	int TopK[K];
//	for (int i = 0; i < K; i++)
//	{
//		TopK[i] = a[i];
//	}
//	//建小堆
//	for (int i = (K - 2) / 2; i >= 0; i--)
//	{
//		Adjustdown1(TopK, K, i);
//	}
//
//	//比较一个数 若大于最小的则交换
//	for (int i = K; i < N; i++)
//	{
//		if (TopK[0] < a[i])
//		{
//			swap(TopK[0], a[i]);
//			Adjustdown1(TopK, K, 0);
//		}
//	}
//
//	//打印
//	for (int i = 0; i < K; i++)
//	{
//		cout << TopK[i] << " ";
//	}
//	cout << endl;
//}

