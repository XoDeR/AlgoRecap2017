#include <bits/stdc++.h>
using namespace std;

// Function to find the Longest Bitonic Subarray in an array
int findBitonicSubarray(int A[], int n)
{
	// I[i] stores the length of the longest increasing sub-array
	// ending at A[i]
	int I[n + 1];
	I[0] = 1;
	for (int i = 1; i <= n; i++) {
		I[i] = 1;
		if (A[i-1] < A[i])
			I[i] = I[i-1] + 1;
	}

	// D[i] stores the length of the longest decreasing sub-array
	// starting with A[i]
	int D[n + 1];
	D[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		D[i] = 1;
		if (A[i] > A[i+1])
			D[i] = D[i+1] + 1;
	}

	// consider each element as peak and calculate LBS
	int lbs_len = 1;
	int beg = 0, end = 0;

	for (int i = 0; i <= n; i++)
    {
        if (lbs_len < I[i] + D[i] - 1)
        {
            lbs_len = I[i] + D[i] - 1;
            beg = i - I[i] + 1;
            end = i + D[i] - 1;
        }
    }

    // print longest bitonic sub-array
    printf("The length of longest bitonic sub-array is %d\n", lbs_len);
	printf("The longest bitonic sub-array is [%d, %d]", beg, end);

	return lbs_len;
}

// main function
int main()
{
	int A[] = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 };
	int n = sizeof(A) / sizeof(A[0]);

	findBitonicSubarray(A, n - 1);

	return 0;
}
