#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 20
#define MAX 1000

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
	peo con[MAX];
	int count;
}contact;

enum OP
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR,
	SORT,
	SAVE
};

void init_contact(contact *pcon);
void add_contact(contact *pcon);
void del_contact(contact *pcon);
void search_contact(contact *pcon);
void modify_contact(contact *pcon);
void show_contact(contact *pcon);
void clear_contact(contact *pcon);
void sort_contact(contact *pcon);
void save_contact(contact *pcon);




