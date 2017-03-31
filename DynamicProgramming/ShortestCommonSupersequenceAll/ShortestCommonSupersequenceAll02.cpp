#include <bits/stdc++.h>
using namespace std;

// define maximum possible length of string X and Y
#define MAX 20

// lookup[i][j] stores the length of SCS of substring X[0..i-1], Y[0..j-1]
int lookup[MAX][MAX];

// Function to return all SCS of substrings X[0..m-1], Y[0..n-1]
vector<string> SCS(string X, string Y, int m, int n)
{
	// if we have reached the end of first string, create a vector
	// containing second substring and return
	if (m == 0)
	{
		vector<string> v;
		v.push_back(Y.substr(0, n));
		return v;
	}

	// if we have reached the end of second string, create a vector
	// containing first substring and return
	else if (n == 0)
	{
		vector<string> v;
		v.push_back(X.substr(0, m));
		return v;
	}

	// if last character of X and Y is same, it should occur 
	// only one time in SSC
	if (X[m - 1] == Y[n - 1])
	{
		// find all SCS of substring X[0..m-2], Y[0..n-2]
		vector<string> scs = SCS(X, Y, m - 1, n - 1);

		// append current character X[m - 1] or Y[n - 1] to all SCS of
		// substring X[0..m-2] and Y[0..n-2]

		for (string &str : scs)		 // don't remove &
			str.push_back(X[m - 1]);

		return scs;
	}

	// we reach here when the last character of X and Y don't match

	// if top cell of current cell has less value than the left cell,
	// then append current character of string X to all SCS of
	// substring X[0..m-2], Y[0..n-1]

	if (lookup[m - 1][n] < lookup[m][n - 1])
	{
		vector<string> scs = SCS(X, Y, m - 1, n);

		for (string &str : scs)		 // don't remove &
			str.push_back(X[m - 1]);

		return scs;
	}

	// if left cell of current cell has less value than the top cell,
	// then append current character of string Y to all SCS of
	// substring X[0..m-1], Y[0..n-2]

	if (lookup[m][n - 1] < lookup[m - 1][n])
	{
		vector<string> scs = SCS(X, Y, m, n - 1);

		for (string &str : scs)		 // don't remove &
			str.push_back(Y[n - 1]);

		return scs;
	}

	// if top cell value is same as left cell, then go in both 
	// top and left directions

	// append current character of string X to all SCS of
	// substring X[0..m-2], Y[0..n-1]
	vector<string> top = SCS(X, Y, m - 1, n);
	for (string &str : top)		 // don't remove &
			str.push_back(X[m - 1]);

	// append current character of string Y to all SCS of
	// substring X[0..m-1], Y[0..n-2]
	vector<string> left = SCS(X, Y, m, n - 1);
	for (string &str : left)		 // don't remove &
		str.push_back(Y[n - 1]);

	// merge two vectors and return
	top.insert(top.end(), left.begin(), left.end());
	// copy(left.begin(), left.end(), back_inserter(top));

	return top;
}

// Function to fill lookup table by finding length of SCS of 
// sequences X[0..m-1] and Y[0..n-1]
int SCSLength(string X, string Y, int m, int n)
{
	// first row and first column of the lookup table
	// are already 0 as lookup[][] is globally declared

	// initalize first column of the lookup table
	for (int i = 0; i <= m; i++)
		lookup[i][0] = i;

	// initalize first row of the lookup table
	for (int j = 0; j <= n; j++)
		lookup[0][j] = j;

	// fill the lookup table in bottom-up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// if current character of X and Y matches
			if (X[i - 1] == Y[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 1;
		
			// else if current character of X and Y don't match
			else
				lookup[i][j] = min(lookup[i - 1][j] + 1, lookup[i][j - 1] + 1);
		}
	}
}

// Function to find all Shortest Common Supersequence of string X and Y
set<string> SCS(string X, string Y)
{
	int m = X.length(), n = Y.length();

	// fill lookup table
	SCSLength(X, Y, m, n);

	// find all Shortest Common Supersequence
	vector<string> v = SCS(X, Y, m, n);

	// since vector can contain duplicates, "copy" the vector to set
	set<string> scs(v.begin(), v.end());

	// to "convert" a vector to a set use 
	// set<string> scs(make_move_iterator(v.begin()), make_move_iterator(v.end()));

	// return set containing all SCS
	return scs;
}

// main function
int main()
{
	string X = "ABCBDAB", Y = "BDCABA";

	// Find all Shortest Common Supersequence of string X and Y
	set<string> scs = SCS(X, Y);

	cout << "All Shortest Common Supersequence of " << X << 
			" and " << Y << " are -" << "\n\n";

	// print all SCS present in the set
	for (string str : scs)
			cout << str << endl;

	return 0;
}
