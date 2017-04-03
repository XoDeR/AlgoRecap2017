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
		}
	}
};

// class to represent a disjoint set
class DisjointSet 
{
	unordered_map<int, int> parent;
public:
	// perform MakeSet operation
	void makeSet()
	{
		// create N disjoint sets (one for each vertex)
		for (int i = 0; i < N; i++)
			parent[i] = i;
	}

	// Find the root of the set in which element k belongs
	int Find(int k)
	{
		// if k is root
		if (parent[k] == k)
			return k;

		// recurse for parent until we find root
		return Find(parent[k]);
	}

	// Perform Union of two subsets
	void Union(int a, int b)
	{
		// find root of the sets in which elements 
		// x and y belongs
		int x = Find(a);
		int y = Find(b);

		parent[x] = y;
	}
};

// returns true if graph has cycle
bool findCycle(Graph const &graph)
{
	// initialize DisjointSet class
	DisjointSet ds;

	// create singleton set for each element of universe
	ds.makeSet();
 
	// consider every edge (u -> v)
	for (int u = 0; u < N; u++)
	{
		// Recur for all adjacent vertices 
		for (int v : graph.adjList[u])
		{
			// find root of the sets to which elements 
			// u and v belongs
			int x = ds.Find(u);
			int y = ds.Find(v);
 
			// both u and v have same parent, cycle is found
			if (x == y)
				return true;
			else
				ds.Union(x, y);
		}
	}
 
	return false;
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = 
	{
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4}, 
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {11, 12}
		// edge (11->12) introduces a cycle in the graph
	};
	
	// create a graph from edges
	Graph graph(edges);

	if (findCycle(graph))
		cout << "Cycle Found";
	else 
		cout << "No Cycle Found";
	
	return 0;
}