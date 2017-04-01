#include <bits/stdc++.h>
using namespace std;

// M x N matrix
#define M 5
#define N 5

int findSubmatrixSum(int mat[M][N], int p, int q, int r, int s)
{
	// pre-process the input matrix such that sum[i][j] stores 
	// sum of elements in matrix from (0, 0) to (i, j)
	int sum[M][N];
	
	sum[0][0] = mat[0][0];

	// pre-process first row
	for (int j = 1; j < N; j++)
		sum[0][j] = mat[0][j] + sum[0][j - 1];

	// pre-process first column
	for (int i = 1; i < M; i++)
		sum[i][0] = mat[i][0] + sum[i - 1][0];

	// pre-process rest of the matrix
	for (int i = 1; i < M; i++)
		for (int j = 1; j < N; j++)
			sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1]
				- sum[i - 1][j - 1];

	// uncomment below lines to print the sum matrix
	/* for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << setw(3) << sum[i][j] << " ";

		cout << endl;
	} */

	// total = sum[r][s] - sum[r][q - 1] - sum[p - 1][s] + sum[p - 1][q - 1];
	int total = sum[r][s];

	if (q - 1 >= 0)
		total -= sum[r][q - 1];

	if (p - 1 >= 0)
		total -= sum[p - 1][s];

	if (p - 1 >= 0 && q - 1 >= 0)
		total += sum[p - 1][q - 1];

	return total;
}

int main()
{
	int mat[M][N] = 
	{
		{ 0, 2, 5, 4, 1 },
		{ 4, 8, 2, 3, 7 },
		{ 6, 3, 4, 6, 2 },
		{ 7, 3, 1, 8, 3 },
		{ 1, 5, 7, 9, 4 }
	};
	
	// (p, q) and (r, s) represents top-left and bottom-right 
	// coordinates of the sub-matrix
	int p = 1, q = 1, r = 3, s = 3;

	// calculate sub-matrix sum
	cout << findSubmatrixSum(mat, p, q, r, s);

	return 0;
}
