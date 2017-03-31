#include <bits/stdc++.h>
using namespace std;

// Function to find the length of Longest repeated Subsequence
// of substring X[0..m-1] and X[0..n-1]
int LRSLength(string X, int m, int n)
{
	// return if we have reached the end of either string
	if (m == 0 || n == 0)
		return 0;

	// if characters at index m and n matches and index is different
	if (X[m - 1] == X[n - 1] && m != n)
		return LRSLength(X, m - 1, n - 1) + 1;
	
	// else if characters at index m and n don't match
	return max (LRSLength(X, m, n - 1), LRSLength(X, m - 1, n));
}

// main function
int main()
{
	string X = "ATACTCGGA";
	int m = X.length();
	
	cout << "Length of Longest Repeating Subsequence is " << 
			LRSLength(X, m, m);

	return 0;
}
