#include"BinaryTreeThd.h"

void Test1()
{
	int p[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTreeThd<int> b1(p, 10, '#');
	b1.InOrderThreading();
	b1.InOrderThd();
}
void Test2()
{
	int p[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int p1[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	BinaryTreeThd<int> b1(p, 10, '#');
	b1.PrevOrderThreading();
	b1.PrevOrderThd();
	BinaryTreeThd<int> b2(p1, 15, '#');
	b2.PrevOrderThreading();
	b2.PrevOrderThd();
	BinaryTreeThd<int> b3(p1, 15, '#');
	b3.InOrderThreading();
	b3.InOrderThd();
	//b1.PostOrderThreading();
}

int main()
{
	Test1();
	//Test2();
	getchar();
	return 0;
}