#include <bits/stdc++.h>
using namespace std;
 
// Function to return maximum of three integers
int max(int a, int b, int c)
{
	return max(max(a, b), c);
}

// Function to find length of Longest Common Subsequence of 
// sequences X[0..m-1], Y[0..n-1] and Z[0..o-1]
int LCSLength(string X, string Y, string Z)
{
	int m = X.length(), n = Y.length(), o = Z.length();
	
	// lookup table stores solution to already computed sub-problems
	// i.e. lookup[i][j][k] stores the length of LCS of substring 
	// X[0..i-1], Y[0..j-1], Z[0..k-1]
	int lookup[m + 1][n + 1][o + 1];
 	
 	// initalize lookup table with 0
 	memset(lookup, 0, sizeof lookup);

	// fill the lookup table in bottom-up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= o; k++)
			{
				// if current character of X, Y and Z matches
				if (X[i - 1] == Y[j - 1] && Y[j - 1] == Z[k - 1])
					lookup[i][j][k] = lookup[i - 1][j - 1][k - 1] + 1;
			
				// else if current character of X, Y and Z don't match
				else
					lookup[i][j][k] = max(lookup[i - 1][j][k], 
										lookup[i][j - 1][k],
										lookup[i][j][k - 1]);
			}
		}
	}
	
	// LCS will be last entry in the lookup table
	return lookup[m][n][o];
}
 
// main function
int main()
{
	string X = "ABCBDAB", Y = "BDCABA", Z = "BADACB";
 
	cout << "The length of LCS is " << LCSLength(X, Y, Z);
 
	return 0;
}