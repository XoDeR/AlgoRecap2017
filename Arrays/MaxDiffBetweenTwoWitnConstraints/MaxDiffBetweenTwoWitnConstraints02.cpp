#include <iostream>
#include <climits>
using namespace std;

// Naive function to find maximum difference between two 
// elements in the array such that smaller element appears 
// before the larger element in the array
int diff(int arr[], int n)
{
	int diff = INT_MIN;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			diff = max(diff, arr[j] - arr[i]);

	return diff;
}

// main function
int main()
{
	int arr[] = { 2, 7, 9, 5, 1, 3, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "The maximum difference is " << diff(arr, n);

	return 0;
}
