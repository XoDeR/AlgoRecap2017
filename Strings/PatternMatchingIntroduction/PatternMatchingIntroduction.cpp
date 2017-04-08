#include <iostream>
using namespace std;

void find(string text, string pattern, int n, int m)
{
	int i = 0;
	while (i <= n - m) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (text[i + j] != pattern[j])
				break;

			if (j == m - 1)
				cout << "Pattern occurs with shift " << i << endl;
		}
		i++;
	}
}

int main()
{
	string text = "abcabaabcabac";
	string pattern = "cab";

	int n = text.length();
	int m = pattern.length();

	find(text, pattern, n, m);

	return 0;
}