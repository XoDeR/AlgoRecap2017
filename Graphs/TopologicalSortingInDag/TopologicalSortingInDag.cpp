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
		// add edges to the Directed graph
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			
			adjList[src].push_back(dest);
		}
	}
};
	
// Perform DFS on graph and set departure time of all 
// vertices of the graph
int DFS(Graph const &graph, int v, vector<bool> 
	&discovered, vector<int> &departure, int& time)
{
	// mark current node as discovered
	discovered[v] = true;

	// set arrival time
	time++;

	// do for every edge (v -> u)
	for (int u : graph.adjList[v])
	{
		// u is not discovered
		if (!discovered[u])
			DFS(graph, u, discovered, departure, time);
	}
	
	// ready to backtrack
	// set departure time of vertex v
	departure[time] = v;
	time++;
}

// performs Topological Sort on a given DAG
void doTopologicalSort(Graph const& graph)
{
	// departure[] stores vertex number having its depature
	// time equal to the index of it
	vector<int> departure(2*N, -1);
	
	// Note if we had done the other way around i.e. fill 
	// array with depature time by using vertex number  
	// as index, we would need to sort the array later

	// stores vertex is discovered or not
	vector<bool> discovered(N);
	int time = 0;
 
	// perform DFS on all undiscovered vertices
	for (int i = 0; i < N; i++)
		if (!discovered[i])
			DFS(graph, i, discovered, departure, time);

	// Print the vertices in order of their decreasing 
	// departure time in DFS i.e. in topological order
	for (int i = 2*N - 1; i >= 0; i--)
		if (departure[i] != -1)
			cout << departure[i] << " ";
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = 
	{
		{0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4},
		{5, 1}, {7, 0}, {7, 1}
	};

	// create a graph from edges
	Graph graph(edges);

	// perform Topological Sort
	doTopologicalSort(graph);

	return 0;
}
