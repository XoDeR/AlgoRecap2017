#include <bits/stdc++.h>
using namespace std;

// Function to find maximum product of two integers in an array
void findMaximumProduct(int arr[], int n)
{
    // sort array in ascending order
	sort(arr, arr + n);

    // maximum product is formed by maximum of
    // 1. product of first two elements or
    // 2. product of last two elements
	if ((arr[0] * arr[1]) > (arr[n - 1] * arr[n - 2]))
		printf("Pair is (%d, %d)", arr[0], arr[1]);
	else
		printf("Pair is (%d, %d)", arr[n - 1], arr[n - 2]);
}

// main function
int main()
{
    int arr[] = { -10, -3, 5, 6, -20 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findMaximumProduct(arr, n);

	return 0;
}
