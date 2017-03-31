#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 4

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
		for(unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			
			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};

void printAllHamiltonianPaths(Graph g, int v, 
	vector<bool> visited, vector<int> &path)
{
	// if all the vertices are visited, then 
	// hamiltonian path exists
	if (path.size() == N)
	{
		// print hamiltonian path
		for (int i : path)
			cout << i << " ";
		cout << endl;
		
		return;
	}

	// Check if every edge starting from vertex v leads 
	// to a solution or not
	for (int w : g.adjList[v]) 
	{
		// process only unvisited vertices as hamiltonian 
		// path visits each vertex exactly once 
		if (!visited[w]) 
		{
			visited[w] = true;
			path.push_back(w);

			// check if adding vertex w to the path leads 
			// to solution or not
			printAllHamiltonianPaths(g, w, visited, path);

			// Backtrack
			visited[w] = false;
			path.pop_back();
		}
	}
}

int main()
{
	// consider complete graph having 4 vertices
	vector<Edge> edges = 
	{ 
		{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}
	};

	// starting node
	int start = 0;
	
	// create a graph from given edges
	Graph g(edges);

	// add starting node to the path
	vector<int> path;
	path.push_back(start);
	
	// mark start node as visited
	vector<bool> visited(N);
	visited[start] = true;
	
	printAllHamiltonianPaths(g, start, visited, path);
	
	return 0;
}