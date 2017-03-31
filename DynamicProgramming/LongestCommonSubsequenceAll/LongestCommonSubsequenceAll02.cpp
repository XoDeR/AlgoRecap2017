#include <bits/stdc++.h>
using namespace std;

// define maximum possible length of string X and Y
#define M 20
#define N 25

// lookup[i][j] stores the length of LCS of substring
// X[0..i-1], Y[0..j-1]
int lookup[N][N];

// Function to return all LCS of substrings X[0..m-1], Y[0..n-1]
vector<string> LCS(string X, string Y, int m, int n)
{
	// if we have reached the end of either sequence
    if (m == 0 || n == 0)
    {
        // create a vector with 1 empty string and return
        vector<string> v(1);
        return v;
    }

	// if last character of X and Y matches
    if (X[m - 1] == Y[n - 1])
    {
        // ignore last characters of X and Y and find all LCS of substring
        // X[0..m-2], Y[0..n-2] and store it in a vector
        vector<string> lcs = LCS(X, Y, m - 1, n - 1);

        // append current character X[m - 1] or Y[n - 1] to all LCS of
        // substring X[0..m-2] and Y[0..n-2]
        for (string &str : lcs)         // don't remove &
            str.push_back(X[m - 1]);

        return lcs;
    }

	// we reach here when the last character of X and Y don't match

    // if top cell of current cell has more value than the left cell, 
    // then ignore current character of string X and find all LCS of 
    // substring X[0..m-2], Y[0..n-1]
    if (lookup[m - 1][n] > lookup[m][n - 1])
        return LCS(X, Y, m - 1, n);

    // if left cell of current cell has more value than the top cell, 
    // then ignore current character of string Y and find all LCS of 
    // substring X[0..m-1], Y[0..n-2]
    if (lookup[m][n - 1] > lookup[m - 1][n])
        return LCS(X, Y, m, n - 1);

    // if top cell has equal value to the left cell, then consider both character

    vector<string> top = LCS(X, Y, m - 1, n);
    vector<string> left = LCS(X, Y, m, n - 1);

    // merge two vectors and return
    top.insert(top.end(), left.begin(), left.end());
    // copy(v2.begin(), v2.end(), back_inserter(v1));

    return top;
}

// Function to fill lookup table by finding the length of LCS
// of substring X[0..m-1] and Y[0..n-1]
void LCSLength(string X, string Y, int m, int n)
{
	// first column of the lookup table will be all 0
	for (int i = 0; i <= m; i++)
		lookup[i][0] = 0;

	// first row of the lookup table will be all 0
	for (int j = 0; j <= n; j++)
		lookup[0][j] = 0;

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
				lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
		}
	}
}

// Function to find all LCS of string X[0..m-1] and Y[0..n-1]
set<string> LCS(string X, string Y)
{
    int m = X.length(), n = Y.length();

    // fill lookup table
    LCSLength(X, Y, m, n);

    // find all longest common sequences
    vector<string> v = LCS(X, Y, m, n);

    // since vector can contain duplicates, "convert" the vector to set
    set<string> lcs(make_move_iterator(v.begin()), make_move_iterator(v.end()));

    // to copy a vector to a set use set<string> s(v.begin(), v.end())

    // return set containing all LCS
    return lcs;
}

// main function
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";

    set<string> lcs = LCS(X, Y);

    // print set elements
    for (string str : lcs)
        cout << str << endl;

    return 0;
}
