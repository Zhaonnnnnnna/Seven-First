#pragma once;
#define _CRT_SECURE_NO_WARNINGS

#include<stack>
#include<iostream>
#include<assert.h>
#include<stdio.h>
using namespace std;
#define N 10

enum Type
{
	OP_NUM,
	OP_SYMBOL
};

enum SYMBOL
{
	ADD,
	SUB,
	MUL,
	DIV
};

struct Cell
{
	Type _type;
	int _value;
};

int CountRNP(Cell a[],size_t size)
{
	assert(a);
	stack<int> s;
	for (size_t i = 0; i < size; i++)
	{
		if (a[i]._type == OP_NUM)
		{
			s.push(a[i]._value);
		}
		else
		{
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();
			switch (a[i]._value)
			{
			case ADD:
				s.push(left + right);
				break;
			case SUB:
				s.push(left - right);
				break;
			case MUL:
				s.push(left * right);
				break;
			case DIV:
				s.push(left / right);
				break;
			}
		}
	}
	return s.top();
}


void GetMaze(int *a, size_t n)
{
	FILE* fout = fopen("MazeMap.txt", "r");
	assert(fout);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n;)
		{
			char ch = fgetc(fout);
			if (ch == '0' || ch == '1')
			{
				a[i*n + j] = ch - '0';
				j++;
			}
			else
			{
				continue;
			}
		}
	}
	fclose(fout);
}

void PrintMaze(int* a, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << a[i*n + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

struct Pos
{
	int _row;
	int _col;
};





bool MazePath(int* a, size_t n, Pos& entry, stack<Pos>& path)
{
	Pos cur = entry;
	path.push(cur);
	while (!path.empty())
	{
		a[cur._row *n + cur._col] = 2;
		Pos next = cur;
		上
		next._row--;
		if (CheckIsAccess(a, n, next))
		{
			cur = next;
			path.push(cur);
			continue;
		}
		//右
		next = cur;
		next._col++;
		if (CheckIsAccess(a, n, next))
		{
			cur = next;
			path.push(cur);
			continue;
		}
		   //下
		next = cur;
		next._row++;
		if (CheckIsAccess(a, n, next))
		{
			cur = next;
			path.push(cur);
			continue;
		}
		  //左
		next = cur;
		next._col--;
		if (CheckIsAccess(a, n, next))
		{
			cur = next;
			path.push(cur);
			continue;
		}
		 
		cur = path.top();
		path.pop();
		if (cur._row == n - 1)
		{
			return true;
		}
	}
	return false;
}


bool CheckIsAccess(int* a, size_t n, Pos next)
{
	assert(a);
	if ((next._col >= 0) && (next._col < n) && (next._row >= 0) && (next._row < n) &&
		(a[next._row *n + next._col] == 0))
	{
		return true;
	}
	else
		return false;
}

//Pos& MazePath(int* a, size_t n, Pos& entry, stack<Pos>& path)
//{
//	Pos cur = entry;
//	path.push(cur);
//	a[cur._row *n + cur._col] = 2;
//
//	while (!path.empty())
//	{
//		Pos next = cur;
//		/*上*/
//		next._row--;
//		if (CheckIsAccess(a, n, next))
//		{
//			MazePath((int*)a, N, next, path);
//		}
//		//右
//		next = cur;
//		next._col++;
//		if (CheckIsAccess(a, n, next))
//		{
//			MazePath((int*)a, N, next, path);
//
//		}
//		//下
//		next = cur;
//		next._row++;
//		if (CheckIsAccess(a, n, next))
//		{
//			MazePath((int*)a, N, next, path);
//
//		}
//		//左
//		next = cur;
//		next._col--;
//		if (CheckIsAccess(a, n, next))
//		{
//			MazePath((int*)a, N, next, path);
//
//		}
//		return
//			path.pop();
//		if (cur._row == n - 1)
//		{
//			return cur;
//		}
//	}
//	return NULL;
//}
