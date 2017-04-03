#include <bits/stdc++.h>
using namespace std;
#define N 8

// Below arrays details all 8 possible movements 
// for a knight
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

// Check if (x, y) is valid chess board cordinates
// Note that a knight cannot go out of the chessboard
bool valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;

	return true;
}

// queue node used in BFS
struct Node
{
	// (x, y) represents chess board cordinates
	// dist represent its minimum distance from the source
	int x, y, dist;
	
	// As we are using struct as a key in a std::map, 
	// we need to overload below operators
	// Alternatively we can use std::pair<int, int> as a key
	// to store cordinates of the matrix in the map
	
	bool const operator==(const Node& o) const
	{
		return x == o.x && y == o.y;
	}

	bool operator<(const Node& o) const
	{
		return x < o.x || (x == o.x && y < o.y);
	}
};

// Find minimum number of steps taken by the knight 
// from source to reach destination using BFS
int BFS(Node src, Node dest)
{
	// map to check if matrix cell is visited before or not
	map<Node, bool> visited;
	
	// create a queue and enqueue first node
	queue<Node> q;
	q.push(src);

	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from queue and process it
		Node node = q.front();
		q.pop();

		int x = node.x;
		int y = node.y;
		int dist = node.dist;
		
		// if destination is reached, return distance
		if (x == dest.x && y == dest.y)
			return dist;

		// Skip if location is visited before
		if (!visited.count(node))
		{
			// mark current node as visited
			visited[node] = true;

			// check for all 8 possible movements for a knight
			// and enqueue each valid movement into the queue
			for (int i = 0; i < 8; ++i) 
			{
				// Get the new valid position of Knight from current
				// position on chessboard and enqueue it in the  
				// queue with +1 distance
				int x1 = x + row[i];
				int y1 = y + col[i];

				if (valid(x1, y1))
					q.push({x1, y1, dist + 1});
			}
		}
	}

	// return INFINITY if path is not possible
	return INT_MAX;
}

// main function
int main()
{
	// source coordinates
	Node src = {0, 7};

	// destination coordinates
	Node dest = {7, 0};

	cout << BFS(src, dest) << endl;

	return 0;
}
