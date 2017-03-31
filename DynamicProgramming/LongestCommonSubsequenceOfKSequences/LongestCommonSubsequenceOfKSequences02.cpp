#include <bits/stdc++.h>
using namespace std;

// Function to return maximum of three integers
int max(int a, int b, int c)
{
	return max(max(a, b), c);
}

// Function to find length of Longest Common Subsequence of 
// sequences X[0..m-1], Y[0..n-1] and Z[0..o-1]
int LCSLength(string X, string Y, string Z, int m, int n, int o, auto &lookup)
{
	// return if we have reached the end of either sequence
	if (m == 0 || n == 0 || o == 0)
		return 0;

	// construct a unique map key from dynamic elements of the input
	string key = to_string(m) + "|" + to_string(n) + "|" + to_string(o);
 
	// if sub-problem is seen for the first time, solve it and 
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// if last character of X, Y and Z matches
		if (X[m - 1] == Y[n - 1] && Y[n - 1] == Z[o - 1])
			lookup[key] = LCSLength(X, Y, Z, m - 1, n - 1, o - 1, lookup) + 1;
		else
			// else if last character of X, Y and Z don't match
			lookup[key] = max(LCSLength(X, Y, Z, m - 1, n, o, lookup), 
							LCSLength(X, Y, Z, m, n - 1, o, lookup),
							LCSLength(X, Y, Z, m, n, o - 1, lookup));
	}
	// return the subproblem solution from the map
	return lookup[key];
}
 
// main function
int main()
{
	string X = "ABCBDAB", Y = "BDCABA", Z = "BADACB";

	// create a map to store solutions of subproblems
	unordered_map<string, int> lookup;

	cout << "The length of LCS is " << 
			LCSLength(X, Y, Z, X.length(), Y.length(), Z.length(), lookup);

	return 0;
}