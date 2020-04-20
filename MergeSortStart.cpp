#include <stdio.h>
/*
void MergeSort(float Items[],float aux[],int low, int high);
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


	MergeSort(Items,aux,0,numberItems-1);

	printf("\nThe sorted number sequence is:\n");

	for(int q1=0;q1<numberItems;q1++)
	{
		printf("%6.1f",Items[q1]);
	}

	getchar();
}

void MergeSort(float Items[],float aux[],int low, int high)// sorting the array by merge sort algorithm
{
	if (high <= low) return;

	int mid = low + (high- low) / 2;
      // calculate middle
	MergeSort(Items, aux, low, mid);
      // MergeSort left half sub-array
	MergeSort(Items, aux, mid+1, high);
      // MergeSort right half sub-array
	merge(Items, aux, low, mid, high);
      // Merge the two sorted sub-arrays
}


void merge(float Items[],float aux[],int low, int middle,int high)  // The function performs Merging the two sorted sub-arrays
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
