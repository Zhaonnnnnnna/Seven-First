#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"


void menu()
{
	printf("***************************************\n");
	printf("              ͨѶ¼                   \n");
	printf("            1.���                     \n");
	printf("            2.ɾ��                     \n");
	printf("            3.����                     \n");
	printf("            4.�޸�                     \n");
	printf("            5.��ʾ                     \n");
	printf("            6.���                     \n");
	printf("            7.����������               \n");
	printf("            0.EXIT                     \n");
	printf("***************************************\n");
}

void test()
{
	contact mycon;
	init_contact(&mycon);
	int input = 1;

	while (input)
	{
		menu();
		printf("������ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&mycon);
			break;
		case DEL:
			del_contact(&mycon);
			break;
		case SHOW:
			show_contact(&mycon);
			break;
		case SEARCH:
			search_contact(&mycon);
			break;
		case MODIFY:
			modify_contact(&mycon);
			break;
		case CLEAR:
			clear_contact(&mycon);
			break;
		case SORT:
			sort_contact(&mycon);
			break;
		case EXIT:
			exit(0);
			break;
		default:
			break;
		}
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}