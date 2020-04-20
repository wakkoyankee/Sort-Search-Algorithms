/*

You only need to write the Dijk_ShortestPath() function

*/
#include<iostream>
using namespace std;

struct DigraphElement{
	int InDegree;
	int OutDegree;
	int adjacent[30];
	float weights[30];           // the above items are basic information for the digraph


	int edgeTo;
	float distTo;
	int pathIdentifiedFlag;     // the above 3 items are information for identifing shortest path

};    // DiDigraphElement defines the InDegree, OutDegree and the adjacency list of a given vertex
      // We use the adjacency-list graph representation


void ConstructGraph(DigraphElement Vertex[],int NumberVertex,int NumberEdge,int edges[][2],float weights[]); // Initialize all vertices and add all edges to graph Vertex[]
void Dijk_ShortestPath(DigraphElement Vertex[],int NumberVertex,int source);  // Identify the shorest path by Dijkstra algorithm from source 

void main()
{
	DigraphElement Vertex[12]; 
	int edges[20][2]={{0,5},{0,2},{0,3},{3,9},{5,6},{5,2},{2,8},{6,11},{9,10},{8,4},{1,4},{10,1},{7,8},{1,7},{3,5},{3,6},{8,9},{10,11}};
	float weights[20]={2.3,3.5,6.1,1.4,1.9,7.2,6.2,3.6,5.5,7.3,2.8,4.6,5.2,1.5,2.8,6.5,1.4,2.3}; // the weights array is coupling with the edges array, i.e., the weight for
	                                                                                             // edge vertex 0 and vertex 5 is 2.3
	int NumberVertex=12;   //       number of vertices in the graph
	int NumberEdge=18;     //       number of edges in the graph

	// construct the graph by using the adjacency-list graph representation
	// this is done by the given program

	ConstructGraph(Vertex,NumberVertex,NumberEdge,edges,weights);

	for(int q1=0;q1<NumberVertex;q1++)
	{
		printf("vertex%2d:   adjacency list (weights):  ",q1);

		for(int q2=0;q2<Vertex[q1].OutDegree;q2++)
		{
			printf("%2d(%4.1f)   ",Vertex[q1].adjacent[q2],Vertex[q1].weights[q2]);
		}
		printf("\n");
	}
	printf("\n");


	Dijk_ShortestPath(Vertex,NumberVertex,0);
	for (int q1 = 0; q1 < NumberVertex; q1++)
	{
		int i = q1;
		while (Vertex[i].edgeTo != 0) {
			cout << i << "<-";
			i = Vertex[i].edgeTo;
		}
		cout << i << "<-" << Vertex[i].edgeTo << " <" << Vertex[q1].distTo <<">"<< endl;
		
	}
	getchar();
	getchar();
}


void ConstructGraph(DigraphElement Vertex[],int NumberVertex,int NumberEdge,int edges[][2],float weights[]) // Initialize all vertices and add all edges to graph Vertex[]
{
	int start,end;

	for(int q1=0;q1<NumberVertex;q1++)
	{
		Vertex[q1].InDegree=0;     // Initialize the InDegree and OutDegree of each vertex as 0
		Vertex[q1].OutDegree=0;
	}

	// Add each of the edges to graph
	 
	for(int q1=0;q1<NumberEdge;q1++)
	{
		start=edges[q1][0];
		end=edges[q1][1];

		Vertex[start].adjacent[Vertex[start].OutDegree]=end;
		Vertex[start].weights[Vertex[start].OutDegree]=weights[q1];
		Vertex[start].OutDegree++;
		Vertex[end].InDegree++;
	}
}

void Dijk_ShortestPath(DigraphElement Vertex[],int NumberVertex,int source)   // Identify the shorest path by Dijkstra algorithm from source 
{
	int numberPath,minVertex,adjacent;
	float minDistance;

	for(int q1=0;q1<NumberVertex;q1++)
	{
		Vertex[q1].pathIdentifiedFlag=0;  // path is not identified for Vertex[q1]
		Vertex[q1].distTo=99999;          // we use 99999 to stand for positive infinity 
		Vertex[q1].edgeTo=9999;
	}

	Vertex[source].distTo=0;              // the distTo of source to source is 0
	Vertex[source].edgeTo = 0;
	numberPath=0;                         // numberPath stands for the number of vertics which has identifed a shortest path to source

	while(numberPath<NumberVertex)
	{
		// find the vertex with the minimum of distTo
		// we index the vertex as minVertex

		
		for (int i = 0; i < NumberVertex; i++)//first vertex that has flag = 0 
		{
			if (Vertex[i].pathIdentifiedFlag == 0) {
				minVertex = i;
				Vertex[minVertex].pathIdentifiedFlag = 1;
				break;
			}
		}

    
		for (int i = 0; i < NumberVertex; i++) //search minimum
		{
			if (Vertex[i].pathIdentifiedFlag == 0 && Vertex[i].distTo < Vertex[minVertex].distTo) {
				Vertex[minVertex].pathIdentifiedFlag = 0;
				minVertex = i;
				Vertex[minVertex].pathIdentifiedFlag = 1;
			}
    
		}
    // perform relaxtion by using Vertex[minVertex]
    // the distTo, edgeTo should be updated in the relaxation
		for (int q1 = 0; q1 < Vertex[minVertex].OutDegree; q1++)
		{
			adjacent = Vertex[minVertex].adjacent[q1];

			if (Vertex[adjacent].distTo > Vertex[minVertex].distTo + Vertex[minVertex].weights[q1])
			{
				Vertex[adjacent].distTo = Vertex[minVertex].distTo
					+ Vertex[minVertex].weights[q1];
				Vertex[adjacent].edgeTo = minVertex;
			}
		}
	









    // you can using the following outputs to check you results
	



    //output the shortest paths for all vertices as formatted in slides











		numberPath++;
	}

}