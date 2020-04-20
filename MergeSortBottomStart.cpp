#include <stdio.h>
/*
void MergeSort(float Items[],float aux[],int numberItems);
void merge(float Items[],float aux[],int low, int middle,int high);

void main()
{
	int numberItems=30;
	float Items[30]={3,5.6,20,11,6.8,3,7,8.8,10,5,4.7,4.7,6,188,8.5,4.7,13,20,7.1,18,21,11,5.7,9,24,33,1.9,2.7,9.3,10};
	float aux[30];
	
	printf("The unsorted number sequence is:\n");
	for(int q1=0;q1<numberItems;q1++)
	{
		printf("%6.1f",Items[q1]);
	}


	MergeSort(Items,aux,numberItems);

	printf("\nThe sorted number sequence is:\n");

	for(int q1=0;q1<numberItems;q1++)
	{
		printf("%6.1f",Items[q1]);
	}

	getchar();
}

void MergeSort(float Items[],float aux[],int numberItems)  // simulate the code in slide 19, bottom-up merge sort
{
	for (int i = 1; i < numberItems; i=i+i)// double i each iteration
	{
		for (int lo = 0; lo < numberItems-i; lo+=i+i) //look at all the values i by i
		{
			if (lo + i + i - 1 < numberItems - 1) { //look if i dont go further than the highest index of array if not set it to high
				merge(Items, aux, lo, lo + i - 1, lo + i + i - 1); // lo = first element, high = lo+ (i by i iteration) -1 
			}
			else {// else set the high to last value
				merge(Items, aux, lo, lo + i - 1, numberItems - 1);
			}
		}
	}

}


void merge(float Items[],float aux[],int low, int middle,int high)  //copy your merge function in previous code
{
	// copy the values in Items to aux
	for (int k = low; k <= high; k++)
	{
		aux[k] = Items[k];
	}

	// Initialize the index for the two sub-arrays

	int fhi = low; //First half index
	int shi = middle + 1; //Seconf half index

	for (int k = low; k <= high; k++)
	{
		if (fhi > middle) {
			Items[k] = aux[shi++];
		}
		else if (shi > high) {
			Items[k] = aux[fhi++];
		}
		else if (aux[fhi] > aux[shi]) {
			Items[k] = aux[shi++];

		}
		else {
			Items[k] = aux[fhi++];
		}
	}

	// Merge the two sub-arrays one entry by one entry
}
*/
