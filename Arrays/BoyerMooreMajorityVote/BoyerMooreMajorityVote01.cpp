#include <bits/stdc++.h>
using namespace std;

// Function to return majority element present in given array
int majorityElement(int A[], int n)
{
	// m stores majority element (if present)
	int m;
	
	// initalize counter i with 0
	int i = 0;
	
	// do for each element A[j] of the array
	for (int j = 0; j < n; j++)
	{
		// If the counter i becomes 0, we set the current candidate
		// to A[j] and reset the counter to 1
		if (i == 0)
			m = A[j], i = 1;
			
		// If the counter is not 0, we increment or decrement the counter 
		// according to whether A[j] is the current candidate
		else (m == A[j]) ? i++ : i--;
	}

	return m;
}

// main function
int main()
{
	// Assumtion - valid input (majority element is present)
	int arr[] = { 1, 8, 7, 4, 1, 2, 2, 2, 2, 2, 2 };
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Majority element is " <<  majorityElement(arr, n);

	return 0;
}
