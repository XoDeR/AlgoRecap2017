#include <bits/stdc++.h>
using namespace std;

// M x N matrix
#define M 4
#define N 4

// create a map to store solutions of subproblems
unordered_map<string, int> lookup;

// Naive recursive top-down function to count total number of paths 
// to reach cell (m, n) from cell (0, 0) and having given cost
int countPaths(int mat[][N], int m, int n, int cost)
{
	// base case
	if (cost < 0)
		return 0;

    // if we're at first cell (0, 0)
	if (m == 0 && n == 0)
	{
		if (mat[0][0] - cost == 0)
			return 1;
		else return 0;
	}
	
	// construct a unique map key from dynamic elements of the input
	string key = to_string(m) + "|" + to_string(n) + "|" + to_string(cost);
	
	// if sub-problem is seen for the first time, solve it and 
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
	    // if we're at first row, we can only go left
		if (m == 0)
			lookup[key] = countPaths(mat, 0, n - 1, cost - mat[m][n]);
	    
	    // if we're at first column, we can only go up
		else if (n == 0)
			lookup[key] = countPaths(mat, m - 1, 0, cost - mat[m][n]);
		
		// recuse to count total paths by going both left and top
		else
			lookup[key] = countPaths(mat, m - 1, n, cost - mat[m][n]) + 
				countPaths(mat, m, n - 1, cost - mat[m][n]);
	}

	// return total number of paths to reach cell (m, n)
	return lookup[key];
}

// main function
int main()
{
	int mat[M][N] = 
	{ 
		{ 4, 7, 1, 6 },
		{ 5, 7, 3, 9 },
		{ 3, 2, 1, 2 },
		{ 7, 1, 6, 3 }
	};

	int cost = 25;

	cout << "Total paths with cost " << cost << " are " << 
			countPaths(mat, M-1, N-1, cost);

	return 0;
}