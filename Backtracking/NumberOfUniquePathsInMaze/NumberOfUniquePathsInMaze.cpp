#include <bits/stdc++.h>
using namespace std;
#define N 4

// Check if cell (x, y) is valid or not
bool isValidCell(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;

	return true;
}

void countPaths(int maze[N][N], int x, int y, int visited[N][N], int& count)
{
	// if destination (bottom-rightmost cell) is found, 
	// increment the path count
	if (x == N - 1 && y == N - 1) 
	{
		count++;
		return;
	}

	// mark current cell as visited
	visited[x][y] = 1;
	
	// if current cell is a valid and open cell, 
	if (isValidCell(x, y) && maze[x][y]) 
	{
		// go down (x, y) --> (x + 1, y)
		if (!visited[x + 1][y])
			countPaths(maze, x + 1, y, visited, count);
			
		// go up (x, y) --> (x - 1, y)
		if (!visited[x - 1][y])
			countPaths(maze, x - 1, y, visited, count);
			
		// go right (x, y) --> (x, y + 1)
		if (!visited[x][y + 1])
			countPaths(maze, x, y + 1, visited, count);
			
		// go left (x, y) --> (x, y - 1)
		if (!visited[x][y - 1])
			countPaths(maze, x, y - 1, visited, count);
	}
	
	// backtrack from current cell and remove it from current path
	visited[x][y] = 0;
}

int main()
{
	int maze[N][N] = 
	{
		{ 1, 1, 1, 1 },
		{ 1, 1, 0, 1 },
		{ 0, 1, 0, 1 },
		{ 1, 1, 1, 1 }
	};

	// stores number of unique paths from source to destination
	int count = 0;

	// 2D matrix to keep track of cells involved in current path
	int visited[N][N];
	memset(visited, 0, sizeof visited);
	
	// start from source cell (0, 0)
	countPaths(maze, 0, 0, visited, count);
	
	cout << "Total number of unique paths are " << count;
	
	return 0;
}
