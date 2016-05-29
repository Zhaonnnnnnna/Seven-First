#include"Maze.h"


void TestCountRNP()
{
	Cell a[] = { { OP_NUM, 12 }, { OP_NUM, 3 }, { OP_NUM, 4 }, { OP_SYMBOL, ADD },
	{ OP_SYMBOL, MUL }, { OP_NUM, 6 }, { OP_SYMBOL, SUB }, { OP_NUM, 8 }, { OP_NUM, 2 },
	{ OP_SYMBOL, DIV }, { OP_SYMBOL, ADD } };
	int ret = CountRNP(a, sizeof(a) / sizeof(Cell));
	cout << ret << endl;
}

void TestMazePath()
{
	int a[N][N] = {};
	GetMaze((int*)a, N);
	PrintMaze((int*)a,N);

	stack<Pos> path;
	Pos entry = { 2, 0 };
	bool ret = MazePath((int*)a, N, entry, path);
	cout <<"是否有通路"<< ret << endl;
	PrintMaze((int*)a, N);


}
int main()
{
	TestMazePath();
	getchar();
	return 0;
}