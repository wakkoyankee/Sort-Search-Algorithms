#include <stdio.h>
/*
void exch(float Items[],int a, int b); //exchange values in Items[a] and Items[b]
void swim(float Items[],int a); // swim up an inserted item
void insert(float Items[],int& numberItems,float x); // insert x into the binary heap Items[]
void sink(float Items[],int numberItems,int a); //sink Items[a] to make the heap order restored
float DelMax(float Items[],int& numberItems);  //delete the max from Items[], sink Items[1] to make the heap order restored
void HeapSort(float Items[],int numberItems);  //Sorting the number sequence by HeapSort algorithm
void main()
{
	int numberItems=15;

	float Items[20] = { 8888,3,5.6,20,11,6.8,3,7,8.8,10,5,4.7,4.7,6,18.8,8.5};
	
	printf("The original number sequence is:\n");
	for(int q1=1;q1<numberItems+1;q1++)
	{
		printf("%6.1f",Items[q1]);
	}

	insert(Items,numberItems,13.1);	

	printf("\n");
	for(int q1=1;q1<numberItems+1;q1++)
	{
		printf("%6.1f",Items[q1]);
	}
	insert(Items,numberItems,10.1);

	printf("\nThe number sequence after adding two numbers:\n");	
	for(int q1=1;q1<numberItems+1;q1++)
	{
		printf("%6.1f",Items[q1]);
	}
	printf("\n");
	getchar();

	DelMax(Items,numberItems);

	printf("\nThe number sequence after deleting the max number:\n");	
	for(int q1=1;q1<numberItems+1;q1++)
	{
		printf("%6.1f",Items[q1]);
	}
	getchar();	

	HeapSort(Items,numberItems);

	printf("\nThe number sequence after sorting:\n");	
	for(int q1=1;q1<numberItems+1;q1++)
	{
		printf("%6.1f",Items[q1]);
	}
	getchar();	
	getchar();
}


void exch(float Items[],int a, int b) //exchange values in Items[a] and Items[b]
{
	float tmp;
	tmp = Items[b];
	Items[b] = Items[a];
	Items[a] = tmp;
}

void swim(float Items[],int a) // swim up an inserted item
{
	// set "a" is the index of the addded item
	while (a>1 && Items[a] > Items[a / 2]) {
		exch(Items, a, a / 2);
		a = a / 2;
	}
}

void insert(float Items[],int& numberItems,float x) // insert x into the binary heap Items[]
{
	if (numberItems < 20) {
		numberItems++;
		Items[numberItems] = x;
		swim(Items, numberItems);
	}
}

void sink(float Items[],int numberItems,int a) //sink Items[a] to make the heap order restored
{

	while (a*2 <= numberItems) {
		if (Items[a] < Items[a * 2] && Items[a] < Items[a * 2 + 1]) {
			if (Items[a * 2] < Items[a * 2 + 1]) {
				exch(Items, a, a * 2+1);
				a = a * 2+1;
			}
			else {
				exch(Items, a, a * 2);
				a = a * 2;
			}
		}
		else if (Items[a] < Items[a * 2]) {
			exch(Items, a, a * 2);
			a = a * 2;
		}
		else if (Items[a] < Items[a * 2 + 1]) {
			exch(Items, a, a * 2 + 1);
			a = a * 2 + 1;
		}
		else {
			break;
		}
	}
}

float DelMax(float Items[],int& numberItems)  //delete the max from Items[], sink Items[1] to make the heap order restored
{
	exch(Items, 1, numberItems);
	numberItems--;
	sink(Items, numberItems, 1);
	float max = Items[numberItems + 1];
	Items[numberItems + 1]=NULL;
	return max;
}

void HeapSort(float Items[],int numberItems)  //Sorting the number sequence by HeapSort algorithm
{
	//heap construct : sink every parent
	for (int i = numberItems/2; i > 0; i--)
	{
		sink(Items, numberItems, i);
	}
	printf("\n After heap construct:\n");
	for (int q1 = 1; q1 < numberItems + 1; q1++)
	{
		printf("%6.1f", Items[q1]);
	}

	//Del max to sort
	while (numberItems != 0) {
		exch(Items, 1, numberItems);
		numberItems--;
		sink(Items, numberItems, 1);
	}
}*/