//This program allocated memory for an NxM integer array dynamicaly 
//The program then prints the 2D array in a matrix form using a combination of * and [] operators
//Note: You can't use ** or [][] for printing the values (use a combination of * and [] only.

//Number of bugs/errors : 6
/*
List of bugs:
first malloc did not use size of int*
dereferencing bugs through out
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int N = 3, M = 5;
	int i, j; 

	// size of int* was not used
	int** d_array = (int**) malloc( N * sizeof(int*) ); 	//Allocating memory for 2D array (N rows) 

	for(i=0; i< N; i++) // not properly defined for loop
	     d_array[i] = (int*) malloc(M * sizeof(int*) );  //Allocating memory for each row with M columns)

	//Initializing 2D array using [ ][ ] notation
	printf("Initializing array values!\n");
	for(i=0; i< N; i++) {			 
	     for(j=0; j < M; j++) {
	          d_array[i][j] = i+j; //missing semicolion and dereferencing not done correctly
	     }
	}

	//Accessing 2D array using a combination of * and [] notation
	printf("\n");
	for(i=0; i< N; i++) {			 
	     for(j=0; j < M; j++) { // N should not be used use M
	          cout<<*(d_array[i]+j);
	     }
	     cout<<"\n";
	}

	//Deallocating 2D array
	for(i=0; i< N; i++)			 
		free(*(d_array+i)); //incorrectly dereferenced
	free(d_array);
}
