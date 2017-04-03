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

// array can handle up to 20 node graph. Add more colors for graphs
// containing more than 20 vertices
string color[] = {"", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
				"BLACK", "BROWN", "WHITE", "PURPLE", "VOILET"};

// assign colors to vertices of graph
void colorGraph(Graph const &graph)
{
	// stores color assigned to each vertex
	map<int, int> result;

	// assign color to vertex one by one
	for (int u = 0; u < N; u++)
	{
		// set to store color of adjacent vertices of u
		set<int> assigned;

		// check colors of adjacent vertices of u and store in set
		for (int i : graph.adjList[u])
			if (result[i])
				assigned.insert(result[i]);

		// check for first free color
		int color = 1;
		for (auto c : assigned )
		{
			if (color != c)
				break;
			color++;
		}

		// assigns vertex u the first available color
		result[u] = color;
	}

	for (int v = 0; v < N; v++)
		cout << "Color assigned to vertex " << v << " is "
			 << color[result[v]] << endl;
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges =
	{
		{0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4},
	};

	// create a graph from edges
	Graph graph(edges);

	// color graph using greedy algorithm
	colorGraph(graph);

	return 0;
}
