#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 13

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
			if (DFS(graph, w, discovered, v))
				return true;
		}

		// w is discovered and w is not a parent
		else if (w != parent)
		{
			// we found a back-edge (cycle)
			return true;
		}
	}
	
	// No back-edges found in the graph
	return false;
}

// main function
int main()
{
	// initalize edges as per above diagram
	vector<Edge> edges = 
	{
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4}, 
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {11, 12}
		// edge (11->12) introduces a cycle in the graph
	};

	// create a graph from edges
	Graph graph(edges);

	// stores vertex is discovered or not
	vector<bool> discovered(N);
	
	// Do DFS traversal from first vertex
	if (DFS(graph, 1, discovered, -1))
		cout << "Graph contains cycle";
	else 
		cout << "Graph doesn't contain any cycle";
	
	return 0;
}