#include <bits/stdc++.h>
using namespace std;

// Space optimized function to find length of Longest Common Subsequence
// of substring X[0..m-1] and Y[0..n-1]
int LCSLength(string X, string Y)
{
	int m = X.length(), n = Y.length();

	// allocate storage for one-dimensional array curr
	int curr[n + 1], prev;

	// fill the lookup table in bottom-up manner
	for (int i = 0; i <= m; i++)
	{
	    prev = curr[0];		
		for (int j = 0; j <= n; j++)
		{
		    int backup = curr[j];
			if (i == 0 || j == 0)
				curr[j] = 0;
			else
			{
				// if current character of X and Y matches
				if (X[i - 1] == Y[j - 1])
					curr[j] = prev + 1;

				// else if current character of X and Y don't match
				else
					curr[j] = max(curr[j], curr[j - 1]);
			}
			prev = backup;
		}
	}

	// LCS will be last entry in the lookup table
	return curr[n];
}

// main function
int main()
{
	string X = "XMJYAUZ", Y = "MZJAWXU";

	if (X.length() > Y.length())
		cout << "The length of LCS is " << LCSLength(X, Y);
	else
		cout << "The length of LCS is " << LCSLength(Y, X);

	return 0;
}
