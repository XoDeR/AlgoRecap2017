#include <bits/stdc++.h>
using namespace std;

// Util function to find length of longest subsequence
// if flag is true, next element should be greater
// if flag is false, next element should be smaller
int Util(int arr[], int start, int end, bool flag)
{
	int res = 0;
	for (int i = start; i <= end; i++)
	{
		// include arr[i] as next high in subsequence and flip flag
		// for next subsequence
		if (flag && arr[i - 1] < arr[i])
			res = max(res, 1 + Util(arr, i + 1, end, !flag));

		// include arr[i] as next low in subsequence and flip flag
		// for next subsequence
		else if (!flag && arr[i - 1] > arr[i])
			res = max(res, 1 + Util(arr, i + 1, end, !flag));

		// don't include arr[i] in subsequence
		else
			res = max(res, Util(arr, i + 1, end, flag));
	}

	return res;
}

// Function to find length of longest subsequence with alternate 
// low and high elements. It uses Util() method.
int findLongestSequence(int arr[], int n)
{
	// Fix first element and recurse for remaining elements as first 
	// element will always be part of longest subsequence (why?)

	// There are two possibilities -

	// 1. Next element is greater (pass true)
	// 2. Next element is smaller (pass false)
	return 1 + max(Util(arr, 1, n - 1, true),
				   Util(arr, 1, n - 1, false));

	// instead of fixing first element, we can also directly call
	// return max(Util(arr, 0, n, true), Util(arr, 0, n, false));
}

// main function
int main()
{
	int arr[] = { 8, 9, 6, 4, 5, 7, 3, 2, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "The length of Longest Subsequence is " 
			<< findLongestSequence(arr, n);

	return 0;
}