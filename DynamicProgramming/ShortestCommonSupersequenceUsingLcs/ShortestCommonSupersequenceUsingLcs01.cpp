#include <bits/stdc++.h>
using namespace std;

// Function to find the length of LCS of substring X[0..m-1] and Y[0..n-1]
int LCSLength(string X, string Y, int m, int n, auto &lookup)
{
	// return if we have reached the end of either string
	if (m == 0 || n == 0)
		return 0;

	// construct a unique map key from dynamic elements of the input
	string key = to_string(m) + "|" + to_string(n);

	// if sub-problem is seen for the first time, solve it and 
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// if last character of X and Y matches
		if (X[m - 1] == Y[n - 1])
			lookup[key] = LCSLength(X, Y, m - 1, n - 1, lookup) + 1;
		
		else
		// else if last character of X and Y don't match
		lookup[key] = max(LCSLength(X, Y, m, n - 1, lookup), 
						  LCSLength(X, Y, m - 1, n, lookup));
	}
	
	// return the subproblem solution from the map
	return lookup[key];
}

// main function
int main()
{
	string X = "ABCBDAB", Y = "BDCABA";
	int m = X.length(), n = Y.length();

	// create a map to store solutions of subproblems
	unordered_map<string, int> lookup;

	// find length of longest common subsequence (LCS)
	int len = LCSLength(X, Y, m, n, lookup);
	
	// length of shortest common supersequence of two strings 
	// is equal to the sum of both strings minus length of 
	// their longest common subsequence

	cout << "The Length of Shortest Common Supersequence is " 
			<< m + n - len;
	
	return 0;
}
