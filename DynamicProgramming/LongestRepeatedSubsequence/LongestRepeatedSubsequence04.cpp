#include <bits/stdc++.h>
using namespace std;

// Maximum string length
#define N 20

// lookup[i][j] stores the length of LRS of substring X[0..i-1], X[0..j-1]
int lookup[N][N];

// Function to find LRS of substrings X[0..m-1], X[0..n-1]
string LRS(string X, int m, int n)
{
	// if we have reached the end of either sequence
	// return empty string
	if (m == 0 || n == 0)
		return string("");

	// if characters at index m and n matches and index is different
	if (X[m - 1] == X[n - 1] && m != n)
		return LRS(X, m - 1, n - 1) + X[m - 1];

	else
	// else if characters at index m and n don't match
	{
		if (lookup[m - 1][n] > lookup[m][n - 1])
			return LRS(X, m - 1, n);
		else
			return LRS(X, m, n - 1);
	}
}

// Function to fill lookup table by finding the length of LRS
// of substring X[0..n-1]
void LRSLength(string X, int n)
{
	// first row and first column of the lookup table
	// are already 0 as lookup[][] is globally declared

	// fill the lookup table in bottom-up manner
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// if characters at index i and j matches 
			// and the index is different
			if (X[i - 1] == X[j - 1] && i != j)
				lookup[i][j] = lookup[i - 1][j - 1] + 1;

			// else if characters at index i and j are different 
			else
				lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
		}
	}

	// Uncomment below code to print the lookup table
/*	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
			cout << lookup[i][j] << " ";
		cout << endl;
	}*/
}

// main function
int main()
{
	string X = "ATACTCGGA";

	int n = X.length();

	// fill lookup table
	LRSLength(X, n);

	// find Longest Repeating Subsequence
	cout << LRS(X, n, n);

	return 0;
}
