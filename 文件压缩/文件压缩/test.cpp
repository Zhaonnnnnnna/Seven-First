#include"Heap.h"
#include"HuffmanTree.h"
#include<time.h>

void TestHeap()
{
	int p[10] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	Heap<int> hp1(p, 10);
	hp1.Print();
}

void TestHuffmanTree()
{
	int p[] = { 4, 5, 2, 3, 10, 1, 9, 7, 8, 6,0 };
	HuffmanTree<int> huff(p, sizeof(p)/sizeof(p[0]),0);

}

void TestCompress()
{
	int p[] = { 4, 5, 2, 3, 10, 1, 9, 7, 8, 6, 0 };
	FileCompress<CharInfo> ft;
	ft.Compress("pic");
}

void TestUnCompress()
{
	FileCompress<CharInfo> ft;
	ft.UnCompress("pic.Huffman");
}

void TestByte()
{
	char c = 0;
	c = c | 1;
	c=c << 3;
}



int main()
{
	//TestHeap();

	//TestHuffmanTree();
	/*time_t start;
	time_t end;
	time(&start);
	TestCompress();
	TestUnCompress();
	time(&end);
	cout << difftime(end, start) << endl;*/

	clock_t  a = clock();
	TestCompress();
	clock_t  b = clock();
	cout << "压缩时间：" << (b - a) / 1000 << "s" << endl;
	clock_t  c = clock();
	TestUnCompress();
	clock_t  d = clock();
	cout << "解压时间：" << (d - c) / 1000 << "s" << endl;
	getchar();



	//TestByte();
	getchar();
	return 0;
}