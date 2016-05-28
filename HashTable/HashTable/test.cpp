#include"HashTable.h"

void test1()
{
	frist::HashTable<int> ht;
	ht.Insert(1);
	ht.Insert(2);
	ht.Insert(3);
	ht.Insert(4);
	ht.Insert(5);
	ht.Print();
}

void test2()
{
	frist::HashTable<int> ht;
	ht.Insert(1);
	ht.Insert(2);
	ht.Insert(3);
	ht.Insert(4);
	ht.Insert(5);
	ht.Print();

	//cout << ht.Find(2) << endl;
	cout << ht.Find(8) << endl;

	ht.Remove(4);
	ht.Print();
}

void test3()
{
	frist::HashTable<int> ht;
	ht.Insert(1);
	ht.Insert(2);
	ht.Insert(3);
	ht.Insert(4);
	ht.Insert(5);
	ht.Print();

	frist::HashTable<int> ht1(ht);
	ht1.Print();
}

void test4()
{
	frist::HashTable<int> ht;
	ht.Insert(1);
	ht.Insert(2);
	ht.Insert(3);
	ht.Insert(4);
	ht.Insert(5);
	//ht.Print();

	frist::HashTable<int> ht1;
	ht1.Insert(6);
	ht1.Insert(7);
	ht1.Insert(8);
	ht1.Insert(9);

	ht = ht1;
	ht.Print();
	/*ht.Print();*/

	/*frist::HashTable<int> ht1(ht);
	ht1.Print();*/
}


void test5()
{
	second::HashTable<int,int> ht;
	ht.Insert(1,1);
	ht.Insert(2,2);
	ht.Insert(3,3);
	ht.Insert(4,4);
	ht.Insert(5,5);
	ht.Print();

	//find(1);

}

void test6()
{
	second::HashTable<string, string> ht;
	ht.Insert("sony","Ë÷Äá");
	ht.Insert("apple","Æ»¹û");
	ht.Insert("acer","ºê³ž");
	ht.Print();

	/*second::HashTable<string, string> ht1;
	ht1.Insert("qwwjregtnj", "Ë÷Äá");
	ht1.Insert("snfdfkjgnj", "Æ»¹û");
	ht1.Insert("fhj", "ºê³ž");

	ht1 = ht;
	ht1.Print();*/

	ht.Remove("sony");
	ht.Print();
	

}

int main()
{
	test6();

	getchar();
	return 0;
}