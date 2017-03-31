#include <bits/stdc++.h>
using namespace std;

// Function to find the length of Longest repeated Subsequence
// of substring X[0..m-1] and X[0..n-1]
int LRSLength(string X, int m, int n, auto &lookup)
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
		// if characters at index m and n matches and index is different
		if (X[m - 1] == X[n - 1] && m != n)
			lookup[key] = LRSLength(X, m - 1, n - 1, lookup) + 1;
		
		else
	
		// else if characters at index m and n don't match
		lookup[key] = max (LRSLength(X, m, n - 1, lookup), 
						  LRSLength(X, m - 1, n, lookup));
	}
	
	// return the subproblem solution from the map
	return lookup[key];
}

// main function
int main()
{
	string X = "ATACTCGGA";
	int m = X.length();

	// create a map to store solutions of subproblems
	unordered_map<string, int> lookup;
	
	cout << "Length of Longest Repeating Subsequence is " << 
			LRSLength(X, m, m, lookup);

	return 0;
}
