#include <bits/stdc++.h>
using namespace std;

// M x N matrix
#define M 5
#define N 5

// Function to collect maximum value from the first cell (0, 0)
int findMaximum(int mat[M][N])
{
	// T[i][j] stores maximum value that can be collected
	// from any cell to cell (i-1, j-1)
	int T[M+1][N+1];
	memset(T, 0, sizeof T);

	// process each row one by one and fill lookup table T[][]
	for (int i = 1; i<= M; i++)
	{
		// handle odd and even row seperately
		if (i & 1)
		{
			// process current row from left to right
			for (int j = 1; j <= N; j++)
			{
				if (mat[i-1][j-1] == -1)
					T[i][j] = 0;
				else
					T[i][j] = mat[i-1][j-1] + max(T[i][j-1], T[i-1][j]);
			}
		}
		else
		{
			// process current row from right to left
			for (int j = N; j >= 1; j--)
			{
				if (mat[i-1][j-1] == -1)
					T[i][j] = 0;
				else
					T[i][j] = mat[i-1][j-1] + max(T[i][j+1], T[i-1][j]);
			}
		}
	}

	// uncomment below code to print lookup table
	
	/*for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << T[i][j] << " ";
		cout << endl;
	}*/


	// trace maximum ones starting from first cell
	int i = 1, j =1;
    int res = T[i][j];

	while (i <= M && j >= 0 && j <= N)
    {
        if (T[i][j] == T[i+1][j] || T[i][j] + 1 == T[i+1][j])
            i++;
        else if (T[i][j] == T[i][j+1] || T[i][j] + 1 == T[i][j+1])
            j++;
        else if (T[i][j] == T[i][j-1] || T[i][j] + 1 == T[i][j-1])
            j--;
        else
            break;

        res = T[i][j];
    }

	return res;
}

// main function
int main()
{
	int mat[M][N] =
	{
		{  1,  1, -1,  1,  1 },
		{  1,  0,  0, -1,  1 },
		{  1,  1,  1,  1, -1 },
		{ -1, -1,  1,  1,  1 },
		{  1,  1, -1, -1,  1 }
	};

	cout << "Maximum value collected is " << findMaximum(mat);

	return 0;
}
