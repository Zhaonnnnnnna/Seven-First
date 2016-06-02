#include"SymmetricMatrix.h"

void testSymmetricMatrix()
{

	int a[4][4] =
	{ { 1, 2, 3, 4 },
	{ 2, 1, 2, 3 },
	{ 3, 2, 1, 2 },
	{ 4, 3, 2, 1 } };
	SymmetricMatrix<int> s1((int *)a, 16, 4);
	s1.Display();
	cout << s1.Access(1, 1) << endl;

}
void testSparseMatrix()
{
	int a[4][5] =
	{ { 1, 0, 0, 0, 4 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 3, 0, 0 },
	{0, 5, 0, 0, 0} };
	SparseMatrix<int> s1((int *)a, 4, 5, 0);
	s1.Display();
	
	SparseMatrix<int> s2;
	s2 = s1.Transport();
	s2.Display();

	SparseMatrix<int> s3;
	s3 = s1.FastTransport();
	s3.Display();
	

}
int main()
{
	//testSymmetricMatrix();
	testSparseMatrix();
	getchar();
	return 0;
}