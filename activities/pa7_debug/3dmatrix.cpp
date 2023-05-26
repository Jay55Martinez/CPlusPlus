// Program to read 3-dimensional matrix and display the elements as 1xSIZE^3 matrix
// TODO
// initize matrix using update_3d method (see comments below)
// display method must not be able to modify array elements (update the code as needed)
// display method must use a single loop/iterator to print the entire array with addresses
// display cannot use nested loops
/*
List of Bugs:
loop does not initialize
const function not defined for a function that should not change the values
print did not work
*/
//

#include <iostream>
#include <random>
#define SIZE 7
using namespace std;

void update_3d(double Matrix_3d[][SIZE][SIZE], int size);
const void display_1d(double Matrix_3d[][SIZE][SIZE], int size);

int main(void)
{
	// prompt the user to initialize the matrix accordingly
	double Matrix_3d[SIZE][SIZE][SIZE] = {};
	// initialize the array to non-zero values (use scanf or random numbers generator)
	update_3d(Matrix_3d, SIZE);
	// display the values
	display_1d(Matrix_3d, SIZE);

	return 0;
}

void update_3d(double matrix[][SIZE][SIZE], int size)
{
	cout << "Entering SIZE^3 elements of the matrix:" << endl;
	for (int i=0; i < size; i++)
	{
		for (int j=0; j < size; j++)
		{
			for (int k=0; k < size; k++)
			{
				int r = rand() % 10 + 1; // random num btw 1 and 10
				matrix[i][j][k] = r;
			}
		}
	}
}

// update as needed. 1 'for' loop only with 1 iterator to print all values with addresses
// must not be able to update the array.
// Share any observations.
const void display_1d(double matrix[][SIZE][SIZE], int size) {
	const double* matrixPtr = &matrix[0][0][0]; // starting address
    const double* endPtr = &matrix[size-1][size-1][size-1]; // ending address

    for (; matrixPtr < endPtr; matrixPtr++) {
        cout << "Address: " << matrixPtr << ", Value: " << *matrixPtr << endl;
    }
}
