#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>



typedef int DateType;
typedef struct LinkNode
{
	DateType data;
	struct LinkNode *next;
}LinkNode, *pLinkNode, *pList;

void InitLinkList(pList *pHead);
void Destory(pList *pHead);
void PushBack(pList *pHead, DateType x);
void PopBack(pList *pHead);
void PushFront(pList *pHead, DateType x);
void PopFront(pList *pHead);
void PrintList(pList list);
int GetListLength(pList head);
pLinkNode Find(pList *pHead, pLinkNode pos, DateType x);
void Insert(pList *pHead, pLinkNode pos, DateType x);
void Remove(pList *pHead, DateType x);
void RemoveAll(pList *pHead, DateType x);
void Erase(pList *pHead, pLinkNode pos);
pLinkNode BuyNode(DateType x);
void EraseNotTail(pLinkNode pos);
void ReverseList(pList *pHead);
void Bubblesort(pList *pHaed);
void InsertFrontNode(pLinkNode pos, DateType x);
pLinkNode Merge(pList l1, pList l2);

void InitLinkList(pList *pHead)
{
	assert(pHead);
	*pHead = NULL;
}

void Destory(pList *pHead)
{
	pLinkNode cur = *pHead;
	while (cur)
	{
		pLinkNode del = cur;
		cur = cur->next;
		delete del;
		del = NULL;
	}
	pHead = NULL;
}

pLinkNode BuyNode(DateType x)
{
	pLinkNode newnode = (pLinkNode)malloc(sizeof(LinkNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void PushBack(pList *pHead, DateType x)
{
	pLinkNode newnode = BuyNode(x);
	pLinkNode cur = *pHead;
	if (*pHead == NULL)
	{
		*pHead = newnode;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}
void PopBack(pList *pHead)
{
	pLinkNode cur = *pHead;
	pLinkNode del;
	if (*pHead == NULL)
	{

	}
	else if (cur->next == NULL)
	{
		del = *pHead;
		*pHead = NULL;
		free(del);
	}
	else
	{
		while (cur->next->next)
		{
			cur = cur->next;
		}
		del = cur->next;
		cur->next = NULL;
		free(del);
	}
}
void PushFront(pList *pHead, DateType x)
{
	pLinkNode newnode = BuyNode(x);
	if (*pHead == NULL)
	{
		*pHead = newnode;
	}
	else
	{
		newnode->next = *pHead;
		*pHead = newnode;
	}
}
void PopFront(pList *pHead)
{
	pLinkNode del;
	pLinkNode cur = *pHead;
	if (*pHead == NULL)
	{

	}
	else if (cur->next == NULL)
	{
		del = *pHead;
		*pHead = NULL;
		free(del);
	}
	else
	{
		del = *pHead;
		*pHead = cur->next;
		free(del);
	}
}
void PrintList(pList list)
{
	pLinkNode cur = list;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}


int GetListLength(pList head)
{
	int count = 0;
	pLinkNode cur = head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

pLinkNode Find(pList head, DateType x)
{
	pLinkNode cur = head;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
}


void Insert(pList *pHead, pLinkNode pos, DateType x)
{
	pLinkNode newnode = BuyNode(x);
	pLinkNode cur = *pHead;
	while ((cur->next) != pos)
	{
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;

}


void Remove(pList *pHead, DateType x)
{
	pLinkNode cur = *pHead;
	pLinkNode del;
	while (cur)
	{
		if (cur->next->data == x)
		{
			del = cur->next;
			cur->next = cur->next->next;
			free(del);
			return;
		}
		cur = cur->next;
	}
}


//void RemoveAll(pList *pHead, DateType x)
//{
//	pLinkNode cur = *pHead;
//	pLinkNode pos;
//	pLinkNode del;
//	while (cur)
//	{
//		if (cur->next->data == x)
//		{
//			del = cur->next;
//			cur->next = cur->next->next;
//		
//			free(del);
//		}
//		cur = cur->next;
//
//	}
//}


void Erase(pList *pHead, pLinkNode pos)
{
	pLinkNode cur = *pHead;
	pLinkNode del;
	while ((cur->next) != pos)
	{
		cur = cur->next;
	}
	del = cur->next;
	cur->next = cur->next->next;
	free(del);
}

void EraseNotTail(pLinkNode pos)
{
	pLinkNode del = pos->next;
	pos->data = pos->next->data;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void ReverseList(pList *pHead)
{
	pLinkNode pNewHead = NULL;
	pLinkNode cur = *pHead;
	pLinkNode prev = NULL;
	if (cur == NULL)
	{
		return;
	}
	if (cur->next == NULL)
	{
		return;
	}
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		prev->next = pNewHead;
		pNewHead = prev;
	}
	*pHead = pNewHead;
}

void Bubblesort(pList *pHead)
{
	pLinkNode cur = *pHead;
	pLinkNode end = NULL;
	while (cur != end)
	{
		while (cur && (cur->next != end))
		{
			if (cur->data > cur->next->data)
			{
				DateType tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
		}
		end = cur;
		cur = *pHead;

	}
}
void InsertFrontNode(pLinkNode pos, DateType x)
{
	pLinkNode newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
	DateType tmp = pos->data;
	pos->data = newnode->data;
	newnode->data = tmp;
}

pLinkNode Merge(pList l1, pList l2)
{
	pLinkNode cur;
	pList newHead = NULL;
	if (l1->data > l2->data)
	{
		newHead = l2;
		l2 = l2->next;
	}
	if (l1->next < l2->next)
	{
		newHead = l1;
		l1 = l1->next;
	}
	cur = newHead;
	while (l1&&l2)
	{
		if (l1->data < l2->data)
		{
			cur->next = l1;
			l1 = l1->next;
		}
		if (l1->data>l2->data)
		{
			cur->next = l2;
			l2 = l2->next;
		}
	}
	if (l1)
	{
		cur->next = l1;
	}
	if (l2)
	{
		cur->next = l2;
	}
	return newHead;
}




#endif __LINK_LIST_H__
