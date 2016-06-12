#include"SeqList.h"


int main()
{
	SeqList s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);
	s.PushFront(7);
	s.PushFront(6);
	s.PushFront(7);
	s.PushFront(8);
	cout << s;
	s.PopBack();
	s.PopFront();
	cout << s;
	//s.Remove(7);
	//s.Insert(3, 5);
	/*bool ret=s.Find(7);
	cout << ret << endl;*/
	s.Reverse();
	cout << s;
	s[1] = 0;
	cout << s;
	getchar();
	return 0;
}