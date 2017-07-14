#include <bits/stdc++.h>
using namespace std;

// Data structure to represent an interval
struct Interval
{
	int begin, end;

	bool operator<(Interval i)
	{
		return (begin < i.begin);
	}
};

// Function to merge overlapping intervals
void mergeIntervals(vector<Interval> arr)
{
    // sort the intervals in increasing order of their starting time
	sort(arr.begin(), arr.end());

	// create an empty stack
	stack<Interval> stk;

	// do for each interval
	for (Interval curr: arr)
	{
	    // if stack is empty or top interval in stack do not overlap
	    // with current interval, push it to the stack
		if (stk.empty() || curr.begin > stk.top().end)
			stk.push(curr);

        // if top interval of stack overlap with current interval,
        // merge two intervals by updating ending of top interval
        // to ending of current interval
		if (stk.top().end < curr.end)
			stk.top().end = curr.end;
	}

	// print all non-overlapping intervals
	while (!stk.empty())
	{
		cout << "(" << stk.top().begin << ", " << stk.top().end << ")" << endl;
		stk.pop();
	}
}

// main function
int main()
{ 
	vector<Interval> arr = { { 1, 5 }, { 2, 3 }, { 4, 6 }, { 7, 8 }, 
							 { 8, 10 },  {12, 15} };

	mergeIntervals(arr);

	return 0;
}
