#include <bits/stdc++.h>
using namespace std;

// Iterative function to find all possible combinations of words
// formed from mobile keypad
void findCombinations(vector<char> keypad[], int input[], int n)
{
	// list to store combinations of all possible words
	vector<string> list;
	
	// push all character associated with first digit into the output list
	for (int i = 0; i < keypad[input[0]].size(); i++)
		list.push_back(string(1, keypad[input[0]][i]));

	// start from second digit
	for (int i = 1; i < n; i++)
	{
		// create a temporary vector
		vector<string> v;
		
		// stores current digit
		int digit = input[i];
		
		// for each character associated with current digit in the keypad
		for (int i = 0; i < keypad[digit].size(); i++)
		{
			// append current character to each word in the output list
			// and push to temporary vector
 			for (string str: list)
				v.push_back(str + keypad[digit][i]);
		}
		
		// vector v now contains all possible combinations of words 
		// till current digit
	
		// replace contents of output list with that of temporary vector 
		list = v;
	}
	
	// print  output list containing all combinations of words possible
	for (string str: list)
		cout << str << " ";
}

int main()
{
	vector<char> keypad[] = 
	{
	    {}, {},		// 0 and 1 digit don't have any characters associated
		{ 'A', 'B', 'C' },
		{ 'D', 'E', 'F' },
		{ 'G', 'H', 'I' },
		{ 'J', 'K', 'L' },
		{ 'M', 'N', 'O' },
		{ 'P', 'Q', 'R', 'S'},
		{ 'T', 'U', 'V' },
		{  'W', 'X', 'Y', 'Z'}
	};

	// input number in the form of an array (number can't start from 0 or 1)
	int input[] = {2, 3, 4};
	int n = sizeof(input)/sizeof(input[0]);

	// find all combinations	
	findCombinations(keypad, input, n);

	return 0;
}