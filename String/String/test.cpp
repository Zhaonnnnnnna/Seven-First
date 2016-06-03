#include"String.h"

int  main()
{
	String str1("hello");
	String str2(str1);
	/*cout << str1;
	cout << str2;
	String str3("bit");
	str1 = str3;
	cout << str1;*/
	str2[1] = 'o';
	cout << str2;
	cout << str1;
	getchar();
	return 0;
}