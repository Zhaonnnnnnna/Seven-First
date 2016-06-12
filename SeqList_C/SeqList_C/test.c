#include<stdio.h>
#include"SeqList.h"

void Test1()
{
	SeqList myseq;
	InitSeqList(&myseq);
	PrintSeqList(myseq);
}

int main()
{
	Test1();
	system("pause");
	return 0;
}