#include<iostream>
using namespace std;

// Function to replace each element of the array with product
// of every other element without using division operator
void findProduct(int arr[], int n)
{
    // use two auxiliary arrays
	int left[n], right[n];

	// left[i] stores the product of all elements in the sub-array[0..i-1]
	left[0] = 1;
	for (int i = 1; i < n; i++)
		left[i] = arr[i - 1] * left[i - 1];

    // right[i] stores the product of all elements in sub-array[i+1..n-1]
	right[n - 1] = 1;
	for (int j = n - 2; j >= 0; j--)
		right[j] = arr[j + 1] * right[j + 1];

    // replace each element with product of its left and right sub-array
	for (int i = 0; i < n; i++)
		arr[i] = left[i] * right[i];
}

// main function
int main()
{
	int arr[] = { 5, 3, 4, 2, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findProduct(arr, n);

	// print the modified array
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
