#include"Stack.h"

void test1()
{
	Stack<int> s1;
	s1.Push(5);
	s1.Push(2);
	s1.Push(7);
	s1.Push(8);
	s1.Push(0);
	s1.Pop();
	s1.Pop();
	cout << s1.Min() << endl;
}

void test2()
{
	ComplexSlist<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	s1.Print();
	s1.InitRandom(2, 1);
	s1.InitRandom(3, 5);
	s1.Print();
	ComplexSlist<int> s2;
	s2=CloneSlist(s1);
	s2.Print();
}
int main()
{
	test2();
	getchar();
	return 0;
}