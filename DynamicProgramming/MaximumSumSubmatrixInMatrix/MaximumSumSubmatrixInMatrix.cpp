#include <bits/stdc++.h>
using namespace std;

// M x N matrix
#define M 5
#define N 5

// to store matrix cordinates
typedef pair<int, int> Point;

// function to find maximum sum k x k sub-matrix
Point findMaxSumSubMatrix(int mat[][N], int k)
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

	int total, max = INT_MIN;
	Point p;

	// find maximum sum sub-matrix
	
	// start from cell (k - 1, k - 1) and consider each 
	// submatrix of size k x k
	for (int i = k - 1; i < N; i++)
	{
		for (int j = k - 1; j < N; j++)
		{
			// Note (i, j) is bottom right corner cordinates of 
			// square sub-matrix of size k
			
			total = sum[i][j];
			if (i - k >= 0)
				total = total - sum[i - k][j];
			if (j - k >= 0)
				total = total - sum[i][j - k];
			if (i - k >= 0 && j - k >= 0)
				total = total + sum[i - k][j - k];

			if (total > max)
				max = total, p = make_pair(i, j);
		}
	}

	// returns cordinates of bottom right corner of sub-matrix
	return p;
}

int main()
{
	int mat[N][N] = 
	{
		{ 3, -4, 6, -5, 1 },
		{ 1, -2, 8, -4, -2 },
		{ 3, -8, 9, 3, 1 },
		{ -7, 3, 4, 2, 7 },
		{ -3, 7, -5, 7, -6 }
	};
	
	// sub-matrix size
	int k = 3;

	// p contains bottom right corner cordinates of sub-matrix
	Point p = findMaxSumSubMatrix(mat, k);

	// print maximum sum sub-matrix
	for (int i = 0; i < k; i++) 
	{
		for (int j = 0; j < k; j++)
			cout << setw(3) << mat[i + p.first - k + 1][j + p.second - k + 1];
		cout << endl;
	}

	return 0;
}
