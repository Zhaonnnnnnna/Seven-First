#include<stdio.h>
#include"LinkList.h"

void Test1()
{
	pLinkNode mylist;
	InitLinkList(&mylist);
	PushBack(&mylist, 3);
	PrintList(mylist);
	PopBack(&mylist);
	PrintList(mylist);
}

void Test2()
{
	pLinkNode mylist;
	InitLinkList(&mylist);
	PushBack(&mylist, 3);
	PushBack(&mylist, 1);
	PushBack(&mylist, 5);
	PrintList(mylist);
	PushFront(&mylist, 2);
	PushFront(&mylist, 4);
	PopFront(&mylist);
	PrintList(mylist);
}

void Test3()
{
	pLinkNode mylist;
	pLinkNode pos;
	int ret = 0;
	InitLinkList(&mylist);
	PushBack(&mylist, 3);
	PushBack(&mylist, 1);
	PushBack(&mylist, 5);
	PrintList(mylist);
	PushFront(&mylist, 2);
	PushFront(&mylist, 4);
	PopFront(&mylist);
	PrintList(mylist);
	ret = GetListLength(mylist);
	printf("%d\n", ret);
	pos = Find(mylist, 2);
	printf("%d\n", pos->data);
}

void Test4()
{
	pLinkNode mylist;
	pLinkNode ret;
	InitLinkList(&mylist);
	PushBack(&mylist, 3);
	PushBack(&mylist, 1);
	PushBack(&mylist, 5);
	PrintList(mylist);
	PushFront(&mylist, 2);
	PushFront(&mylist, 4);
	PrintList(mylist);
	ret = Find(mylist, 2);
	Insert(&mylist, ret, 3);
	PrintList(mylist);
	//Remove(&mylist, 2);
	//RemoveAll(&mylist, 3);
	Erase(&mylist, ret);
	PrintList(mylist);
}

void Test5()
{
	pLinkNode mylist;
	pLinkNode ret;
	InitLinkList(&mylist);
	PushBack(&mylist, 2);
	PushBack(&mylist, 1);
	PushBack(&mylist, 4);
	PushBack(&mylist, 3);
	PushBack(&mylist, 5);
	PrintList(mylist);
	ret = Find(mylist, 2);
	//EraseNotTail(ret);
	InsertFrontNode(ret, 8);
	PrintList(mylist);
}

void Test6()
{
	pLinkNode l1;
	InitLinkList(&l1);
	PushBack(&l1, 2);
	PushBack(&l1, 4);
	PushBack(&l1, 6);
	PushBack(&l1, 8);
	PrintList(l1);
	pLinkNode l2;
	pLinkNode l;
	InitLinkList(&l2);
	PushBack(&l2, 1);
	PushBack(&l2, 3);
	PushBack(&l2, 5);
	PushBack(&l2, 7);
	PrintList(l2);
	l = Merge(l1, l2);
	PrintList(l);
	Destory(&l1);
}
int main()
{
	Test6();
	system("pause");
	return 0;
}