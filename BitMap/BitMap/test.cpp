#include"BitMap.h"


void test1()
{
	BitMap bp(10);
	bp.Set(1);
	bp.Set(2);
	bp.Set(3);

	cout << "1?" << bp.Test(1) << endl;
	bp.Reset(1);

	cout << "1?" << bp.Test(1) << endl;

}

void test2()
{
	BloomFilter bf(100);
	bf.Set("BloomFilter1");
	bf.Set("BloomFilter2");
	bf.Set("BloomFilter3");
	bf.Set("BloomFilter4");
	bf.Set("BloomFilter5");

	cout << "BloomFilter1:?" << bf.Test("BloomFilter1") << endl;
	cout << "BloomFilter2:?" << bf.Test("BloomFilter2") << endl;
	cout << "BloomFilter3:?" << bf.Test("BloomFilter3") << endl;
	cout << "BloomFilter4:?" << bf.Test("BloomFilter4") << endl;
	cout << "BloomFilter6:?" << bf.Test("BloomFilter6") << endl;

}

int main()
{
	test2();
	getchar();
	return 0;
}