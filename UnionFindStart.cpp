#include <stdio.h>
/*
int Id[100];
int numberObjects=12;

void main()
{
	int numberConnections=8;
	int connections[8][2]={{1,5},{1,7},{2,6},{3,6},{5,7},{7,9},{8,11},{11,12}};

	//Initialize unionFind data structure, each element forms a single union
	//write code

	for (int i = 0; i < numberObjects; i++)
	{
		Id[i] = i;
	}

	
	//For each of the connection, connects two unions into one
	//write code

	for (int i = 0; i < numberConnections; i++)
	{
		int pid = Id[connections[i][0]-1];
		int qid = Id[connections[i][1]-1];
		for (int j = 0; j < numberObjects; j++)
		{
			if (Id[j] == pid) {
				Id[j] = qid;
			}
		}
	}




	for(int q1=0;q1<numberObjects;q1++)
	{
		printf("the %d-th element belongs to %d-th union\n",q1+1,Id[q1]+1);
	}

	getchar();
}
*/