#include <bits/stdc++.h>
using namespace std;

// M x N matrix
#define M 8
#define N 6

// Function to find the size of largest square sub-matrix of 1's 
// present in the given binary matrix 
int findLargestSquare(int mat[M][N], int m, int n, int &max_size)
{
	// base condition
	if (m == 0 || n == 0 || mat[m][n] == 0)
		return mat[m][n];

	// find largest square matrix ending at mat[m][n-1]
	int left = findLargestSquare(mat, m, n - 1, max_size);

	// find largest square matrix ending at mat[m-1][n]
	int top = findLargestSquare(mat, m - 1, n, max_size);
	
	// find largest square matrix ending at mat[m-1][n-1]
	int diagonal = findLargestSquare(mat, m - 1, n - 1, max_size);
	
	// largest square matrix ending at mat[m][n] will be 1 plus  
	// minimum of largest square matrix ending at mat[m][n-1], 
	// mat[m-1][n] and mat[m-1][n-1]
	
	int size = 1 + min (min(top, left), diagonal);

	// update maximum size found so far
	max_size = max(max_size, size);

	// return the size of largest square matrix ending at mat[m][n]
	return size;
}

// main function
int main()
{
	int mat[M][N] = 
	{ 
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 }, 
		{ 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1 }
	};
 	
	// size stores the size of largest square sub-matrix of 1's 
	// and it is passed by reference
 	int size = 0;
	
	findLargestSquare(mat, M-1, N-1, size);
	
	cout << "The size of largest square sub-matrix of 1's is " << size;
	
	return 0;
}