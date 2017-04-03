#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 6

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
		// add edges to the undirected graph
		for (int i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			
			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};

// Perform DFS on graph starting from vertex v and find 
// all Bridges in the process
int DFS(Graph const &graph, int v, vector<bool> discovered, 
				int arrival[], int parent, int &time)
{
	// set arrival time of vertex v
	arrival[v] = ++time;
 
	// mark vertex as discovered
	discovered[v] = true;
	
	// initialize arr to arrival time of vertex v
	int arr = arrival[v];

	// (v, w) forms a edge
	for (int w : graph.adjList[v])
	{
		// w is not discovered
		if (!discovered[w])
			arr = min(arr, DFS(graph, w, discovered,
							arrival, v, time));

		// w is discovered and w is not parent of v
		else if (w != parent) 
			// If the vertex w is already discovered, that 
			// means that there is a back edge starting 
			// from v. Note that as discovered[u] is already 
			// true, arrival[u] is already defined
			arr = min(arr, arrival[w]);
	}
	
	// if value of arr remains unchanged i.e. it is equal 
	// to the arrival time of vertex v and if v is not root
	// node, then (parent[v] -> v) forms a Bridge
	if (arr == arrival[v] && parent != -1) 
		cout << parent << ", " << v << endl;

	// we return the minimum arrival time
	return arr;
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = { 
		{0, 2}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {3, 5} 
	};
	
	// create a graph from above edges
	Graph graph(edges);

	// stores vertex is discovered or not
	vector<bool> discovered(N);
	
	// stores arrival time of a node in DFS
	int arrival[N];

	int start = 0, parent = -1, time = 0;
	
	// As given graph is connected, DFS will cover every node
	DFS(graph, start, discovered, arrival, parent, time);
	
	return 0;
}
