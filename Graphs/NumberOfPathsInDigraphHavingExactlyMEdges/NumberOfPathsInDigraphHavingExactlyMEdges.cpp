#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 8

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
	public:
	// A array of vectors to represent adjacency list
	vector<int> adjList[N];
	
	// Constructor
	Graph(vector<Edge> edges)
	{
		// add edges to the directed graph
		for (int i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			
			adjList[src].push_back(dest);
		}
	}
};

// BFS Node
struct Node 
{
	// stores current vertex number and current depth of 
	// BFS (how far away current node is from the source?)
	int vertex, depth;
};

// Perform BFS on graph g starting from vertex v
int modifiedBFS(Graph const &g, int src, int dest, int m)
{
	// create a queue used to do BFS
	queue<Node> q;
	
	// push source vertex into the queue
	q.push({src, 0});
	
	// stores number of paths from source to destination
	// having exactly m edges
	int count = 0;
	
	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from queue
		Node node = q.front();
		q.pop();
		
		int v = node.vertex;
		int depth = node.depth;
		
		// if destination is reached and BFS depth is equal to m
		// update count
		if (v == dest && depth == m)
			count++;

		// don't consider nodes having BFS depth more than m.
		// This check will result in optimized code and also
		// handle cycles in the graph (else loop will never break)
		if (depth > m)
			break;

		// do for every adjacent vertex u of v
		for (int u : g.adjList[v])
		{
			// push every vertex (discovered or undiscovered) into
			// the queue
			q.push( {u, depth + 1} );
		}
	}
	
	// return number of paths from source to destination
	return count;
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = 
	{
		{0, 6}, {0, 1}, {1, 6}, {1, 5}, {1, 2}, {2, 3}, {3, 4},
		{5, 2}, {5, 3}, {5, 4}, {6, 5}, {7, 6}, {7, 1}
	};

	// create a graph from edges
	Graph g(edges);

	int src = 0, dest = 3, m = 4;

	// Do modified BFS traversal from source vertex src
	cout << modifiedBFS(g, src, dest, m);

	return 0;
}
