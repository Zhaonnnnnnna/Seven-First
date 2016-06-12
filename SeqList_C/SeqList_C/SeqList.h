#ifndef __SEQ_LIST_H__
#define	 __SEQ_LIST_H__
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int DataType;
#define MAX 1000
typedef struct Seqlist
{
	DataType data[MAX];
	int size;
}SeqList, *pSeqList;


void InitSeqList(pSeqList pSeq)
{
	assert(pSeq);
	memset(pSeq->data, 0, MAX*sizeof(DataType));
	pSeq->size = 0;
}

void PrintSeqList(SeqList Seq)
{
	int i = 0;
	for (i = 0; i < Seq.size; i++)
	{
		printf("%d", Seq.data[i]);
	}
	printf("\n");
	printf("over\n");
}

void PushBack(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	if (MAX == pSeq->size)
	{
		printf("顺序表已满");
	}
	pSeq->data[pSeq->size] = x;
	pSeq->size++;
}

void PopBack(pSeqList pSeq)
{
	assert(pSeq);
	if (0 == pSeq->size)
	{
		printf("顺序表已空");
	}
	pSeq->size--;
}

void PushFront(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	if (MAX == pSeq->size)
	{
		printf("顺序表已满");
	}
	int i = 0;
	for (i = pSeq->size; i >= 0; i--)
	{
		pSeq->data[i] = pSeq->data[i - 1];
	}
	pSeq->data[0] = x;
	pSeq->size++;
}

void PopFront(pSeqList pSeq)
{
	assert(pSeq);
	if (0 == pSeq->size)
	{
		printf("顺序表已空");
	}
	int i = 0;
	for (i = 0; i < pSeq->size; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;
}
int Find(SeqList Seq, DataType x)
{
	int i = 0;
	for (i = 0; i < Seq.size; i++)
	{
		if (Seq.data[i] == x)
		{
			return i;
			break;
		}
	}
	return NULL;
}

void Insert(pSeqList pSeq, int pos, DataType x)
{
	assert(pSeq);
	int i = 0;
	for (i = pSeq->size; i<pos; i--)
	{
		pSeq->data[i] = pSeq->data[i - 1];
	}
	pSeq->data[pos] = x;
	pSeq->size++;
}

void Remove(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	int pos = 0;
	int i = 0;
	pos = find(*pSeq, x);
	for (i = pos; i < pSeq->size; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;
}
int Findcount(SeqList Seq, DataType x)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < Seq.size; i++)
	{
		if (Seq.data[i] == x)
		{
			count++;
		}
	}
	return count;
}

void RemoveAll(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	int i = 0;
	int pos = 0;
	int count = Findcount(*pSeq, x);
	while (count)
	{
		pos = Find(*pSeq, x);
		for (i = pos; i < pSeq->size; i++)
		{
			pSeq->data[i] = pSeq->data[i + 1];
		}
		count--;
		pSeq->size--;
	}
}

void ReverseList(pSeqList pSeq)
{
	assert(pSeq);
	int left = 0;
	int right = pSeq->size - 1;
	DataType tmp = 0;
	while (left < right)
	{
		tmp = pSeq->data[left];
		pSeq->data[left] = pSeq->data[right];
		pSeq->data[right] = tmp;
		left++;
		right--;
	}
}

void SortList(pSeqList pSeq)
{
	assert(pSeq);
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->size - 1; i++)
	{
		for (j = 0; j < pSeq->size - 1 - i; j++)
		{
			if (pSeq->data[j]>pSeq->data[j + 1])
			{
				DataType tmp = pSeq->data[j];
				pSeq->data[j] = pSeq->data[j + 1];
				pSeq->data[j + 1] = tmp;
			}
		}
	}

}

void BinarySearch(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	int start = 0;
	int end = pSeq->size - 1;
	int mid = 0;
	SortList(pSeq);
	mid = (start + end) / 2;
	while ((start < end) && (x != pSeq->data[mid]))
	{
		if (x>pSeq->data[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}
	if (x == pSeq->data[mid])
	{
		printf("找到了");
	}
	else
	{
		printf("没找到");
	}
}
#endif __SEQ_LIST_H__