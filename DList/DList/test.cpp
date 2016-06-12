#include"DList.h"


void Test1()
{
	DList d1;
	d1.PushBack(1);
	d1.PushBack(2);
	d1.PushBack(3);
	d1.PushBack(4);
	cout << d1;
	d1.PopBack();
	cout << d1;
	Node *cur = d1.Find(3);
	cout << cur << endl;
	d1.Insert(cur, 5);
	cout << d1;
}

void Test2()
{
	DList d1;
	d1.PushFront(1);
	d1.PushFront(2);
	d1.PushFront(3);
	d1.PushFront(4);
	cout << d1;
	d1.PopFront();
	cout << d1;
}

void Test3()
{
	DList d1;
	d1.PushFront(1);
	d1.PushFront(2);
	d1.PushFront(3);
	d1.PushFront(4);
	cout << d1;
	//d1.Reverse();
	d1.Sort();
	cout << d1;
}

void Test4()
{
	DList d1;
	d1.PushFront(1);
	d1.PushFront(2);
	d1.PushFront(3);
	d1.PushFront(4);
	d1.PushFront(2);
	d1.PushFront(3);
	d1.PushFront(4);
	cout << d1;
	//d1.Remove(2);
	d1.RemoveAll(2);
	cout << d1;
}

void Test5()
{
	DList d1;
	d1.PushFront(1);
	d1.PushFront(2);
	d1.PushFront(3);
	d1.PushFront(4);
	cout << d1;
	DList d2;
	d2.PushFront(5);
	d2.PushFront(6);
	d2.PushFront(7);
	d2.PushFront(8);
	cout << d2;
	d2 = d1;
	cout << d2;
}
int main()
{
	Test5();
	getchar();
	return 0;
}