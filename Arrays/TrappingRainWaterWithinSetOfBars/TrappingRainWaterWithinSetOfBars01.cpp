#include <bits/stdc++.h>
using namespace std;

// Function to find amount of water that can be trapped within
// given set of bars in linear time and constant space
int trap(int heights[], int n)
{
    // maintain two pointers left and right pointing to leftmost and
    // rightmost index of the input array
	int left = 0, right = n-1, water = 0;

	int maxLeft = heights[left];
	int maxRight = heights[right];

	while (left < right)
	{
		if (heights[left] <= heights[right])
		{
			left++;
			maxLeft = max(maxLeft, heights[left]);
			water += (maxLeft - heights[left]);
		}
		else
		{
			right--;
			maxRight = max(maxRight, heights[right]);
			water += (maxRight - heights[right]);
		}
	}

	return water;
}

// main function
int main()
{
	int heights[] = { 7, 0, 4, 2, 5, 0, 6, 4, 0, 5 };
	int n = sizeof(heights) / sizeof(heights[0]);

    cout << "Maximum amount of water that can be trapped is " <<
            trap(heights, n);

	return 0;
}
