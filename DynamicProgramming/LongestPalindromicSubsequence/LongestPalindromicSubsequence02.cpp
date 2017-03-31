#include <iostream>
#include <unordered_map>
using namespace std;

// Function to find the length of Longest Palindromic Subsequence 
// of substring X[i..j]
int longestPalindrome(string X, int i, int j, auto &lookup)
{
	// base condition
	if (i > j)
		return 0;

	// if string X has only one character, it is palindrome
	if (i == j)
		return 1;

	// construct a unique map key from dynamic elements of the input
    string key = to_string(i) + "|" + to_string(j);

	// if sub-problem is seen for the first time, solve it and 
    // store its result in a map
    if (lookup.find(key) == lookup.end())
    {	
    	// if last character of the string is same as the first character
		// include first and last characters in palindrome and recuse 
		// for the remaining substring X[i+1, j-1]
		if (X[i] == X[j])
			lookup[key] = longestPalindrome(X, i + 1, j - 1, lookup) + 2;
		else
		
		// if last character of string is different to the first character
	
		// 1. Remove last char & recurse for the remaining substring X[i, j-1]
		// 2. Remove first char & recurse for the remaining substring X[i+1, j]
		// return maximum of the two values
		
		lookup[key] = max (longestPalindrome(X, i, j - 1, lookup), 
					longestPalindrome(X, i + 1, j, lookup));
	 }
 
    // return the subproblem solution from the map
    return lookup[key];
}

int main()
{
	string X = "ABBDCACB";
	int n = X.length();

	// create a map to store solutions of subproblems
    unordered_map<string, int> lookup;
 	
	cout << "The length of Longest Palindromic Subsequence is " << 
		longestPalindrome(X, 0, n - 1, lookup);

	return 0;
}
