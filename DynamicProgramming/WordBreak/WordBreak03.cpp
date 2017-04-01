#include <bits/stdc++.h> 
using namespace std;

// define maximum string length
#define N 50

// look-up array to store solutions to sub-problems
// lookup[i] stores if substring str[n-i..n) can be segmented or not
int lookup[N+1] = {-1};

// Function to determine if string can be segmented into a space-separated 
// sequence of one or more dictionary words
bool wordBreak(vector<string> dict, string str)
{
	// n stores length of current substring
    int n = str.size();

	// return true if we have reached the end of the string
	if (n == 0)
		return true;

	// if sub-problem is seen for the first time
    if(lookup[n] == -1)
    {
	    // mark sub-problem as seen (0 initally assuming string 
	    // can't be segmented)
        lookup[n] = 0;
    
        for (int i = 1; i <= n; i++) 
        {
			// consider all prefixes of current string
            string prefix = str.substr(0, i);
    
    		// if prefix is found in dictionary, then recuse for suffix
            if (find(dict.begin(), dict.end(), prefix) != dict.end() && 
                wordBreak(dict, str.substr(i)))
            {
            	// return true if the string can be segmented
                return lookup[n] = 1;
            }
        }
    }

	// return solution to current sub-problem
    return lookup[n];
}

// main function
int main()
{
	// vector of strings to represent dictionary
	// we can also use trie or std::set to store dictionary
    vector<string> dict = { "this", "th", "is", "famous", "Word", "break", "b",
					"r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

	// input string
	string str = "Wordbreakproblem";
    
	memset(lookup, -1, sizeof(lookup));

    if (wordBreak(dict, str))
    	cout << "String can be segmented";
	else
		cout << "String can't be segmented";

    return 0;
}
