#include"HashTableBucket.h"

void test1()
{
	HashTableBucket<int, int> ht;
	ht.Insert(1, 1);
	ht.Insert(2, 2);
	ht.Insert(3, 3);
	ht.Insert(4, 4);
	ht.Print();

	/*ht.Remove(1);
	ht.Print();*/

	/*HashTableBucket<int, int> ht1(ht);
	ht1.Print();*/


	HashTableBucket<int, int> ht1;
	ht1.Insert(5, 5);
	ht1.Insert(6, 6);
	ht1.Insert(7, 7);
	ht1 = ht;
	ht1.Print();
}

void test2()
{
	HashTableBucket<string, string> ht;
	ht.Insert("¸¶Ü°","ÖÇÕÏ");
	ht.Insert("Ã«É©","Éµ±Æ");
	ht.Insert("ºîÈï","Éñ¾­");
	ht.Print();

	ht.Remove("¸¶Ü°");
	ht.Print();

}

int main()
{
	test3();
	getchar();
	return 0;
}