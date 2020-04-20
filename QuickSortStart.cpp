#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
/*
void QuickSort(float Items[],int low, int high);
int partition(float Items[],int low, int high);
void Shuffle(float Items[], int numberItems);

void main()
{
	int numberItems=30;
	float Items[30]={3,5.6,20,11,6.8,3,7,8.8,10,5,4.7,4.7,6,18.8,8.5,4.7,13,20,7.1,18,71,11,5.7,9,24,2,1.9,0.7,9.3,10};
	
	//so that rand doesn t give always the same random numbers for each exec
	srand(time(NULL));
	
	Shuffle(Items, numberItems);

	printf("The unsorted number sequence is:\n");
	for(int q1=0;q1<numberItems;q1++)
	{
		printf("%6.1f",Items[q1]);
	}


	QuickSort(Items,0,numberItems-1);

	printf("\nThe sorted number sequence is:\n");

	for(int q1=0;q1<numberItems;q1++)
	{
		printf("%6.1f",Items[q1]);
	}

	getchar();
}

void QuickSort(float Items[],int low, int high)
{
	if(high<=low) return;
           //One time partition
		int pivot = partition(Items,low,high);
			//pivot is placed at the good position so we dont send it in recursive
           //QuickSort the left subarray
		QuickSort(Items, low, pivot-1);
           //QuickSort the right subarray
		QuickSort(Items, pivot + 1, high);
}


int partition(float Items[],int low, int high)// use Items[low] as the pivot to perform one time partition
{
	int i=low+1,j=high;
	float dummy;  // dummy is used to swap two entries


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
	}
	
	dummy = Items[j];
	Items[j] = Items[low];
	Items[low] = dummy;

	//j = pivot, pivot is well placed, separtor for left and right array
	return j;
}

void Shuffle(float Items[], int numberItems) {
	float dummy;
	int r;//r for random
	for (int i = 0; i < numberItems; i++)
	{
		r = rand() % numberItems;
		dummy = Items[i];
		Items[i] = Items[r];
		Items[r] = dummy;
	}

}*/