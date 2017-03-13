#include<bits/stdc++.h>
using namespace std;

struct Pair
{
	// stores start time and finish time of the activities
	int start, finish;
};

// Activity-Selection problem
set<int> selectActivity(vector<Pair> vc)
{
	// k keeps track of the index of the last selected activity
	int k = 0;
	
	// set to store the selected activities index
	set<int> out;
	// select 0 as first activity
	out.insert(0);
	
	// start iterating from the second element of 
	// vector up to its last element
	for (int i = 1; i < vc.size(); i++)
	{
		// if start time of ith activity is is greater or equal
		// to the finish time of the last selected activity, it 
		// can be included in activities list
		if (vc[i].start >= vc[k].finish)
		{
			out.insert(i);
			k = i;	// update i as last selected activity
		}
	}

	return out;
}

// main function
int main()
{
	// vector of pairs with each pair storing start time 
	// and finish time of the activities
	vector<Pair> v = 
	{
		{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, 
		{6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
	};

	// Sort the activities according to their finishing time
	sort(v.begin(), v.end(), [](auto &lhs, auto &rhs) {
		return lhs.finish < rhs.finish;
	});

	set<int> out = selectActivity(v);
	for (int i : out)
		cout << "(" << v[i].start << "  " << v[i].finish << ")" << endl;

	return 0;
}
