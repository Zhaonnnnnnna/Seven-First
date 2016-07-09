#include"RBTree.hpp"


void TestRBTree()
{
	RBTree<int, int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << "是否满足条件？" << t.CheckRETree() << endl;
		t.Insert(a[i], i);
	}

	cout << "是否满足条件？" << t.CheckRETree() << endl;

}

void TestRBTree1()
{
	RBTree<int, int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << "是否满足条件？" << t.CheckRETree() << endl;
		t.Insert(a[i], i);
	}

	cout << "是否满足条件？" << t.CheckRETree() << endl;
	cout << "key:" << t.Find(0)<< endl;

}

int main()
{
	TestRBTree1();
	getchar();
	return 0;
}