#include"Sort.h"


void TestInsertSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));

}

void TestShellSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));

}



void TestHeapSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));

}

void TestSelectSort()
{
	/*int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };*/
	int a[] = { 9, 5, 4, 2, 3, 6, 8, 7, 1, 0 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));

}

void TestBubbleSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));

}

void TestQuickSort()
{
	int a[] = { 1, 5, 4, 9, 3, 6, 8, 7, 0, 2 };
	QuickSort(a, 0, (sizeof(a) / sizeof(a[0])-1));
	Print(a, sizeof(a) / sizeof(a[0]));

}

void TestMergeSort()
{
	int a[] = { 1, 5, 4, 9, 3, 6, 8, 7, 0, 2 };
	int *tmp = (int *)malloc(sizeof(a) / sizeof(a[0]));
	MergeSort(a, tmp, 0, (sizeof(a) / sizeof(a[0]) - 1));
	Print(a, sizeof(a) / sizeof(a[0]));

}

void TestCountSort()
{
	/*int a[] = { 1, 5, 4, 9, 3, 6, 8, 7, 0, 2 };*/
	int a[] = { 1, 5, 4, 5, 3, 6, 8, 5, 0, 2 };
	CountSort(a, (sizeof(a) / sizeof(a[0])), 0, (sizeof(a) / sizeof(a[0]) - 1));
	Print(a, sizeof(a) / sizeof(a[0]));

}

void TestLSD()
{
	int a[] = { 1, 5, 16, 9, 131, 26, 8, 7, 0, 22 };
	LSD(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));

}


int main()
{
	
	//TestInsertSort();
	//TestHeapSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestShellSort();
	//TestQuickSort();
	//TestMergeSort();
	//TestCountSort();
	TestLSD();
	getchar();
	return 0;
}