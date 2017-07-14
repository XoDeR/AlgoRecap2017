#include <bits/stdc++.h>
using namespace std;

// Function to find maximum profit that can be earned by buying and 
// selling shares any number of times
int maxProfit(int rate[], int n)
{
    // store maximum profit gained
    int profit = 0;

    // initialize local minimum to first element's index
	int j = 0;

	// start from second element
	for (int i = 1; i < n; i++)
	{
        // update local minimum if decreasing sequence is found
		if (rate[i - 1] > rate[i])
			j = i;

        // sell shares if current element is peak (previous < current > next)
		if (rate[i - 1] < rate[i] &&
                (i + 1 == n || rate[i] > rate[i + 1]))
        {
            profit += (rate[i] - rate[j]);
            printf("Buy on day %d and sell on day %d\n", j + 1, i + 1);
        }
	}

	return profit;
}

// main function
int main()
{
	int rate[] = { 1, 5, 2, 3, 7, 6, 4, 5 };
	int n = sizeof(rate) / sizeof(rate[0]);

	cout << "\nTotal profit earned is " << maxProfit(rate, n);

	return 0;
}
