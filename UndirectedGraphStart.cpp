#include<iostream>
using namespace std;

/*
//vertex is a point
struct GraphElement{
	int degree; //number of connected vertex
	int adjacent[30]; //list of connected vertex
	bool marked; //visited or not
	int edgeTo; //number of the next vertex to go to (to remember path) 
	int distToSource; //increment variable

};    // GraphElement defines the degree, the adjacent vertices of a given vertex
      // We use the adjacency-list graph representation
      // The length of each edge is set as 1

void AddEdge(GraphElement Vertex[],int first, int second);  // there is an edge between first and second, add the edge to the graph Vertex[]
void ConstructGraph(GraphElement Vertex[],int NumberVertex,int NumberEdge,int edges[][2]); // Initialize all vertices and add all edges to graph Vertex[]
void DFS(GraphElement Vertex[], int currentVertex);  // depth-first search on Vertex[], and we start at Vertex[source]
void BFS(GraphElement Vertex[], int source); // breadth-first search on Vertex[], and we start at Vertex[source],output the distance of all vertices to source
void main()
{
	GraphElement Vertex[12]; 
	int edges[20][2]={{0,5},{0,2},{0,3},{3,9},{5,6},{5,2},{2,8},{6,11},{9,10},{8,4},{1,4},{10,1}};
	int NumberVertex=12;   //       number of vertices in the graph
	int NumberEdge=12;     //       number of edges in the graph

	// construct the graph by using the adjacency-list graph representation

	ConstructGraph(Vertex,NumberVertex,NumberEdge,edges);

	for(int q1=0;q1<NumberVertex;q1++)
	{
		printf("vertex%d:  degree=%d   adjacency list:",q1,Vertex[q1].degree);

		for(int q2=0;q2<Vertex[q1].degree;q2++)
		{
			printf("%4d",Vertex[q1].adjacent[q2]);
		}
		printf("\n");
	}
	
	DFS(Vertex,0); // depth-frst search on Vertex[],output all vertices that Vertex[0] is reachable

	for(int q1=0;q1<NumberVertex;q1++)
	{
		Vertex[q1].marked=0;
	}
	printf("\n");
	BFS(Vertex,0);

	getchar();
	getchar();
}

void AddEdge(GraphElement Vertex[],int first, int second)  // there is an edge between first and second, add the edge to the graph Vertex[]
{                                                          // both the adjacent[] and the degree of Vertex[first] and Vertex[second] should be updated

	Vertex[first].adjacent[Vertex[first].degree] = second;
	Vertex[second].adjacent[Vertex[second].degree] = first;
	Vertex[first].degree++;
	Vertex[second].degree++;
}

void ConstructGraph(GraphElement Vertex[],int NumberVertex,int NumberEdge,int edges[][2]) // Initialize all vertices and add all edges to graph Vertex[]
{
	for(int q1=0;q1<NumberVertex;q1++)
	{
		Vertex[q1].degree=0;     // Initialize the degree of each vertex as 0
		Vertex[q1].marked = false;
		Vertex[q1].distToSource = 0;
	}

	// Add each of the edges to graph
	for (int i = 0; i < NumberEdge; i++)
	{
			AddEdge(Vertex, edges[i][0], edges[i][1]);
	}

}

void DFS(GraphElement Vertex[], int currentVertex)  // depth-first search on Vertex[], and we start at Vertex[currentVertex]
{                                            // output all vertices that Vertex[source] is reachable
	Vertex[currentVertex].marked=1;
	printf(" Vertex %d has a path to source.\n",currentVertex);

	for (int i = 0; i < Vertex[currentVertex].degree; i++) //search adjacent vertexes
	{
		if (!Vertex[Vertex[currentVertex].adjacent[i]].marked) { //if not marked
			DFS(Vertex, Vertex[currentVertex].adjacent[i]);
			Vertex[Vertex[currentVertex].adjacent[i]].edgeTo = currentVertex;
		}
	}

	

}

void BFS(GraphElement Vertex[], int source)  // breadth-first search on Vertex[], and we start at Vertex[source]
{                                                   // output the distance of all vertices to source
	int Queue[20];

	int currentInQueue, LastOfQueue;         // currentInQueue is the index of the entry we are processing, LastOfQueue is the index of the last entry of Queue[]

	Queue[0] = source, currentInQueue = 0, LastOfQueue = 0;
	Vertex[Queue[0]].marked = 1;             // Queue[0] is marked as processed
	Vertex[Queue[0]].distToSource = 0;       // Distance between Queue[0] and source is 0.
	Vertex[Queue[0]].edgeTo = source;
	while (currentInQueue<= LastOfQueue) {
		//increment currentInQueue
		printf(" Vertex %d : edgeTo %d , distTo %d.\n", Queue[currentInQueue],Vertex[Queue[currentInQueue]].edgeTo, Vertex[Queue[currentInQueue]].distToSource);
		for (int i = 0; i < Vertex[Queue[currentInQueue]].degree; i++)
		{
			if (!Vertex[Vertex[Queue[currentInQueue]].adjacent[i]].marked) { //if not marked update queue
				LastOfQueue++;
				Queue[LastOfQueue] = Vertex[Queue[currentInQueue]].adjacent[i]; // add to queue
				Vertex[Queue[LastOfQueue]].marked = true; //signal as marked
				Vertex[Queue[LastOfQueue]].edgeTo = Queue[currentInQueue]; //vertex before in the path
				Vertex[Queue[LastOfQueue]].distToSource = Vertex[Queue[currentInQueue]].distToSource +1;//increment path size
			}
		}
		currentInQueue++;
	}
}*/