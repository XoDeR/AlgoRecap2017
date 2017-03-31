#include <bits/stdc++.h>
using namespace std;

#define N 25
 
// lookup[i][j] stores the length of LCS of substring X[0..i-1], Y[0..j-1]
int lookup[N][N];

// Function to find LCS of string X[0..m-1] and Y[0..n-1]
string longestPalindrome(string X, string Y, int m, int n)
{
	// return empty string if we have reached the end of
	// either sequence
    if (m == 0 || n == 0)
        return string("");
 
	// if last character of X and Y matches
    if (X[m - 1] == Y[n - 1])
    {
        // append current character (X[m-1] or Y[n-1]) to LCS of
        // substring X[0..m-2] and Y[0..n-2]
        return longestPalindrome(X, Y, m - 1, n - 1) + X[m - 1];
    }
 
	// else when the last character of X and Y are different
 
	// if top cell of current cell has more value than the left 
	// cell, then drop current character of string X and find LCS 
	// of substring X[0..m-2], Y[0..n-1]
 
    if (lookup[m - 1][n] > lookup[m][n - 1])
        return longestPalindrome(X, Y, m - 1, n);
 
    // if left cell of current cell has more value than the top 
    // cell, then drop current character of string Y and find LCS 
    // of substring X[0..m-1], Y[0..n-2]
 
    return longestPalindrome(X, Y, m, n - 1);
}

// Function to find length of LCS of substring X[0..n-1] and Y[0..n-1]
int LCSLength(string X, string Y, int n)
{
	// first row and first column of the lookup table
	// are already 0 as lookup[][] is globally declared

	// fill the lookup table in bottom-up manner
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// if current character of X and Y matches
			if (X[i - 1] == Y[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 1;

			// else if current character of X and Y don't match
			else
				lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
		}
	}
	return lookup[n][n];
}

// main function
int main()
{
	string X = "ABBDCACB";
	int m = X.length();

	// string Y is reverse of X
	string Y = X;
	reverse(Y.begin(), Y.end());

	// Find length of Longest Palindromic Subsequence using LCS
	cout << "The length of Longest Palindromic Subsequence is " 
			<< LCSLength(X, Y, m) << endl;

	// Print Longest Palindromic Subsequence using lookup table
	cout << "The Longest Palindromic Subsequence is " 
			<< longestPalindrome(X, Y, m, m);

	return 0;
}
