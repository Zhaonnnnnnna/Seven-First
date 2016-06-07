#include"Date.h"

int main()
{
	int yy, mm, dd;
	cin >> yy >> mm >> dd;
	Date d1(yy, mm, dd);
	d1.Display();
	/*int x = 0;
	cin >> x;
	d1 = d1 + x;
	d1.Display();*/
	cin >> yy >> mm >> dd;
	Date d2(yy, mm, dd);
	d2 = d1 + d2;
	d2.Display();
	system("pause");
	return 0;
}