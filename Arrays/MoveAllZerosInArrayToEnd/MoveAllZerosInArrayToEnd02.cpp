#include <bits/stdc++.h>
using namespace std;

// Function to move all zeros present in the array to the end
int Partition(int A[], int n)
{
	int j = 0;

	// each time we encounter a non-zero, j is incremented and
	// the element is placed before the pivot
	for (int i = 0; i < n; i++)
	{
		if (A[i] != 0)   // pivot is 0
		{
			swap(A[i], A[j]);
			j++;
		}
	}
}

// main function
int main()
{
	int A[] = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
	int n = sizeof(A) / sizeof(A[0]);

	Partition(A, n);

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";

	return 0;
}
