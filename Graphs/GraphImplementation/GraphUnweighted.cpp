#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 6

// data structure to store Adjacency list nodes
struct Node {
	int dest;
	Node* next;
};

// data structure to store graph edges
struct Edge {
	int src, dest;
};

class Graph 
{
	// Function to allocate new node of Adjacency List
	Node* getAdjListNode(int dest, Node* head)
	{
		Node* newNode = new Node;
		newNode->dest = dest;
		
		// point new node to current head
		newNode->next = head;

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

			// insert in the beginning
			Node* newNode = getAdjListNode(dest, head[src]);
			// point head pointer to new node
			head[src] = newNode;

			// Uncomment below lines for undirected graph
			/*
			newNode = getAdjListNode(src, head[dest]);
			
			// change head pointer to point to the new node
			head[dest] = newNode; 
			*/
		}
	}
};

// print all neighboring vertices of given vertex 
void printList(Node* ptr)
{
	while (ptr != NULL) 
	{
		cout << ptr->dest << " ";
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
		// (x, y) represents edge from x to y
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// construct graph
	Graph graph(edges);

	// print adjacency list representation of graph
	for (int i = 0; i < N; i++) 
	{
		// print given vertex
		cout << i << " --> ";
		
		// print all its neighboring vertices 
		printList(graph.head[i]);
	}
	
	return 0;
}