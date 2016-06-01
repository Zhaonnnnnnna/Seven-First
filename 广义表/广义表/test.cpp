#include"Generalized.h"

void test1()
{
	char *str = "(1,2,(3,4),5)";
	Generalized g1(str);
	Generalized g2(g1);
	g1.Print();
	size_t count = g1.Size();
	cout << count << endl;
	size_t dep = g1.Depth();
	cout << dep << endl;
}

void test2()
{
	char *str = "(1,(2),5,(3,(1)))";
	Generalized g1(str);
	g1.Print();
	size_t dep = g1.Depth();
	cout << dep << endl;
}
int main()
{
	test2();
	getchar();
	return 0;
}