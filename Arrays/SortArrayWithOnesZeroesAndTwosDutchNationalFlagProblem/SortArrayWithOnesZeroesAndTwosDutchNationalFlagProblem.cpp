#include <bits/stdc++.h>
using namespace std;

// Linear-time partition routine to sort an array containing 0, 1 and 2
// It similar to three-way Partitioning for Dutch national flag problem
int threeWayPartition(int A[], int end)
{
	int start = 0, mid = 0;
	int pivot = 1;

	while (mid <= end)
	{
		if (A[mid] < pivot)			// current element is 0
		{
			swap(A[start], A[mid]);
			++start, ++mid;
		}
		else if (A[mid] > pivot)	// current element is 2
		{
			swap(A[mid], A[end]);
			--end;
		}
		else						// current element is 1
			++mid;
	}
}

// main function
int main()
{
	int A[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
	int n = sizeof(A)/sizeof(A[0]);

	threeWayPartition(A, n - 1);

	for (int i = 0 ; i < n; i++)
		cout << A[i] << " ";

	return 0;
}
