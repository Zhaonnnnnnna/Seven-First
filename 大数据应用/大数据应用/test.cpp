#include"BigData.h"

void test1()
{
	BigData b(12345678967890);
	cout << b << endl;

	//BigData BigData2((long long)(9223372036854775800)‬);


	BigData b1("12345678967890");
	cout << b1 << endl;

	//BigData b("+aaaaaaaaaaaaa678967890");
	//cout << b << endl;

	/*BigData b("-12345aaaaaaaaaaaaa678967890");
	cout << b << endl;*/

    //char *p = "1234567";

	/*string s("123456789");
	BigData b(s);
	cout << b << endl;*/
}


void TestADD()
{
	/*BigData BigData1("1111111111111111111111111111111111");
	BigData BigData2(9223372036854775807);*/

	BigData BigData1("-99999999999999999999999999999999999999999999");
	BigData BigData2(-999);

	/*BigData BigData1("101010010101010101010101010101010101001010101");
	BigData BigData2(999);*/
	
	BigData b (BigData1 + BigData2);

	cout << b << endl;
}

void TestSUB()
{
	/*BigData BigData1("222222");
	BigData BigData2("44444444444444444444");
	BigData b(BigData1 - BigData2);*/

	////BigData BigData1((INT64)-9223372036854775808);
	//BigData BigData2("10");
	//BigData b(BigData1 - BigData2);
	//cout << b << endl;

	/*BigData BigData1("-44");
	BigData BigData2("22");*/

	BigData BigData1("-9223372036854775808‬");
	BigData BigData2("22");
	BigData b1(BigData1 - BigData2);

	cout << b1 << endl;
}

void TestMUL()
{
	/*BigData BigData1("444444444444444444");
	BigData BigData2("22");
	BigData b(BigData1 * BigData2);*/

	BigData BigData1("-999999999999999999990999999999999999999999");
	BigData BigData2("99");
	BigData b(BigData1 * BigData2);


	cout << b << endl;

}

void TestDIV()
{
	/*BigData BigData1("2222222222222222222222222222222");
	BigData BigData2("33");
	BigData b(BigData1 / BigData2);*/

	/*BigData BigData1("2222222222222222222220000000000000000000000");
	BigData BigData2("33");
	BigData b(BigData1 / BigData2);*/

	BigData BigData1("222222220000000000000000000222222222222222222222222222222");
	BigData BigData2("33");
	BigData b(BigData1 / BigData2);


	cout << b << endl;
}


int main()
{
	//test1();

   // TestADD();

	//TestSUB();

	//TestMUL();

	//Test();

	TestDIV();
	getchar();
	return 0;
}
