#include <bits/stdc++.h>
using namespace std;

// create a map to store solutions of subproblems
unordered_map<string, int> lookup;

// Find optimal cost to construct binary search tree from keys i to j
// where each key k occurs freq[k] number of times
int findOptimalCost(int freq[], int i, int j, int level)
{
	// base case
	if (j < i)
		return 0;

	// construct a unique map key from dynamic elements of the input
	string key = to_string(i) + "|" + to_string(j) + "|" + to_string(level);

	// if sub-problem is seen for the first time, solve it and 
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		lookup[key] = INT_MAX;

		// consider each key as a root and recursively find an optimal solution
		for (int k = i; k <= j; k++)
		{
			// recursively find the optimal cost of left subtree
			int leftOptimalCost = findOptimalCost(freq, i, k - 1, level + 1); 

			// recursively find the optimal cost of right subtree
			int rightOptimalCost = findOptimalCost(freq, k + 1, j, level + 1);

			// current node's cost is freq[k]*level
			
			// update optimal cost
			lookup[key] = min (lookup[key],
					freq[k]*level + leftOptimalCost + rightOptimalCost);
		}
	}
	
	// return the subproblem solution from the map
	return lookup[key];
}

// main function
int main()
{
	int freq[] = { 25, 10, 20 };
	int n = sizeof(freq) / sizeof(freq[0]);

	cout << "The optimal cost of constructing BST is " 
			<< findOptimalCost(freq, 0, n - 1, 1);

	return 0;
}
