#pragma once

#include<stdio.h>
#include<malloc.h>


#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 20



typedef struct People
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int  age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peo;

typedef struct Contact
{
	peo con;
	int count;
}contact;

peo *con = NULL;
con = (peo *)malloc(100 * sizeof(peo));

enum OP
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR,
	SORT
};

void init_contact(contact *pcon);
void add_contact(contact *pcon);
void del_contact(contact *pcon);
void search_contact(contact *pcon);
void modify_contact(contact *pcon);
void show_contact(contact *pcon);
void clear_contact(contact *pcon);
void sort_contact(contact *pcon);
