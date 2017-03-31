#include <bits/stdc++.h>
using namespace std;

// Function to find all Permutations of a given string 
// containing all distinct characters
void permutations(string str, int n, string res)
{
	// base condition (only one character is left in the string)
    if (n == 1)
    	cout << res + str << endl;
    else
	{
		// process each character of remaining string
		for (int i = 0; i < n; i++)
	    {
	    	// push current character to the output string and recuse for 
	    	// the remaining characters
	        permutations(str.substr(1), n - 1, res + str[0]);
	        
	        // left rotate the string by 1 unit for next iteration
	        // to right rotate the string use reverse iterator
	        rotate(str.begin(), str.begin() + 1, str.end());
	    }

	} 	
}

// main method
int main()
{
    string str = "ABC";
    string res;	// empty string
    
    permutations(str, str.size(), res);
    
    return 0;
}