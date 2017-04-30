#include <iostream>
using namespace std;

// Function to rearrange the array such that every second element 
// of the array is greater than its left and right elements
void rearrangeArray(int arr[], int n)
{
	// start from second element and increment index
	// by 2 for each iteration of loop
	for (int i = 1; i < n; i += 2) 
	{
		// If the prev element is greater than current element, 
		// swap the elements
		if (arr[i - 1] > arr[i])
			swap(arr[i - 1], arr[i]);

		// if next element is greater than current element, 
		// swap the elements
		if (i + 1 < n && arr[i + 1] > arr[i])
			swap(arr[i + 1], arr[i]);
	}
}

// main function
int main()
{
	int arr[] = { 9, 6, 8, 3, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	rearrangeArray(arr, n);

	// print output array
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
