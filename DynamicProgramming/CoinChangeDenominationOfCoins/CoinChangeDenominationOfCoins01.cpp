#include <bits/stdc++.h>
using namespace std;

// Function to find the total number of ways to get change of N from
// unlimited supply of coins in set S
int count(int S[], int n, int N)
{
	// if total is 0, return 1
	if (N == 0)
		return 1;
	
	// return 0 if total become negative
	if (N < 0)
		return 0;
	
	// initialize total number of ways to 0
	int res = 0;
	
	// do for each coin
	for (int i = 0; i < n; i++) 
	{
		// recuse to see if total can be reached by including
		// current coin S[i]
		res += count(S, n, N - S[i]);
	}
	
	// return total number of ways
	return res;
}

// main function
int main()
{
	// n coins of given denominations
	int S[] = { 1, 2, 3 };
	int n = sizeof(S) / sizeof(S[0]);

	// Total Change required
	int N = 4;

	cout << "Total number of ways to get desired change is "
			<< count(S, n, N);

	return 0;
}
