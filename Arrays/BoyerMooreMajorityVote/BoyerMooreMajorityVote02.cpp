#include <bits/stdc++.h>
using namespace std;

// Function to find majority element is present in an array
int majorityElement(int A[], int n)
{
    // create an empty map
    unordered_map<int, int> map;

    // 1. store each element's frequency in a map
	for (int i = 0; i < n; i++)
        map[A[i]]++;

    // 2. return the element if its count is more than n/2
    for (auto pair: map)
        if (pair.second > n/2)
            return pair.first;

    // Note that step 2 and step 3 can be merged into one
    /* for (int i = 0; i < n; i++)
    {
        if (++map[A[i]] > n/2)
            return A[i];
    } */

    // return -1 if no majority element is present
	return -1;
}

// main function
int main()
{
	int arr[] = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 };

	int n = sizeof(arr)/sizeof(arr[0]);

	int ret = majorityElement(arr, n);
	if (ret != -1)
        cout << "Majority element is " << ret;
    else
        cout << "Majority element doesn't exists";

	return 0;
}
