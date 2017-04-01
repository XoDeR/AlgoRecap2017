#include <iostream>
using namespace std;

// print all n-digit binary strings without any consecutive 1's
void countStrings(int n, string out, int last_digit)
{
	// if number becomes N-digit, print it
	if (n == 0)
	{
		cout << out << " ";
		return;
	}

	// append 0 to the result and recuse with one less digit
	countStrings(n - 1, out + "0", 0);
	
	// append 1 to the result and recuse with one less digit
	// only if last digit is 0
	if (last_digit == 0)
		countStrings(n - 1, out + "1", 1);
}

// main function
int main()
{
	// given number of digits
	int n = 5;
	string out = "";
	
	countStrings(n, out, 0);

	return 0;
}