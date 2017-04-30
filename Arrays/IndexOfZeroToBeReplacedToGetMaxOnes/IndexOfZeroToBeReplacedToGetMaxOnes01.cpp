#include <iostream>
using namespace std;

// Find index of 0 to replaced with 1 to get maximum sequence of continuous 1's
int findIndexofZero(int arr[], int n)
{
	int max_count = 0;          // for maximum number of 1 including  zero
	int max_index = -1;         // stores index of 0 to be replaced

	int prev_zero_index = -1;   // stores index of previous zero
	int count = 0;              // store current count of zeros

	// consider each index i of the array
	for (int i = 0; i < n; i++)
	{
	    // if current element is 1
		if (arr[i] == 1)
			count++;
		else
		// if current element is 0
		{
            // reset count to 1 + number of ones to the left of current 0
            count = i - prev_zero_index;

            // update prev_zero_index to current index
			prev_zero_index = i;
		}

		// update maximum count and index of 0 to be replaced if required
		if (count > max_count)
		{
			max_count = count;
			max_index = prev_zero_index;
		}
	}

	return max_index;
}

// main function
int main()
{
	int arr[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int index = findIndexofZero(arr, n);

	if (index != -1)
        cout << "Index to be replaced is " << index;
    else
        cout << "Invalid input";

	return 0;
}
