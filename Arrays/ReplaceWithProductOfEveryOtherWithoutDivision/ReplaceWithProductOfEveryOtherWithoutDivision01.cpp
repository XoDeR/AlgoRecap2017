#include<iostream>
using namespace std;

// Recursive function to replace each element of the array with product
// of every other element without using division operator
int findProduct(int arr[], int n, int left, int i)
{
    // base case: no elements left on right side
	if (i == n)
		return 1;

    // take back-up of current element
	int curr = arr[i];

	// calculate product of the right sub-array
	int right = findProduct(arr, n, left * arr[i], i + 1);

	// replace current element with product of left and right sub-array
	arr[i] = left * right;

	// return product of right sub-array including current element
	return curr * right;
}

// main function
int main()
{
	int arr[] = { 5, 3, 4, 2, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findProduct(arr, n, 1, 0);

	// print the modified array
    for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
