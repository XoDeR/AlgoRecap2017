#include<bits/stdc++.h>
using namespace std;

// Number of nodes in the graph
#define N 5

// data structure to store graph edges
struct Edge {
	int source, dest, weight;
};

// class to represent a graph object
class Graph
{
	public:
	// A array of vectors to represent adjacency list
	vector<Edge> adjList[N];

	// Constructor
	Graph(vector<Edge> edges)
	{
		// add edges to the undirected graph
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int source = edges[i].source;
			int dest = edges[i].dest;
			int weight = edges[i].weight;
			
			// insert at end
			adjList[source].push_back({source, dest, weight});
		}
	}
};

// data structure to store heap nodes
struct Node {
	int vertex, weight;
};

void printRoute(int prev[], int i)
{
	if (i < 0)
		return;
	
	printRoute(prev, prev[i]);
	cout << i << " ";
}

// Comparison object to be used to order the heap
struct comp 
{
	bool operator()(const Node lhs, const Node rhs) const
	{
		return lhs.weight > rhs.weight;
	}
};

// Run Dijkstra's algorithm on given graph
void shortestPath(Graph const& graph, int source)
{
	// create min heap and push source node having distance 0
	priority_queue<Node, vector<Node>, comp> minHeap;	
	minHeap.push({source, 0});
	
	// set infinite distance from source to v initally
	vector<int> dist(N, INT_MAX);
	// distance from source to itself is zero
	dist[source] = 0;
	
	// boolean array to track vertices for which minimum 
	// cost is already found
	bool done[N] = {0};
	done[0] = 1;

	// stores predecessor of a vertex (to print path)
	int prev[N] = {-1};

	// run till minHeap is not empty
	while (!minHeap.empty())
	{
		// Remove and return best vertex
		Node node = minHeap.top();
		minHeap.pop();

		// get vertex number
		int u = node.vertex;

		// do for each neighbor v of u
		for (auto i : graph.adjList[u])
		{
			int v = i.dest;
			int weight = i.weight;

			// Relaxation step
			if (!done[v] && (dist[u] + weight) < dist[v])
			{
				dist[v] = dist[u] + weight;
				prev[v] = u;
				minHeap.push({v, dist[v]});
			}
		}
		
		// marked vertex u as done so it will not get picked up again
		done[u] = 1;
	}

	for (int i = 1; i < N; ++i)
	{
		cout << "Path from vertex 0 to vertex " << i << " has minimum "
				"cost of " << dist[i] << " and the route is - ";
		printRoute(prev, i);
		cout << endl;
	}
}

// main function
int main()
{
	// initalize edges as per above diagram
	vector<Edge> edges = 
	{
		{0, 1, 10}, {0, 4, 3}, {1, 2, 2}, {1, 4, 4}, {2, 3, 9}, 
		{3, 2, 7}, {4, 1, 1}, {4, 2, 8}, {4, 3, 2}
	};
	
	// construct graph
	Graph graph(edges);

	shortestPath(graph, 0);

	return 0;
}
