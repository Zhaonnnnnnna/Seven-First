#include"Stack_Queue.h"


void test1()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	cout << s1;
	/*s1.Pop();
	cout << s1;
	bool ret = s1.Empty();
	cout << ret << endl;*/
	cout << s1.Top() << endl;
	size_t size = s1._Size();
	cout << size << endl;
}
void test2()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	cout << s1;
	Stack<int> s2 = s1;
	cout << s2;

	/*Stack<int> s3(s1);
	cout << s3;*/
}

void test3()
{
	Queue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	cout << q1;
	q1.Pop();
	cout << q1;
}
void test4()
{
	Queue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	cout << q1;
	//cout << q1.Empty() << endl;
	/*cout << q1.Front() << endl;
	cout << q1.Rear() << endl;*/
	/*Queue<int> q2(q1);
	cout << q2;*/
	Queue<int> q3 = q1;
	cout << q3;
}

long long Fib(size_t n)
{
	if (n < 2)
	{
		return n;
	}
	long long First = 0;
	long long Second = 1;
	long long ret = 0;
	for (size_t i = 2; i <= n; i++)
	{
		ret = First + Second;
		First = Second;
		Second = ret;
	}
	return ret;
}
int main()
{
	test2();
	//long long ret = Fib(5);
	//cout << ret << endl;
	getchar();
	return 0;
}