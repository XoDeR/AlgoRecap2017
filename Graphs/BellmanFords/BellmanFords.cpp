#include <bits/stdc++.h>
using namespace std;

// N is number of vertices in the graph
#define N 5

// data structure to store graph edges
struct Edge 
{
	int source, dest, weight;
};

// Recurive Function to print path of given 
// vertex v from source vertex
void printPath(int parent[], int v)
{
	if (v < 0)
		return;

	printPath(parent, parent[v]);
	cout << v << " ";
}

// Function to run Bellman-Ford algorithm from given source
void BellmanFord(vector<Edge> edges, int source)
{
	// count number of edges present in the graph
	int E = edges.size();
	
	// distance[] and parent[] stores shortest-path 
	// (least cost/path) information
	int distance[N], parent[N];

	// initialize distance[] and parent[]. Initally all
	// vertices except source vertex have a weight of 
	// infinity and a no parent
	for (int i = 0; i < N; i++)
		distance[i] = INT_MAX, parent[i] = -1;
	distance[source] = 0;

	int u, v, w, k = N;

	// Relaxation step (run V -1 times)
	while (--k)
	{
		for (int j = 0; j < E; j++) 
		{
			// edge from u to v having weight w		
			u = edges[j].source, v = edges[j].dest;
			w = edges[j].weight;
			
			// if the distance to the destination v can be 
			// shortened by taking the edge u-> v
			if (distance[u] != INT_MAX && distance[u] + w < distance[v])
			{
				// update distance to the new lower value
				distance[v] = distance[u] + w;
				
				// set v's parent as u
				parent[v] = u;
			}
		}
	}

	// run Relaxation step once more for Nth time to 
	// check for negative-weight cycles
	for (int i = 0; i < E; i++) 
	{
		// edge from u to v having weight w
		u = edges[i].source, v = edges[i].dest;
		w = edges[i].weight;

		// if the distance to the destination u can be 
		// shortened by taking the edge u-> v		
		if (distance[u] != INT_MAX && 
			distance[u] + w < distance[v])
		{
			cout << "Negative Weight Cycle Found!!";
			return;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << "Distance of vertex " << i << " from the source is " 
			 << setw(2) << distance[i] << ". It's path is \" ";
			 printPath(parent, i); cout << "\"" << endl;
	}	
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = 
	{
		// (x, y, w) -> edge from x to y having weight w
		{ 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, { 1, 3, 2 },
		{ 1, 4, 2 }, { 3, 2, 5 }, { 3, 1, 1 }, { 4, 3, -3 }
	};

	// let source be vertex 0
	int source = 0;

	// run Bellman-Ford algorithm from given source
	BellmanFord(edges, source);

	return 0;
}
