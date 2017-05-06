#include<bits/stdc++.h>
using namespace std;

// Find minimum sum sub-array of given size k
void findSubarray(int arr[], int n, int k)
{
    // stores sum of element in current window
    int window_sum = 0;

    // stores sum of minimum sum sub-array found so far
    int min_window = INT_MAX;

    // stores ending index of minimum sum sub-array found so far
    int last = 0;

    for (int i = 0; i < n; i++)
    {
        // add current element to the window
        window_sum += arr[i];

        // if window size is more than k equal to
        if (i + 1 >= k)
        {
            // update minimum window sum
            if (min_window > window_sum)
            {
                min_window = window_sum;
                last = i;
            }

            // remove leftmost element from the window
            window_sum -= arr[i + 1 - k];
        }
    }

    cout << "Minimum sum sub-array is (" <<
            last - k + 1 << ", " << last << ")";
}

// main function
int main()
{
    int arr[] = { 10, 4, 2, 5, 6, 3, 8, 1 };
    int k = 3;

    int n = sizeof(arr)/sizeof(arr[0]);

    findSubarray(arr, n, k);

    return 0;
}
