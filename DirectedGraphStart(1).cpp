#include<iostream>
#include <string> 

using namespace std;
/*
struct DigraphElement{
	int InDegree;
	int OutDegree;
	int adjacent[30];
	bool marked;
	int edgeTo;
	int distToSource;

};    // DiDigraphElement defines the InDegree, OutDegree and the adjacency list of a given vertex
      // We use the adjacency-list graph representation
      // The length of each edge is set as 1

void AddEdge(DigraphElement Vertex[],int first, int second);  // there is a directed edge directing from first to second, add the edge to the graph Vertex[]
void ConstructGraph(DigraphElement Vertex[],int NumberVertex,int NumberEdge,int edges[][2]); // Initialize all vertices and add all edges to graph Vertex[]
void DFS(DigraphElement Vertex[], int currentVertex);  // depth-first search on Vertex[], the index of current Vertex is currentVertex
void BFS(DigraphElement Vertex[], int source); 
int main()
{
	DigraphElement Vertex[12]; 
	int edges[20][2]={{0,5},{0,2},{0,3},{3,9},{5,6},{5,2},{2,8},{6,11},{9,10},{8,4},{1,4},{1,10}}; //a directed edge directing from first to second (i.e., 0->5, 0->2)
	int NumberVertex=12;   //       number of vertices in the graph
	int NumberEdge=12;     //       number of edges in the graph


	ConstructGraph(Vertex, NumberVertex, NumberEdge, edges); // construct the graph by using the adjacency-list graph representation

	for(int q1=0;q1<NumberVertex;q1++)
	{
		printf("vertex%d:  degree=%d   adjacency list:",q1,Vertex[q1].OutDegree);

		for(int q2=0;q2<Vertex[q1].OutDegree;q2++)
		{
			printf("%4d",Vertex[q1].adjacent[q2]);
		}
		printf("\n");
	}
	printf("\n");

	Vertex[0].edgeTo=-1;

	DFS(Vertex,0); // depth-frst search on Vertex[], output the path of currentVertex directing from source
	printf("\n\n");

	for(int q1=0;q1<NumberVertex;q1++)
	{
		Vertex[q1].marked=0;
		Vertex[q1].edgeTo=-1;
	}

	BFS(Vertex,0);
	getchar();
}

void AddEdge(DigraphElement Vertex[],int first, int second)  //there is a directed edge directing from first to second, add the edge to the graph Vertex[]
{ 
	Vertex[first].adjacent[Vertex[first].OutDegree] = second;
	Vertex[second].adjacent[Vertex[second].InDegree] = first;
	Vertex[first].OutDegree++;
	Vertex[second].InDegree++;

}

void ConstructGraph(DigraphElement Vertex[],int NumberVertex,int NumberEdge,int edges[][2]) // Initialize all vertices and add all edges to graph Vertex[]
{
	for(int q1=0;q1<NumberVertex;q1++) {
		Vertex[q1].InDegree = 0;     // Initialize the degree of each vertex as 0
		Vertex[q1].OutDegree = 0;     // Initialize the degree of each vertex as 0
	}

	for (int i = 0; i < NumberEdge; i++) {
		AddEdge(Vertex, edges[i][0], edges[i][1]); // Add each of the edges to graph
	}
}

void DFS(DigraphElement Vertex[], int currentVertex)  // depth-first search on Vertex[], the index of current Vertex is currentVertex
{                                                     // output the path of currentVertex directing from source
	
	Vertex[currentVertex].marked=1;
	printf(" Vertex %d has a path to source.\n",currentVertex);

	for(int q1=0;q1<Vertex[currentVertex].OutDegree;q1++)
	{
		if(Vertex[Vertex[currentVertex].adjacent[q1]].marked!=1)
		{
			DFS(Vertex,Vertex[currentVertex].adjacent[q1]);
		}
	}


}

void BFS(DigraphElement Vertex[], int source)  // breadth-first search on Vertex[], and we start at Vertex[source]
{                                              // output the path of all vertices to source

	int Queue[20];
	int currentInQueue, LastOfQueue;
	Queue[0]=source,currentInQueue=0,LastOfQueue=0;
	Vertex[Queue[0]].marked=1;             // Queue[0] is marked as processed
	Vertex[Queue[0]].distToSource=0;       // Distance between Queue[0] and source is 0.

	while(currentInQueue<=LastOfQueue)
	{
		 for(int q1=0;q1<Vertex[Queue[currentInQueue]].OutDegree;q1++)
		 {
			if(Vertex[Vertex[Queue[currentInQueue]].adjacent[q1]].marked!=1)
			{
				LastOfQueue++;
				Queue[LastOfQueue]=Vertex[Queue[currentInQueue]].adjacent[q1];
				Vertex[Vertex[Queue[currentInQueue]].adjacent[q1]].marked=1;
				Vertex[Vertex[Queue[currentInQueue]].adjacent[q1]].distToSource=Vertex[Queue[currentInQueue]].distToSource+1;
			}	
		 }
	  currentInQueue++;
	}

}*/