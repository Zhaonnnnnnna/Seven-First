#pragma once
#include<iostream>
using namespace std;
#include<stack>
#include<stdio.h>

void InsertSort(int* a, size_t n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = end + 1;
		while ((end >= 0) && (a[end]>a[tmp]))
		{
			swap(a[end], a[tmp]);
			end--;
			tmp--;		
		}
	}
	
}

void ShellSort(int* a, size_t n)
{
	int gap = n;
	int i = 0;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (i = 0; i< n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while ((a[end] > tmp) && (end >= 0))
			{
				//swap(a[end + gap], a[end]);
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}	
}


void _AdjustDown(int* a, size_t n, int i)
{
	int parent = i;
	int child = 2 * i + 1;
	while (child < n)
	{
		if((child + 1 < n) && (a[child] < a[child + 1]))
		{
			child++;
			//swap(a[child], a[child + 1]);
		}
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
	
}

void HeapSort(int* a, size_t n)
{
	int i = 0;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		_AdjustDown(a, n, i);
	}

	int size = n;
	for (i = 0; i < n; i++)
	{
		swap(a[0], a[n - 1 - i]);
		_AdjustDown(a, --size, 0);
	}

}


//void SelectSort(int* a, size_t n)
//{
//
//	for (int j = n - 1; j > 0; j--)
//	{
//		int MaxIndex = 0;
//		for (int i = 1; i <= j; i++)
//		{
//			if (a[i] > a[MaxIndex])
//			{
//				MaxIndex = i;
//			}
//		}
//		swap(a[MaxIndex], a[j]);
//	}
//
//}

void SelectSort(int* a, size_t n)
{
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int MaxIndex = start;
		int MinIndex = start;
		for (int i = start + 1; i <= end; i++)
		{
			if (a[i] >= a[MaxIndex])
			{
				MaxIndex = i;
			}
			if (a[i] <= a[MinIndex])
			{
				MinIndex = i;
			}
		}

		swap(a[start], a[MinIndex]);

		//排除最大的在第一位，最小的在最后一位要交换两次的情况
		if (a[end] < a[MaxIndex])
		{
			swap(a[end], a[MaxIndex]);
		}

		start++;
		end--;
	}
}


void BubbleSort(int* a, size_t n)
{
	int end = n - 1;
	while (end)
	{
		for (int i = 0; i <= end; i++)
		{
			if (a[i - 1] > a[i])
			{
				swap(a[i - 1], a[i]);
			}
		}
		end--;
	}
}


//左右交换
//int GetKey(int* a, int left, int right)
//{
//	//GetMid(a, left, right);
//
//	int key = a[right];
//	int start = left;
//	int end = right - 1;
//
//	while (start < end)
//	{
//		while ((a[start]<key)&&(start<end))
//		{
//			start++;
//		}
//	    while ((a[end]>key)&&(start<end))
//		{
//			end--;
//		}		
//	    swap(a[start], a[end]);		
//	}
//
//	if (a[right]<a[start])
//	{
//		swap(a[right], a[start]);
//		return start;
//	}
//
//	return right;
//}
//
//
//三数取中法
//
//void GetMid(int* a, int left, int right)
//{
//
//	int mid = (left + right) / 2;
//	int k = 0;
//	if (a[mid] > a[left])
//	{
//		if (a[left] > a[right])
//			k = left;
//		else if (a[mid] > a[right])
//			k = right;
//		else
//			k = mid;
//	}
//	else
//	{
//		if (a[left] < a[right])
//			k = left;
//		else if (a[mid]>a[right])
//			k = mid;
//		else
//			k = right;
//	}
//
//	swap(a[k], a[right]);
//
//}



//挖坑法
//int GetKey(int* a, int left, int right)
//{
//	int key = a[right];
//	int start = left;
//	int end = right;
//
//	while (start < end)
//	{
//		while ((a[start]<key) && (start<end))
//		{
//			start++;
//		}
//		if (a[start]>key)
//		{
//			a[end] = a[start];
//			end--;
//		}
//
//		while ((a[end]>key) && (start<end))
//		{
//			end--;
//		}
//		if (a[end] < key)
//		{
//			a[start] = a[end];
//			start++;
//		}
//		
//	}
//
//	if (a[start]>key)
//	{
//		a[start] = key;
//	}
//
//
//	return start;
//}



//前后指针
//int GetKey(int* a, int left, int right)
//{
//	int cur = left;
//	int prev = left - 1;
//	int key = a[right];
//
//	while (cur < right)
//	{
//		if (a[cur] < key)
//		{
//			prev++;
//			swap(a[cur], a[prev]);
//		}
//		cur++;
//	}
//
//	prev++;
//	if (a[prev]>a[cur])
//	{
//		swap(a[prev], a[cur]);
//	}
//
//	return prev;
//
//
//}



int GetKey(int* a, int left, int right)
{
	int key = a[right];
	int start = left;
	int end = right;

	while (start < end)
	{
		while ((a[start]<key) && (start<end))
		{
			start++;
		}
		if (a[start]>key)
		{
			a[end] = a[start];
			end--;
		}

		while ((a[end]>key) && (start<end))
		{
			end--;
		}
		if (a[end] < key)
		{
			a[start] = a[end];
			start++;
		}

	}


	a[start] = key;

	return start;
}


// 非递归
void QuickSort(int* a, int left, int right)
{
	stack<int> s;
	s.push(right);
	s.push(left);

	while (!s.empty())
	{
		int start = s.top();
		s.pop();
		int end = s.top();
		s.pop();

		if (start < end)
		{
			int div = GetKey(a, start, end);

			s.push(end);
			s.push(div + 1);

			s.push(div - 1);
			s.push(start);
         }

	}
	
}



//[left,right]
//void QuickSort(int* a,int left, int right)
//{
//	
//	if (left < right)
//	{
//		int pos = GetKey(a, left, right);
//        
//		QuickSort(a, left, pos-1);
//		QuickSort(a, pos + 1, right);
//	}	
//}



void Merge(int* a, int* tmp, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = start;

	while ((i < mid + 1) && (j < end + 1))
	{
		while ((a[i] <= a[j]) && (i < mid + 1))
		{
			tmp[k++] = a[i++];
		}
		while ((a[i] > a[j]) && (j < end + 1))
		{
			tmp[k++] = a[j++];
		}
	}

	while (i < mid + 1)
	{
		tmp[k++] = a[i++];
	}
	while (j < end + 1)
	{
		tmp[k++] = a[j++];
	}

	for ( i = start; i < k; i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int* tmp, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(a, tmp, start, mid);
		MergeSort(a, tmp, mid + 1, end);
		Merge(a, tmp, start, mid, end);
	}
	
}



int GetCount(int* a,int size)
{
	int j = 10;
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		if (a[i]>j)
		{
			j *= 10;
			count++;
		}
	}

	return count;
}


//基数排序
void LSD(int* a,int size)
{
	int count = GetCount(a, size);

	int* arr = new int[size];
	 
	int *Count = new int[10];
	int *Start = new int[10];
	memset(Count, 0, sizeof(int)* 10);
	memset(Start, 0, sizeof(int)* 10);

	//统计个数
	int i = 0;
	int tmp = 1;

	while (count)
	{
		for (i = 0; i < size; i++)
		{
			Count[((a[i]) / (tmp)) % 10]++;
		}

		Start[0] = 0;
		for (i = 1; i < size; i++)
		{
			Start[i] = Start[i - 1] + Count[i - 1];
		}

		for (i = 0; i < size; i++)
		{
			int index = Start[(a[i] / tmp) % 10];
			Start[(a[i] / tmp) % 10]++;
			Count[(a[i] / tmp) % 10]--;
			arr[index] = a[i];
		}

		memcpy(a, arr, sizeof(int)*size);

		tmp *= 10;
		count--;
	}

	delete[] arr;
	delete[] Start;
	delete[] Count;
		
}

//
////计数排序
void CountSort(int*a, int size, int left, int right)
{
	int Max = 0;
	int Min = 0;

	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (a[i]>Max)
			Max = a[i];

		if (a[i] < Min)
			Min = a[i];
	}

	int length = Max - Min + 1;
	int *tmp = new int[length];
	memset(tmp, 0, sizeof(int)*length);

	for (i = 0; i < size; i++)
	{
		tmp[a[i] - Min]++;
	}

	int index = 0;
	for (i = 0; i < length; i++)
	{
		while (tmp[i] != 0)
		{
			a[index++] = Min + i;
			tmp[i]--;
		}
	}


}

void Print(int* a,size_t n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


