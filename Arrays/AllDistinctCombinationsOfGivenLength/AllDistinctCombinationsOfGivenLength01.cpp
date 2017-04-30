#include <bits/stdc++.h>
using namespace std;

// Function to print all distinct combinations of length k
void recurse(int arr[], string out, int n, int k)
{
	// invalid input
	if (k > n)
		return;

	// base case: combination size is k
	if (k == 0) {
		cout << out << endl;
		return;
	}

	// start from next index till first index
	for (int i = n - 1; i >= 0; i--)
	{
		// add current element arr[i] to output and recurse for next index
		// (i-1) with one less element (k-1)
		recurse(arr, to_string(arr[i]) + " " + out, i, k - 1);

		// uncomment below code to handle duplicates
		// while (arr[i] == arr[i - 1])
		//	 i--;
	}
}

// main function
int main()
{
	int arr[] = { 1, 2, 3 };
	int k = 2;

	int n = sizeof(arr) / sizeof(arr[0]);

	// if array do not contain distinct elements,
	// sort the array to handle duplicates as combinations are asked
	// sort (arr, arr + n);

	// process elements from right to left
	recurse(arr, "", n, k);

	return 0;
}
