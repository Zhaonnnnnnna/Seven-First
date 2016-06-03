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
		printf("�绰���������޷����");
		return;
	}
	printf("���������֣�");
	scanf("%s", pcon->con[pcon->count].name);
	printf("�������Ա�");
	scanf("%s", pcon->con[pcon->count].sex);
	printf("���������䣺");
	scanf("%d", &pcon->con[pcon->count].age);
	printf("������绰��");
	scanf("%s", pcon->con[pcon->count].tele);
	printf("�������ַ��");
	scanf("%s", pcon->con[pcon->count].addr);
	pcon->count++;
	printf("��ӳɹ���\n");
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
	printf("������Ҫɾ�����˵�����");
	scanf("%s", &name);
	int ret = find(pcon, name);
	if (ret == -1)
	{
		printf("Ҫɾ�����˲����ڣ�\n");
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
	printf("ɾ���ɹ�\n");
}
void search_contact(contact *pcon)
{
	char name[MAX_NAME];
	int i = 0;
	printf("������Ҫ���ҵ��˵�����");
	scanf("%s", &name);
	int ret = find(pcon, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
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
	printf("������Ҫ�޸ĵ��˵�����");
	scanf("%s", &name);
	int ret = find(pcon, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("���������֣�");
		printf("%s", pcon->con[ret].name);
		printf("�������Ա�");
		printf("%s", pcon->con[ret].sex);
		printf("���������䣺");
		printf("%d", pcon->con[ret].age);
		printf("������绰��");
		printf("%s", pcon->con[ret].tele);
		printf("�������ַ��");
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
	printf("��ճɹ�\n");
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
	printf("�������\n");
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
	printf("��ʼ�����ļ�\n");
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
	printf("����ɹ�");
	printf("�����������");
	getch();
}
