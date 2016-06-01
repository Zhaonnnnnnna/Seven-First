#include"BinaryTree.h"
#include<stdlib.h>
#include<assert.h>

//void test1()
//{
//	int p[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
//	BinaryTree<int> b1(p, 10, '#');
//	b1.PrevOrder();
//}
//
//void test2()
//{
//	int p[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
//	BinaryTree<int> b1(p, 10, '#');
//	BinaryTree<int> b2(b1);
//	BinaryTree<int> b3;
//	b3 = b1;
//	b3.PrevOrder();
//	b3.InOrder();
//	b3.PostOrder();
//	cout << b3.Size() << endl;
//	cout << b3.Depth() << endl;
//	cout << b3.LeafSize() << endl;
//	b3.LevelOrder();
//
//}
void test3()
{
	int p[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> b1(p, 10, '#');
	b1.PrevOrder_NonR();
	cout << endl;
	b1.InOrder_NonR();
	cout << endl;
	b1.PostOrder_NonR();
	cout << b1.Find(2) << endl;
	cout << b1.GetKLevel(3) << endl;

}


int main()
{
	test3();
	getchar();
	return 0;
}