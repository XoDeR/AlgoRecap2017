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
	vector<int> adj[N];

	// Constructor
	Graph(vector<Edge> edges)
	{
		// add edges to the undirected graph
		for(int i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			adj[src].push_back(dest);
			adj[dest].push_back(src);
		}
	}
};

// string array to store colors (10-colorable graph)
string COLORS[] = {"", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE",
				"PINK", "BLACK", "BROWN", "WHITE", "PURPLE"};

// Function to check if it is safe to assign color c to vertex v
bool isSafe(Graph const &graph, vector<int> color, int v, int c)
{
	// check color of every adjacent vertex of v
	for (int u : graph.adj[v])
		if (color[u] == c)
			return false;

	return true;
}

void kColorable(Graph const &graph, vector<int> color, int k, int v)
{
	// if all colors are assigned, print the solution
	if (v == N)
	{
		for (int v = 0; v < N; v++)
			cout << setw(8) << left << COLORS[color[v]];
		cout << endl;

		return;
	}

	// try all possible combinations of available colors
	for (int c = 1; c <= k; c++)
	{
		// if it is safe to assign color c to vertex v
		if (isSafe(graph, color, v, c))
		{
			// assign color c to vertex v
			color[v] = c;
			
			// recurse for next vertex
			kColorable(graph, color, k, v + 1);
			
			// backtrack
			color[v] = 0;
		}
	}
}

int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges =
	{
		{0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
	};

	// create a graph from edges
	Graph g(edges);

	int k = 3;

	vector<int> color(N, 0);

	// print all k-colorable configurations of the graph
	kColorable(g, color, k, 0);

	return 0;
}