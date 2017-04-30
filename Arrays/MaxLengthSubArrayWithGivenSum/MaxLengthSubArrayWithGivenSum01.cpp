#include <iostream>
#include <unordered_map>
using namespace std;

// Naive function to find maximum length sub-array with sum S present
// in the given array
void maxLengthSubArray(int arr[], int n, int S)
{
	// len stores the maximum length of sub-array with sum S
	int len = 0;

	// stores ending index of maximum length sub-array having sum S
	int ending_index = -1;

	// consider all sub-arrays starting from i
	for (int i = 0; i < n; i++)
	{
		int sum = 0;

		// consider all sub-arrays ending at j
		for (int j = i; j < n; j++)
		{
			// sum of elements in current sub-array
			sum += arr[j];

			// if we have found a sub-array with sum S
			if (sum == S)
			{
				// update length and ending index of maximum length sub-array
				if (len < j - i + 1)
				{
					len =  j - i + 1;
					ending_index = j;
				}
			}
		}
	}

	// print the sub-array
	cout << "[" << (ending_index - len + 1) << ", " << ending_index << "]";
}

// main function
int main()
{
	int arr[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
	int sum = 8;

	int n = sizeof(arr)/sizeof(arr[0]);

	maxLengthSubArray(arr, n, sum);

	return 0;
}
