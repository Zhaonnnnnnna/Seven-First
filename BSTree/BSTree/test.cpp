#include"BSTree.h"


void test()
{
	/*BSTree<int, int> bt;
	bt.Insert(5, 0);
	bt.Insert(3, 1);
	bt.Insert(4, 2);
	bt.Insert(1, 3);
	bt.Insert(7, 4);
	bt.Insert(8, 5);
	bt.Insert(2, 6);
	bt.Insert(6, 7);
	bt.Insert(0, 8);
	bt.Insert(9, 9);


	bt.InOrder();
	cout << endl;*/

	BSTree<int, int> bt;
	bt.InsertR(5, 0);
	bt.InsertR(3, 1);
	bt.InsertR(4, 2);
	bt.InsertR(1, 3);
	bt.InsertR(7, 4);
	bt.InsertR(8, 5);
	bt.InsertR(2, 6);
	bt.InsertR(6, 7);
	bt.InsertR(0, 8);
	bt.InsertR(9, 9);


	bt.InOrder();
	cout << endl;

	//BSTreeNode<int, int>* ret = bt.Find(2);
	//cout << ret->_key << endl;

	//BSTreeNode<int, int>* ret = bt.FindR(2);
	//cout << ret->_key << endl;

	//int h = bt.Height(bt.GteRoot());
	//cout << h << endl;

	//cout << bt.IsBlanceTree() << endl;

	/*bt.Remove(0);
	bt.Remove(1);
	bt.Remove(7);
	bt.InOrder();
	cout << endl;*/

	/*bt.Remove(0);
	bt.Remove(1);
	bt.Remove(2);
	bt.Remove(3);
	bt.Remove(4);
	bt.Remove(5);
	bt.Remove(6);
	bt.Remove(7);
	bt.Remove(8);
	bt.Remove(9);
	bt.InOrder();*/

	bt.ToMirror();

	////bt.RemoveR(0);
	//bt.RemoveR(1);
	//bt.RemoveR(2);
	//bt.RemoveR(3);
	//bt.RemoveR(4);
	//bt.RemoveR(5);
	//bt.RemoveR(6);
	//bt.RemoveR(7);
	//bt.RemoveR(8);
	//bt.RemoveR(9);
	//bt.InOrder();

}
int main()
{
	test();
	getchar();
	return 0;
}