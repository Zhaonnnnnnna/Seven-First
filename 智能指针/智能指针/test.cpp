#define _CRT_SECURE_NO_WARNINGS


#include"SmartPtr.h"
using namespace std;

void test1(){
	int *p1 = new int(1);
	int *p2 = new int(5);
	AutoPtr<int> ap1(p1);
	*ap1 = 3;
	cout << (*ap1) << endl;
	AutoPtr<int> ap2(p2);
	AutoPtr<int> ap3(ap1);
	*ap2 = 10;
	cout << (*ap2) << endl;
	cout << (*ap3) << endl;
	*ap3 = 8;
	cout << (*ap3) << endl;
	AutoPtr<A> ap(new A);
	ap->_a = 1;
	cout << (ap->_a) << endl;

}

void test2()
{
	SharedPtr<int> sp1(new int(1));
	SharedPtr<int> sp2(sp1);

	SharedPtr<int, Free<int>> sp3((int*)malloc(sizeof(int)));
	SharedPtr<int, Free<int>> sp4(sp3);

	FILE *pf = fopen("test.txt", "w");
	SharedPtr<FILE, Fclose<FILE>> sp5(pf);
	SharedPtr<FILE, Fclose<FILE>> sp6(sp5);


	/*cout << (*sp1) << endl;
	cout << (*sp2) << endl;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp1.GetPtr() << endl;
	cout << sp2.GetPtr() << endl;
	SharedPtr<int> sp3(new int(2));
	sp3 = sp1;
	cout << (*sp3) << endl;
	cout << sp3.UseCount() << endl;
	cout << sp2.GetPtr() << endl;
	cout << sp3.GetPtr() << endl;
	cout << sp1.UseCount() << endl;*/
}
void test3()
{
	ScopedPtr<int> sp1(new int(1));
	ScopedPtr<A> sp2(new A);
	sp2->_a = 8;
	cout << (sp2->_a) << endl;
	cout << (*sp1) << endl;
	/*ScopedPtr<int> sp3(sp1);
	sp2 = sp1;*/
}

void test4()
{
	ScopedArr<int> sp1(new int[10]());
	ScopedArr<int> sp2(new int[5]());
	sp1[0] = 1;
	cout << sp1[0] << endl;
	/*sp2 = sp1;
	ScopedArr<int> sp3(sp1);*/


}

void test5()
{
	SharedArr<int> sp1(new int[10]());
	SharedArr<int> sp2(new int[5]());
	SharedArr<int> sp3(sp1);
	sp1[0] = 10;
	cout << sp1[0] << endl;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	cout << sp1.GetPtr() << endl;
	cout << sp2.GetPtr() << endl;
	cout << sp3.GetPtr() << endl;
	sp3 = sp2;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	cout << sp2.GetPtr() << endl;
	cout << sp3.GetPtr() << endl;


}
int main()
{
	test2();
	getchar();
	return 0;
}