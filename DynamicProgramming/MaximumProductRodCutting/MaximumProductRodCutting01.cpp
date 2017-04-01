#include <bits/stdc++.h>
using namespace std;

// Function to find best way to cut a rod of length n
// where rod of length i has price i
int rodCut(int n)
{
	// base case
	if (n <= 1)
		return n;

	// rod of length n has at-least cost of n
	int maxValue = n;

	// one by one partition the given rod of length n into two parts of  
	// length (1, n-1), (2, n-2), .... (n-1 , 1), (n, 0) and take maximum
	for (int i = 1; i <= n; i++) 
		maxValue = max(maxValue, i * rodCut(n - i));

	return maxValue;
}

// main function
int main()
{
	int n = 15;		// 3x 5 times
	cout << rodCut(n);

	return 0;
}