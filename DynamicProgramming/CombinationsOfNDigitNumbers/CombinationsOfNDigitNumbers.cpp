#include <bits/stdc++.h>
using namespace std;

// Maximum N-digit number allowed
#define N 8

// create a lookup table to store solutions of subproblems
// lookup[i][j] stores count of all numbers starting from digit i 
// having length n
int lookup[10][N];

// Below arrays details all 4 possible movements from current cell
int row[] = { 0, -1, 0, 1 };
int col[] = { -1, 0, 1, 0 };

// The function returns false if (i, j) is not a valid position
int isValid(int i, int j)
{
	// for handling '*' or '#' (present in 4th row and 1st & 3rd column)
	if (i == 3 && (j == 0 || j == 2))
		return 0;

	return (i >= 0 && i <= 3 && j >= 0 && j <= 2);
}

// Function to fill a multimap that stores the mapping of cells  
// reachable from current cell
void fillMap(multimap<int, int>& mp)
{
	// mobile keypad
	char key[4][3] = 
	{
		{ '1', '2', '3' },
		{ '4', '5', '6' },
		{ '7', '8', '9' },
		{ '*', '0', '#' } 
	};
	
	// do for each row
	for (int i = 0; i < 4; i++)
	{
		// do for each column of row i
		for (int j = 0; j < 3; j++)
		{
			// move in all four possible directions of current 
			// digit key[i][j]
			for (int k = 0; k < 4; k++) 
			{
				int r = i + row[k];
				int c = j + col[k];
				
				// insert adjacent cell to multimap if valid
				if (isValid(i, j) && isValid(r, c))
					mp.insert(pair<int, int>(key[i][j] - '0', key[r][c] - '0'));
			}
		}
	}
}

// Function to count all numbers starting from digit i and
// having length n
int getCount(multimap<int, int> keypad, int i, int n)
{
	if (n == 1) // reached end of digit
		return 1;

	// if sub-problem is seen for the first time, solve it and 
	// store its result in a array
	if (lookup[i][n] == 0) 
	{
		// recurse for digit i
		lookup[i][n] = getCount(keypad, i, n - 1);

		// recur for all digits reachable from i
		for (auto it = keypad.find(i); (it->first == i); it++)
			lookup[i][n] += getCount(keypad, it->second, n - 1);
	}

	// return the subproblem solution
	return lookup[i][n];
}

// main function
int main()
{
	int n = 2;
	
	// use a multimap to store mapping of cells reachable 
	// from current cell
	multimap<int, int> keypad;
	fillMap(keypad);
	
	int count = 0;
	// get count of of each digit
	for (int i = 0; i <= 9; i++)
		count += getCount(keypad, i, n);

	cout << "Total possible combinations are " << count;

	return 0;
}
