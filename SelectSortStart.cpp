#include <stdio.h>

/*
void main()
{
	int numberItems=20;
	float Items[20]={3,5.6,20,11,6.8,3,7,8.8,10,5,4.7,4.7,6,188,8.5,4.7,13,20,7.1,18};
	float tmp;
	printf("The unsorted number sequence is:\n");
	for(int q1=0;q1<numberItems;q1++)
	{
		printf("%6.1f",Items[q1]);
	}

	for(int q1=0;q1<numberItems;q1++)
	{
		int min=q1;

		//find the index of the minum element among the subarray from Items[q1] to Items[numberItems-1]
		for (int j = q1+1; j < numberItems; j++)
		{
			if (Items[min] > Items[j]) {
				min = j;
			}
		}
		tmp = Items[min];
		Items[min] = Items[q1];
		Items[q1] = tmp;
 
	}
	
	printf("\nThe sorted number sequence is:\n");

	for(int q1=0;q1<numberItems;q1++)
	{
		printf("%6.1f",Items[q1]);
	}

	getchar();
}*/


