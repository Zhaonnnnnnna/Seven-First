#include"Heap.h"

void test1()
{
	int p[10] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	Heap<int> hp1(p, 10);
	hp1.Push(18);
	hp1.Pop();
}

int main()
{
	test1();
	getchar();
	return 0;
}