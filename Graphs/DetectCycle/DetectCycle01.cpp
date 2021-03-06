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
			adjList[dest].push_back(src);
		}
	}
};

// node to store vertex and its parent info in BFS
struct Node
{
	int v, parent;
};

// Perform BFS on graph starting from vertex src and
// returns true of cycle is found in the graph
bool BFS(Graph const &graph, int src)
{	
	// stores vertex is discovered or not
	vector<bool> discovered(N);
	// mark source vertex as discovered
	discovered[src] = true;

	// create a queue used to do BFS and
	// push source vertex into the queue
	queue<Node> q;
	q.push({src, -1});
 
	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from queue and print it
		Node node = q.front();
		q.pop();

		// do for every edge (v -> u)
		for (int u : graph.adjList[node.v])
		{
			if (!discovered[u])
			{
				// mark it discovered
				discovered[u] = true;
				
				// construct the queue node contaning info 
				// about vertex and push it into the queue
				q.push({ u, node.v });
			}
			
			// u is discovered and u is not a parent
			else if (u != node.parent)
			{
				// we found a cross-edge ie. cycle is found
				return true;
			}
		}
	}
	
	// No cross-edges found in the graph
	return false;
}

// main function
int main()
{
	// initalize edges as per above diagram
	vector<Edge> edges = 
	{ 
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}, {6, 10}
		// edge (6->10) introduces a cycle in the graph
	};
	
	// create a graph from given edges
	Graph graph(edges);
		
	// Do BFS traversal in connected components of graph
	if (BFS(graph, 1))
		cout << "Graph contains cycle";
	else 
		cout << "Graph doesn't contain any cycle";
	
	return 0;
}
