#include <stdio.h>

/*
int BinarySearch(float Array[],int NumerElements, float searchNumber);
int BinarySearchCounts(float Array[],int NumerElements, float searchNumber); 

int main()
{
	float Array[30]={1.5,1.5,3,4,5,5,6,6,6,6,6,6.6,8,8.1,10.3,10.3,10.3,10.3,20,23,34,41,43,46,46,67,70,74.3,78.5,100};
	float searchNumber;
	int   flag;
	printf("Input the number you want to search:");
	scanf_s("%f",&searchNumber);

	flag=BinarySearch(Array,30,searchNumber);

	if(flag==1)
	{
		printf("%f is in the array.\n",searchNumber);
	}
	else
	{
		printf("%f is not in the array.\n",searchNumber);
	}

	getchar();
    printf("");
	flag=BinarySearchCounts(Array,30,searchNumber);
	printf("%f occurs in the array %d times.",searchNumber,flag);

	getchar();
	return 0;
}

//
// Binary Search
// Searchs if a given number is in a given array
// @param Array of numbers, size of array, searched Number
// @return 1 if in array, 0 if not
//
int BinarySearch(float Array[],int NumerElements, float searchNumber)
{
	int start=0,end=NumerElements-1;
	int middle;
	int flag=0;     //flag is used to record whether the number is found
	middle = (int) NumerElements / 2; // set middle variable to middle value of array
	int counter = 0; //debug variable (counts iterations)
	bool pente = NULL;// false = going down, true = going up

	// continue looping until we ve reached an extremity or break or return
	while (middle != start-1 && middle != end+1) {
		if (Array[middle] > searchNumber) { //the number we are looking for is lower
			middle--; //going 1 down for next iteration
			if (pente == true) { //the number is not in the array
				return flag;
			}
			if (counter == 0 && pente == NULL) { // sets the inclination
				pente = false;
			}
			counter++; //add iteration
		}
		else if (Array[middle] < searchNumber) { // same principal but higher
			middle++;
			if (pente == false) {
				return flag;
			}
			if (counter == 0 && pente == NULL) {
				pente = true;
			}
			counter++;
		}
		else { // number found
			flag = 1;
			break;
		}
		if (counter == (NumerElements / 2)+1) { // debug against infinite loop
			break;
		}
	}

	return flag;
}


//
// Binary Search Counts
// Searchs if a given number is in a given array, then gives the number of times it is in that array
// @param Array of numbers, size of array, searched Number
// @return the number of occurance of the searched number in the array
//
int BinarySearchCounts(float Array[],int NumerElements, float searchNumber) 
{
	int start=0,end=NumerElements-1;
	int middle = (int)NumerElements / 2;
	int count=0;              //count is the frequency of the searched number
	int counter = 0;	//prevents to many iterations (debug variable)
	bool pente = false; // false = going down, true = going up
	

	while (middle != start - 1 && middle != end + 1) {
		if (Array[middle] > searchNumber) { //number not found and lower so going down
			middle--;
			counter++;
			pente = false;
		}
		else if (Array[middle] < searchNumber) { // going up
			middle++;
			counter++;
			pente = true;
		}
		else {//number is found
			if(counter==0){ //if we find the number we are looking for the first sets middle to the highest one
				int cpt = 1;
				while (Array[middle] == Array[middle + cpt]) {
					cpt++;
				}
				pente = false;
				middle = middle + cpt -1;
			}
			
			count++; // found number once
			if (pente == false) { //highest occurance then looking down and counting
				int cpt = -1;
				while (Array[middle] == Array[middle + cpt]) {
					count++;
					cpt--;
				}
			}
			else { // same but lowest
				int cpt = 1;
				while (Array[middle] == Array[middle + cpt]) {
					count++;
					cpt++;
				}
			}
			
			break;
			
		}

		if (counter == NumerElements + 1) { // debug infinte loop
			break;
		}
	}



	return count;
}

*/