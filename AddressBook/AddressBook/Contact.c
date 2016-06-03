#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"


void init_contact(contact *pcon)
{
	pcon->count = 0;
}
void add_contact(contact *pcon)
{
	if (pcon->count >= MAX)
	{
		printf("电话本已满，无法添加");
		return;
	}
	printf("请输入名字：");
	scanf("%s", pcon->con[pcon->count].name);
	printf("请输入性别：");
	scanf("%s", pcon->con[pcon->count].sex);
	printf("请输入年龄：");
	scanf("%d", &pcon->con[pcon->count].age);
	printf("请输入电话：");
	scanf("%s", pcon->con[pcon->count].tele);
	printf("请输入地址：");
	scanf("%s", pcon->con[pcon->count].addr);
	pcon->count++;
	printf("添加成功！\n");
}

static int find(contact *pcon, const char *name)
{
	int i = 0;
	for (i = 0; i < pcon->count; i++)
	{
		if (strcmp(name, pcon->con[i].name) == 0)
			return i;
	}
	return -1;
}
void del_contact(contact *pcon)
{
	char name[MAX_NAME];
	int i = 0;
	printf("请输入要删除的人的姓名");
	scanf("%s", &name);
	int ret = find(pcon, name);
	if (ret == -1)
	{
		printf("要删除的人不存在！\n");
		return;
	}
	else
	{
		for (i = ret; i < pcon->count - 1; i++)
		{
			pcon->con[i] = pcon->con[i + 1];
		}
	}
	pcon->count--;
	printf("删除成功\n");
}
void search_contact(contact *pcon)
{
	char name[MAX_NAME];
	int i = 0;
	printf("请输入要查找的人的姓名");
	scanf("%s", &name);
	int ret = find(pcon, name);
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		//printf("name   sex   age    tele    addr\n");
		printf("%10s   %5s   %d    %12s    %20s\n",
			pcon->con[ret].name,
			pcon->con[ret].sex,
			pcon->con[ret].age,
			pcon->con[ret].tele,
			pcon->con[ret].addr);
	}
}
void modify_contact(contact *pcon)
{
	char name[MAX_NAME];
	int i = 0;
	printf("请输入要修改的人的姓名");
	scanf("%s", &name);
	int ret = find(pcon, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("请输入名字：");
		printf("%s", pcon->con[ret].name);
		printf("请输入性别：");
		printf("%s", pcon->con[ret].sex);
		printf("请输入年龄：");
		printf("%d", pcon->con[ret].age);
		printf("请输入电话：");
		printf("%s", pcon->con[ret].tele);
		printf("请输入地址：");
		printf("%s", pcon->con[ret].addr);
	}
}
void show_contact(contact *pcon)
{
	int i = 0;
	printf("%10s   %5s   %5s    %12s    %20s\n",
		"name", "sex", "age", "tele", "addr");
	for (i = 0; i < pcon->count; i++)
	{
		printf("%10s   %5s   %5d    %12s    %20s\n",
			pcon->con[i].name,
			pcon->con[i].sex,
			pcon->con[i].age,
			pcon->con[i].tele,
			pcon->con[i].addr);
	}
}
void clear_contact(contact *pcon)
{
	pcon->count = 0;
	printf("清空成功\n");
}
void sort_contact(contact *pcon)
{
	int i = 0;
	int j = 0;
	peo tmp;
	for (i = 0; i < pcon->count - 1; i++)
	{
		for (j = 0; j < pcon->count - 1 - i; j++)
		{
			if (strcmp(pcon->con[j].name, pcon->con[j + 1].name)>0)
			{
				tmp = pcon->con[j];
				pcon->con[j + 1] = pcon->con[j];
				pcon->con[j] = tmp;
			}
		}
	}
	printf("排序完成\n");
}

void save_contact(contact *pcon)
{
	int i = 0;
	FILE *fp = fopen("text.txt", "wb");
	if (fp == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	printf("开始保存文件\n");
	fprintf(fp, "%d", pcon->count);
	fprintf(fp, "\r\n");
	fprintf(fp, " % 10s % 5s % 5s % 12s % 20s\n",
		"name", "sex", "age", "tele", "addr");
	for (i = 0; i < pcon->count; i++)
	{
		fprintf("%10s   %5s   %5d    %12s    %20s\n",
			pcon->con[i].name,
			pcon->con[i].sex,
			pcon->con[i].age,
			pcon->con[i].tele,
			pcon->con[i].addr);
		fprintf(fp, "\r\n");
	}
	fclose(fp);
	printf("保存成功");
	printf("按任意键继续");
	getch();
}
