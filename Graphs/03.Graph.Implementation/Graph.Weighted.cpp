#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 6

// data structure to store Adjacency list nodes
struct Node 
{
	int dest, weight;
	Node* next;
};

// data structure to store graph edges
struct Edge {
	int src, dest, weight;
};

class Graph 
{
	// Function to allocate new node of Adjacency List
	Node* getAdjListNode(int dest, int weight, Node* next)
	{
		Node* newNode = new Node;
		newNode->dest = dest;
		newNode->weight = weight;
		
		// point new node to current head
		newNode->next = next;
		
		return newNode;
	}

public:

	// An array of pointers to Node to represent 
	// adjacency list
	Node* head[N];

	// Constructor
	Graph(vector<Edge> edges)
	{
		// initialize head pointer for all vertices 
		for (int i = 0; i < N; ++i)
			head[i] = NULL;

		// add edges to the directed graph
		for (unsigned i = 0; i < edges.size(); i++) 
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			int weight = edges[i].weight;
			
			// insert in the beginning
			Node* newNode = getAdjListNode(dest, weight, 
											head[src]);
			// change head pointer to point to the new node
			head[src] = newNode;

			// Uncomment below lines for undirected graph
			/* 
			newNode = getAdjListNode(src, weight, 
										head[dest]);
			
			// change head pointer to point to the new node
			head[dest] = newNode; 
			*/
		}
	}
};

// print all neighboring vertices of given vertex 
void printList(Node* ptr, int i)
{
	while (ptr != NULL) 
	{
		cout << "(" << i << ", " << ptr->dest 
			<< ", " << ptr->weight << ") ";
		ptr = ptr->next;
	}
	cout << endl;
}

// main function
int main()
{
	// vector of graph edges as per above diagram. Please 
	// note that initialization vector in below format will
	// work fine in C++11 and C++14 but will fail in C++98.
	vector<Edge> edges = 
	{
		// (x, y, w) -> edge from x to y having weight w
		{ 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 }, 
		{ 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
	};

	// construct graph
	Graph graph(edges);

	// print adjacency list representation of graph
	for (int i = 0; i < N; i++) 
	{
		// print all neighboring vertices of vertex i
		printList(graph.head[i], i);
	}
	
	return 0;
}