#include"DList.h"

void Test1()
{
	DList<int> d1;
	d1.PushBack(1);
	d1.PushBack(4);
	d1.PushBack(1);
	d1.PushBack(4);
	d1.PushBack(5);
	//cout << d1;

	/*d1.PopBack();
	d1.Print();*/
	/*d1.PushFront(6);*/
	/*d1.PopFront();
	cout << d1;
	Node<int> *cur = d1.Find(3);
	cout << cur->_data << endl;
	d1.Insert(cur, 8);
	cout << d1;*/
	/*d1.Reverse();*/
	//d1.Sort();
	d1.RemoveAll(1);
	//cout << d1;
}


int main()
{

	Test1();
	system("pause");
	return 0;
}
