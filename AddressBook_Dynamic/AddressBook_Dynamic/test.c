#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"


void menu()
{
	printf("***************************************\n");
	printf("              通讯录                   \n");
	printf("            1.添加                     \n");
	printf("            2.删除                     \n");
	printf("            3.查找                     \n");
	printf("            4.修改                     \n");
	printf("            5.显示                     \n");
	printf("            6.清空                     \n");
	printf("            7.以名字排序               \n");
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
		printf("请输入选择:");
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