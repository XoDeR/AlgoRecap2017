#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 5

// data structure to store graph edges
struct Edge {
	int src, dest;
};

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

// Perform DFS on graph starting from vertex v
int DFS(Graph const &graph, int v, vector<bool> 
	&discovered, int arrival[], bool& isSC, int &time)
{
	// terminate the search if graph is not strongly 
	// connected
	if (!isSC)
		return false;
	
	// set arrival time of vertex v
	arrival[v] = ++time;
 
	// mark vertex as discovered
	discovered[v] = true;
 
	// initialize arr to arrival time of vertex v
	int arr = arrival[v]; 
 
	// do for every edge (v -> w)
	for (int w : graph.adjList[v]) 
	{
		// vertex w is not yet explored
		if (!discovered[w])
			arr = min(arr, DFS(graph, w, discovered,
					arrival, isSC, time));
		// vertex w is explored before
		else 
			// If the vertex is w is already discovered,
			// that means there is either a cross edge 
			// or a back edge starting from v. Note that
			// the arrival time is already defined for w
			arr = min(arr, arrival[w]);
	}

	// if v is not root node and value of arr didn't 
	// change i.e. it is still set to arrival time of
	// vertex v, the graph is not strongly connected
	if (v != 0 && arr == arrival[v])
		isSC = false;

	// we return the minimum arrival time
	return arr;
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = {
		{0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4}, 
		{3, 1}, {3, 2}, {4, 3}
	};
	
	// create a graph from given edges
	Graph graph(edges);

	// stores vertex is discovered or not
	vector<bool> discovered(N);
 
	// array to store arrival time of vertex.
	int arrival[N];
	
	// flag to determine if graph is strongly connected
	// or not
	bool isSC = true;
	int time = -1;
	
	// Do DFS traversal starting from first vertex.
	DFS(graph, 0, discovered, arrival, isSC, time);

	// If DFS traversal doesn’t visit all vertices, 
	// then graph is not strongly connected
	for (int i = 0; i < N; i++)
		if (discovered[i] == false)
			isSC = false;

	if (isSC)
		cout << "Graph is Strongly Connected";
	else
		cout << "Graph is not Strongly Connected";
		
	return 0;
}