#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
/*
using namespace std;

struct record{
	string name;     //key in node
	int    score;    // value in node
	int    index_Left;  //reference to the left
	int    index_Right; //reference to the right
};


void NewNode(record BST[], int& NumNodes, string key, int value);
void put(record BST[], int& NumNodes, int position, string key, int value); // Insert a new record (with key and value) under BST[NumNodes]
int  get(record BST[], string name);
int getFloor(record BST[],string name);
int getFloor(record BST[], int pos,string name);

void main()
{
	int numberItems=8;
	record RawData[20],BST[20];
	int scoreLucy,scoreLuck;

	RawData[0].name="Mike",RawData[0].score=85;
	RawData[1].name="Tom",RawData[1].score=75;	
	RawData[2].name="Jack",RawData[2].score=80;
	RawData[3].name="Li",RawData[3].score=95;	
	RawData[4].name="John",RawData[4].score=66;
	RawData[5].name="Lucy",RawData[5].score=82;
	RawData[6].name="Liu",RawData[6].score=91;	
	RawData[7].name="Adam",RawData[7].score=63;

	
	printf("The raw data is:\n");
	for(int q1=0;q1<numberItems;q1++)
	{
		printf("%8s  %3d\n",RawData[q1].name.c_str(),RawData[q1].score);
	}
	getchar();

	// Initialize the first(root) node of BST
	int numberItemsBST=0;
	NewNode(BST,numberItemsBST,RawData[0].name,RawData[0].score);

	for(int q1=0;q1<numberItemsBST;q1++)
	{
		printf("%8s  %3d    %3d %3d\n",BST[q1].name.c_str(),BST[q1].score,BST[q1].index_Left,BST[q1].index_Right);
	}

	//Insert the remaining nodes into BST
	for(int q1=1;q1<numberItems;q1++)
	{	
		put(BST,numberItemsBST,0,RawData[q1].name,RawData[q1].score);
	}

	printf("    Key   Value  Index-L Index-R\n");
	for(int q1=0;q1<numberItemsBST;q1++)
	{
		printf("%8s  %3d     %3d     %3d\n",BST[q1].name.c_str(),BST[q1].score,BST[q1].index_Left,BST[q1].index_Right);
	}
	getchar();		

	scoreLucy=get(BST,"Lucy");
	scoreLuck=get(BST,"Luck");

	if(scoreLucy!=-88)
	{
		printf("The score of Lucy is %3d.\n",scoreLucy);
	}
	else
	{
		printf("Lucy is not in our records.\n",scoreLucy);
	}

	if(scoreLuck!=-88)
	{
		printf("The score of Luck is %3d.\n",scoreLuck);
	}
	else
	{
		printf("Luck is not in our records.\n",scoreLuck);
	}
	string name = "Jame";
	int tmp = getFloor(BST, name);
	cout<<"Floor of: "<< name<<" is "<<BST[tmp].name<<endl;
	getchar();	
}

void NewNode(record BST[], int& NumNodes, string key, int value) // create a new record (with key and value) at BST[NumNodes]
{
	BST[NumNodes].name=key;
	BST[NumNodes].score=value;
	BST[NumNodes].index_Left=-88;
	BST[NumNodes].index_Right=-88;
	NumNodes++;
}

void put(record BST[], int& NumNodes, int position, string key, int value) // Insert a new record (with key and value) under BST[NumNodes]
{

	if (BST[position].name < key) {//go to right
		if (BST[position].index_Right == -88) { // position not taken
			BST[position].index_Right = NumNodes;//update parent
			NewNode(BST, NumNodes, key, value);// add node
		}
		else {
			position = BST[position].index_Right; // go to the right
			put(BST, NumNodes, position, key, value);
		}
	}
	else if (BST[position].name > key) {// go to left
		if (BST[position].index_Left == -88) { // position not taken
			BST[position].index_Left = NumNodes;//update parent
			NewNode(BST, NumNodes, key, value);// add node
		}
		else {
			position = BST[position].index_Left; // go to the left
			put(BST, NumNodes, position, key, value);
		}
	}
}

int  get(record BST[], string name)
{
	int start=0;


	while (start != -88) {
		if (BST[start].name == name) {
			return BST[start].score;
		}
		else if (BST[start].name < name) {//search to the right
			start = BST[start].index_Right;
		}
		else { //search to the left
			start = BST[start].index_Left;
		}
	}

	return -88;
}


int getFloor(record BST[], string name) {
	return getFloor(BST,0,name);
}

int getFloor(record BST[],int pos,string name) {
	//keep searching on the left until its needs to go to the right
	//take the last node as floor where you need to go on the right and the value is not null

	if (pos == -88) {
		return pos;
	}
	if (BST[pos].name == name) { //found itself so its floor
		return pos;
	}
	else if(BST[pos].name>name){
		pos = BST[pos].index_Left;
		return getFloor(BST, pos, name);
	}
	else {
		int tmp = getFloor(BST, BST[pos].index_Right, name);
		if (tmp == -88) {
			return pos;
		}
		else {
			return tmp;
		}
	}

}*/