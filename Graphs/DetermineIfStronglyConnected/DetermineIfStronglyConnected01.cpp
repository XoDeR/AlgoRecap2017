#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 5

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
		for (unsigned int i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			
			adjList[src].push_back(dest);
		}
	}
};

// Function to perform DFS Traversal
void DFS(Graph const &graph, int v, 
		vector<bool> &discovered)
{
	// mark current node as discovered
	discovered[v] = true;
		
	// do for every edge (v -> u)
	for (int u : graph.adjList[v])
	{
		// u is not discovered
		if (!discovered[u])
			DFS(graph, u, discovered);
	}
}

// check if graph is strongly connected or not
bool check(Graph const& graph)
{
	// do for every vertex
	for (int i = 0; i < N; i++)
	{
	   	// stores vertex is discovered or not
		vector<bool> discovered(N);
		
		// start DFS from first vertex
		DFS(graph, i, discovered);

		// If DFS traversal doesn’t visit all vertices, 
		// then graph is not strongly connected
		if (find(discovered.begin(), discovered.end(), 
				false) != discovered.end() )
			return false;
	}
	return true;
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = {
		{0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4}, 
		{3, 1}, {3, 2} , {4, 3}
	};

	// create a graph from given edges
	Graph graph(edges);

	// check if graph is not strongly connected or not
	if (check(graph))
		cout << "Graph is Strongly Connected";
	else 
		cout << "Graph is not Strongly Connected";

	return 0;
}