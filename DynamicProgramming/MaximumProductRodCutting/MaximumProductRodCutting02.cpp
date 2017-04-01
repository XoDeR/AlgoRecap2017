#include <bits/stdc++.h>
using namespace std;

int rodCut(int n)
{
	// T[i] stores maximum profit achieved from rod of length i
	int T[n + 1];

	// rod of len i has at-least cost i
	for (int i = 0; i <= n; i++)
		T[i] = i;
	
	// consider rod of length i
	for (int i = 2; i <= n; i++) 
	{
		// divide the rod of length i into two rods of length j 
		// and i-j each and take maximum
		for (int j = 1; j <= i; j++)
			T[i] = max(T[i], j * T[i - j]);
	}

	// T[n] stores maximum profit achieved from rod of length n 
	return T[n];
}

// main function
int main()
{
	// rod length
	int n = 15;
	
	cout << rodCut(n);

	return 0;
}