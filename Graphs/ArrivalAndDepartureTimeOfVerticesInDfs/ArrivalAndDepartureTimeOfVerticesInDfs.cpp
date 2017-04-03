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
		for(int i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			
			adjList[src].push_back(dest);
		}
	}
};

// Function to perform DFS Traversal
int DFS(Graph const &graph, int v, vector<bool> &discovered,
	vector<int> &arrival, vector<int> &departure, int &time)
{	
	// set arrival time of vertex v
	arrival[v] = ++time;
 
	// mark vertex as discovered
	discovered[v] = true;
	 
	for(int i : graph.adjList[v])
		if (!discovered[i])
			DFS(graph, i, discovered, arrival, departure, time);
 
	// set departure time of vertex v
	departure[v] = ++time;
}

int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = { 
		{0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5}, 
		{4, 5}, {6, 7}
	};

	// create a graph from edges
	Graph graph(edges);

	// vector to store arrival time of vertex.
	vector<int> arrival(N);

	// vector to store departure time of vertex.
	vector<int> departure(N);
	
	// Mark all the vertices as not discovered
	vector<bool> discovered(N);
	int time = -1;
 
	// Do DFS traversal from all undiscovered nodes to 
	// cover all unconnected components of graph
	for(int i = 0; i < N; i++)
		if (!discovered[i])
			DFS(graph, i, discovered, arrival, departure, time);
	
	// print arrival and departure time of each 
	// vertex in DFS
	for(int i = 0; i < N; i++)
		cout << "Vertex " << i << " (" << arrival[i]
			 << ", " << departure[i] << ")" << endl;
	
	return 0;
}