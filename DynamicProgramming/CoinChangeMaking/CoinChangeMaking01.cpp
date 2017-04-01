#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of coins required 
// to get total of N from set S
int findMinCoins(int S[], int n, int N)
{
	// if total is 0, no coins are needed
	if (N == 0)
		return 0;
	
	// return INFINITY if total become negative
	if (N < 0)
		return INT_MAX;
	
	// initalize minimum number of coins needed to infinity
	int coins = INT_MAX;
	
	// do for each coin
	for (int i = 0; i < n; i++) 
	{
		// recuse to see if total can be reached by including
		// current coin S[i]
		int res = findMinCoins(S, n, N - S[i]);
	
		// update minimum number of coins needed if choosing current 
		// coin resulted in solution
		if (res != INT_MAX)
			coins = min(coins, res + 1);
	}
	
	// return minimum number of coins needed
	return coins;
}

int main()
{
	// n coins of given denominations
	int S[] = { 1, 3, 5, 7 };
	int n = sizeof(S) / sizeof(S[0]);

	// Total Change required
	int N = 18;

	cout << "Minimum number of coins required to get desired change is "
			<< findMinCoins(S, n, N);

	return 0;
}
