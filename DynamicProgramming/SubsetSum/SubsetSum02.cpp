#include <bits/stdc++.h>
using namespace std;

// create a map to store solutions of subproblems
unordered_map<string, int> lookup;

// Return true if there exists a subarray of array[0..n] with given sum
bool subsetSum(int arr[], int n, int sum)
{
	// return true if sum becomes 0 (subset found)
	if (sum == 0)
		return true;

	// base case: no items left or sum becomes negative
	if (n < 0 || sum < 0)
		return false;

	// construct a unique map key from dynamic elements of the input
	string key = to_string(n) + "|" + to_string(sum);
	
	// if sub-problem is seen for the first time, solve it and 
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// Case 1. include current item in the subset (arr[n]) and recurse
		// for remaining items (n - 1) with decreased sum (sum - arr[n])
		bool include = subsetSum(arr, n - 1, sum - arr[n]);
		
		// Case 2. exclude current item n from subset and recurse for 
		// remaining items (n - 1)
		bool exclude = subsetSum(arr, n - 1, sum);
		
		// assign true if we get subset by including or excluding current item
		lookup[key] = include || exclude;
	}
	
	// return solution to current sub-problem
	return lookup[key];
}

int main()
{
	// Input: set of items and a sum
	int arr[] = { 7, 3, 2, 5, 8 };
	int sum = 14;

	// number of items
	int n = sizeof(arr) / sizeof(arr[0]);

	if (subsetSum(arr, n - 1, sum))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}