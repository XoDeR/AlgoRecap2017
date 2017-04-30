#include <bits/stdc++.h>
using namespace std;

// Function to shuffle an array A of n elements
void shuffle(int A[], int n)
{
    // read array from lowest index to highest
	for (int i = 0; i <= n - 2; i++)
	{
	    // generate a random number j such that i <= j < n
		int j = i + rand() % (n - i);

		// swap current element with randomly generated index
		swap(A[i], A[j]);
	}
}

// main function
int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(A) / sizeof(A[0]);

	// seed for random input
	srand(time(NULL));

	shuffle(A, n);

	// print the shuffled array
	for (int i = 0; i < n; i++)
		cout << setw(2) << A[i];

	return 0;
}
