#include <bits/stdc++.h>
using namespace std;

// Function to find length of shortest Common supersequence of 
// sequences X[0..m-1] and Y[0..n-1]
int SCSLength(string X, string Y, int m, int n, auto &lookup)
{
	// if we have reached the end of either sequence, return 
	// length of other sequence
	if (m == 0 || n == 0)
		return n + m;

	// construct a unique map key from dynamic elements of the input
	string key = to_string(m) + "|" + to_string(n);

	// if sub-problem is seen for the first time, solve it and 
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// if last character of X and Y matches
		if (X[m - 1] == Y[n - 1])
			lookup[key] = SCSLength(X, Y, m - 1, n - 1, lookup) + 1;
		
		else
		
		// else if last character of X and Y don't match
		lookup[key] = min (SCSLength(X, Y, m, n - 1, lookup) + 1, 
						  	SCSLength(X, Y, m - 1, n, lookup) + 1);
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
	// we can also use array instead of map
	unordered_map<string, int> lookup;
	
	cout << "The length of shortest Common supersequence is " 
			<< SCSLength(X, Y, m, n, lookup);

	return 0;
}
