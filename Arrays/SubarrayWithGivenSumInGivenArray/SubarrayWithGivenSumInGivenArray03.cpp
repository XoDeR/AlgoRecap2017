#include<bits/stdc++.h>
using namespace std;

// Function to print sub-array having given sum using Hashing
void findSubarray(int arr[], int n, int sum)
{
    // create an empty map
    unordered_map<int, int> map;

    // insert (0, -1) pair into the set to handle the case when
	// sub-array with given sum starts from index 0
    map.insert(pair<int, int>(0, -1));

	// maintains sum of elements so far
    int sum_so_far = 0;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // update sum_so_far
        sum_so_far += arr[i];

		// if (sum_so_far - sum) is seen before, we have found
		// the sub-array with sum 'sum'
        if (map.find(sum_so_far - sum) != map.end())
        {
            cout << "Sub-array found [" << map[sum_so_far - sum] + 1 <<
                    "-" << i << "]" << endl;
            return;
        }

        // insert current sum with index into the map
        map.insert(pair<int, int>(sum_so_far, i));
    }
}

// main function
int main()
{
    // array of integers
	int arr[] = { 0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10 };
	int sum = 15;

    int n = sizeof(arr)/sizeof(arr[0]);

    findSubarray(arr, n, sum);

    return 0;
}
