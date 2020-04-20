#include <stdio.h>
/*
int Id[100];
int numberObjects=12;

void main()
{
	int numberConnections=8;
	int connections[8][2]={{1,5},{1,7},{2,6},{3,6},{5,7},{7,9},{8,11},{11,12}};

	//Initialize unionFind data structure, each element forms a single union
	for(int q1=0;q1<numberObjects;q1++)
	{
		Id[q1]=q1;
	}
	
	//For each of the connection, connects two unions into one
	for(int q2=0;q2<numberConnections;q2++)
	{
		int tempElement=connections[q2][0]-1;
		int tempElement2 = connections[q2][1] - 1;
		//write code
		
		//find root of first 
		while (tempElement != Id[tempElement]) {
			tempElement = Id[tempElement];
		}


		//find root of second
		while (tempElement2 != Id[tempElement2]) {
			tempElement2 = Id[tempElement2];
		}

		//root of  first point to root of second
		Id[tempElement] = tempElement2;






	}

	for(int q1=0;q1<numberObjects;q1++)
	{
		printf("the %d-th element belongs to %d-th union\n",q1+1,Id[q1]+1);
	}

	getchar();
}
*/