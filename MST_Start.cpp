#include<iostream>*
using namespace std;
/*
struct GraphElement{
	int degree;
	int adjacent[30];
	float edgeWeights[30];
	int UnionID;               //for Kruskal algorithm

};    // GraphElement defines the degree, the adjacent vertices of a given vertex
      // We use the adjacency-list graph representation
      // The edgeWeights stand for the weights of the edges that connecting a given vertex and the adjacent list

void ConstructGraph(GraphElement Vertex[],int NumberVertex,int NumberEdge,int edges[][2],float weights[]); // Initialize all vertices and add all edges, weights to graph Vertex[]; 
void Kruskal(int edges[][2], float weights[], int numberConnections);  // Generate MST by Kruskal algorithm
void Prime(GraphElement Vertex[], int NumberVertex);  // Generate MST by Prime algorithm
void QuickSort(float Items[], int edges[][2], int low, int high);
int partition(float Items[], int edges[][2], int low, int high);

void main()
{
	GraphElement Vertex[12]; 
	int edges[20][2]={{0,5},{0,2},{0,3},{3,9},{5,6},{5,2},{2,8},{6,11},{9,10},{8,4},{1,4},{10,1},{7,8},{1,7},{3,5},{3,6},{8,9},{10,11}};
	float weights[20]={2.3,3.5,6.1,1.4,1.9,7.2,6.2,3.6,5.5,7.3,2.8,4.6,5.2,1.5,2.8,6.5,1.4,2.3}; // the weights array is coupling with the edges array, i.e., the weight for
	                                                                                             // edge vertex 0 and vertex 5 is 2.3
	int NumberVertex=12;   //       number of vertices in the graph
	int NumberEdge=18;     //       number of edges in the graph

	// construct the graph by using the adjacency-list graph representation

	ConstructGraph(Vertex,NumberVertex,NumberEdge,edges,weights);
	Kruskal(edges,weights,18);
	Prime(Vertex,NumberVertex);
	getchar();
}



void ConstructGraph(GraphElement Vertex[],int NumberVertex,int NumberEdge,int edges[][2],float edgeWeight[]) // Initialize all vertices and add all edges and weights to graph Vertex[]
{
	for(int q1=0;q1<NumberVertex;q1++)
	{
		Vertex[q1].degree=0;     // Initialize the degree of each vertex as 0
		Vertex[q1].UnionID = q1;
	}

	// Add each of the edges to graph
	// Add the weights to graph
	for (int i = 0; i < NumberEdge; i++)
	{
		Vertex[edges[i][0]].adjacent[Vertex[edges[i][0]].degree] = edges[i][1];
		Vertex[edges[i][0]].edgeWeights[Vertex[edges[i][0]].degree] = edgeWeight[i];
		Vertex[edges[i][0]].degree++;

		Vertex[edges[i][1]].adjacent[Vertex[edges[i][1]].degree] = edges[i][0];
		Vertex[edges[i][1]].edgeWeights[Vertex[edges[i][1]].degree] = edgeWeight[i];
		Vertex[edges[i][1]].degree++;
		
	}






}
bool UnionIsDiff(int tab[][2],int size,int indx1,int indx2) {
	if (tab[indx1][1] != tab[indx2][1]) {
		return true;
	}
	else {
		return false;
	}
}

void Unionfind(int tab[][2], int changingValue,int oldValue) {
	for  (int i= 0; i < 12; i++)
	{
		if (tab[i][1] == oldValue) {
			tab[i][1] = changingValue;
		}
	}
}

void Kruskal(int edges[][2], float weights[], int numberConnections)  // Generate MST by Kruskal algorithm
{                                            
	//output the MST as in slide 20
	int tab[12][2];
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			tab[i][j] = i;
		}
	}

	QuickSort(weights, edges, 0, numberConnections - 1);
	for (int i = 0; i < numberConnections; i++)
	{
		cout << edges[i][0] << " : " << edges[i][1] << " -> " << weights[i] << endl;
	}

	cout << endl;
	cout << endl;


	for (int i = 0; i < numberConnections; i++)
	{
		if (UnionIsDiff(tab,12,edges[i][0],edges[i][1])) {//if they re not both in the table
			Unionfind(tab, tab[edges[i][1]][1], tab[edges[i][0]][1]);
			cout << edges[i][0] << " : " << edges[i][1] << " -> " << weights[i] << endl;
		}
	}
	cout << endl;
	cout << endl;
}

void Prime(GraphElement Vertex[], int NumberVertex)  // Generate MST by Prime algorithm
{                                            
	//output the MST as in slide 20

	//for each vertex find the minimum path
	//if doesnt make a cycle then add
	//UnionID connected with who
	//check if both you want to connected have unionID null
	int indexmin;
	for (int i = 0; i < NumberVertex; i++)
	{
		bool changed = false;

		//Vertex[i].edgeWeights[0]; // minimum = first adjacent vertex
		indexmin = 0;
		//Vertex[i].UnionID = Vertex[Vertex[i].adjacent[0]].UnionID; //update UnionID
		for (int j = 0; j < Vertex[i].degree; j++)//try to find better/smaller weight
		{
			if (Vertex[i].edgeWeights[indexmin] > Vertex[i].edgeWeights[j] && Vertex[Vertex[i].adjacent[j]].UnionID != Vertex[i].UnionID) {//and add if unionID isnt the same
				indexmin = j;
				Vertex[i].UnionID = Vertex[Vertex[i].adjacent[j]].UnionID;
				changed = true;
				//print here
				cout << i << " : " << Vertex[i].adjacent[j] << " -> " << Vertex[i].edgeWeights[j] << endl;
			}
		}
		if (changed == false && Vertex[Vertex[i].adjacent[0]].UnionID != Vertex[i].UnionID) {//if min was the first value
			Vertex[i].UnionID = Vertex[Vertex[i].adjacent[0]].UnionID;
			//print here
			cout << i << " : " << Vertex[i].adjacent[0] << " -> " << Vertex[i].edgeWeights[0] << endl;
		}

	}
}


void QuickSort(float Items[], int edges[][2], int low, int high)
{
	if (high <= low) return;
	//One time partition
	int pivot = partition(Items,edges, low, high);
	//pivot is placed at the good position so we dont send it in recursive
   //QuickSort the left subarray
	QuickSort(Items,edges, low, pivot - 1);
	//QuickSort the right subarray
	QuickSort(Items,edges, pivot + 1, high);
}


int partition(float Items[], int edges[][2], int low, int high)// use Items[low] as the pivot to perform one time partition
{
	int i = low + 1, j = high;
	float dummy;  // dummy is used to swap two entries
	int tmp1;
	int tmp2;
	//i = index from left to right, start from beginning, search for the next bigger values than pivot
	//j = index from right to left, start from the end, search for the next smaller value than pivot
	// pivot = first value , thats why i = low+1 (could also be with the last value but not in this example)
	//as long as i<j, i and j haven't met up then continue searching (check before exchange)
	// exchange [i] and [j] once they re found
	//if i == high than finished searching
	// if j == low than finished searching
	// since pivot is the first value at the END we need to exchange it with the the smaller value which is given by j


	while (true) {
		//search for i
		while (Items[i] <= Items[low]) {
			i++;
			if (i == high) {
				break;
			}
		}
		//search for j
		while (Items[j] > Items[low]) {
			j--;
			if (j == low) {
				break;
			}
		}

		if (i >= j) {
			break;
		}
		dummy = Items[i];
		Items[i] = Items[j];
		Items[j] = dummy;

		tmp1 = edges[i][0];
		tmp2 = edges[i][1];
		edges[i][0] = edges[j][0];
		edges[i][1] = edges[j][1];
		edges[j][0] = tmp1;
		edges[j][1] = tmp2;
	}

	dummy = Items[j];
	Items[j] = Items[low];
	Items[low] = dummy;

	tmp1 = edges[low][0];
	tmp2 = edges[low][1];
	edges[low][0] = edges[j][0];
	edges[low][1] = edges[j][1];
	edges[j][0] = tmp1;
	edges[j][1] = tmp2;

	//j = pivot, pivot is well placed, separtor for left and right array
	return j;
}*/