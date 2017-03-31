#include <bits/stdc++.h>
using namespace std;

// define maximum possible length of string X and Y
#define MAX 20

// lookup[i][j] stores the length of SCS of substring X[0..i-1], Y[0..j-1]
int lookup[MAX][MAX];

// Function to return an SCS of substrings X[0..m-1], Y[0..n-1]
string SCS(string X, string Y, int m, int n)
{
	// if we have reached the end of first string, 
	// return second string
	if (m == 0)
		return Y.substr(0, n);

	// if we have reached the end of second string, 
	// return first string
	else if (n == 0)
		return X.substr(0, m);

	// if last character of X and Y matches, then include it in SSC
	// and recurse to find SCS of substring X[0..m-2], Y[0..n-1]
	if (X[m - 1] == Y[n - 1])
		return SCS(X, Y, m - 1, n - 1) + X[m - 1];
	
	else
	// if the last character of X and Y don't match
	{
		// if top cell of current cell has less value than the left 
		// cell, then include current character of string X in SCS
		// and find SCS of substring X[0..m-2], Y[0..n-2]

		if (lookup[m - 1][n] < lookup[m][n - 1])
			return SCS(X, Y, m - 1, n) + X[m-1];

		// if left cell of current cell has less value than the top 
		// cell, then include current character of string Y in SCS 
		// and find SCS of substring X[0..m-1], Y[0..n-2]
		else
			return SCS(X, Y, m, n - 1) + Y[n-1];
	}
}

// Function to fill lookup table by finding length of SCS of 
// sequences X[0..m-1] and Y[0..n-1]
int SCSLength(string X, string Y, int m, int n)
{
	// lookup table stores solution to already computed sub-problems
	
	// i.e. lookup[i][j] stores the length of SCS of substring 
	// X[0..i-1] and Y[0..j-1]
	int lookup[m + 1][n + 1];

	// initalize first column of the lookup table
	for (int i = 0; i <= m; i++)
		lookup[i][0] = i;

	// initalize first row of the lookup table
	for (int j = 0; j <= n; j++)
		lookup[0][j] = j;

	// fill the lookup table in bottom-up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// if current character of X and Y matches
			if (X[i - 1] == Y[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 1;
		
			// else if current character of X and Y don't match
			else
				lookup[i][j] = min(lookup[i - 1][j] + 1, lookup[i][j - 1] + 1);
		}
	}
}

// main function
int main()
{
	string X = "ABCBDAB", Y = "BDCABA";
	int m = X.length(), n = Y.length();

	// fill lookup table in bottom-up manner
	SCSLength(X, Y, m, n);

	// find Shortest Common Supersequence by reading lookup
	// table in top-down manner
	cout << "The Shortest Common Supersequence of " << X << 
			" and " << Y << " is " << SCS(X, Y, m, n);

	return 0;
}
