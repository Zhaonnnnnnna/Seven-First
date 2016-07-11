#include"AVLTree.hpp"

void test()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	AVLTree<int, int> al;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		al.Insert(a[i], a[i]);
	}

	al.InOrder();
	cout << endl;
/*
	AVLTreeNode<int, int>* ret = al.Find(15);
	cout << ret->_key << endl;


	al.Remove(11);
	al.Remove(26);
	al.InOrder();
	cout << endl;*/

	cout << al.IsBlanceTree() << endl;
}				 


int main()
{
	test();
	getchar();
	return 0;
}
