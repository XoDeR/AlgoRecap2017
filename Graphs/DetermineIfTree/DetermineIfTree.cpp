#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 6

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
		// add edges to the undirected graph
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			
			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};

// Perform DFS on graph and returns true if any back-edge
// is found in the graph
bool DFS(Graph const &graph, int v, vector<bool> 
		&discovered, int parent)
{
	// mark current node as discovered
	discovered[v] = true;

	// do for every edge (v -> w)
	for (int w : graph.adjList[v])
	{
		// w is not discovered
		if (!discovered[w])
		{
			if (!DFS(graph, w, discovered, v))
				return false;
		}

		// w is discovered and w is not a parent
		else if (w != parent)
		{
			// we found a back-edge (cycle)
			return false;
		}
	}
	
	// No back-edges found in the graph
	return true;
}

// main function
int main()
{
	// initalize edges as per above diagram
	vector<Edge> edges = 
	{
		{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}
		// edge (5->0) introduces a cycle in the graph
	};

	// create a graph from edges
	Graph graph(edges);

	// stores vertex is discovered or not
	vector<bool> discovered(N);
	
	// boolean flag to store if the graph is tree or not
	bool isTree = true;
	
	// Do DFS traversal from first vertex
	isTree = DFS(graph, 0, discovered, -1);

	for (int i = 0; isTree && i < N; i++)
	{
		// any undiscovered vertex means graph is not connected
		if (!discovered[i])
			isTree = false;
	}
	
	if (isTree)
		cout << "Graph is a Tree";
	else 
		cout << "Graph is not a Tree";
	
	return 0;
}