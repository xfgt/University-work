//
// Created by MRSLAVE on 03-Feb-25.
//

#include <stdio.h>
#include <stdlib.h>
#include "../dynamics.h"

int main() {


    /*
     *      Swap the elements from the principal diagonal with those of the k-row
     */

    //int matrix[4][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    const int matrixfirst[4][4] = {{3,5,6,9},{2,1,8,4},{6,6,-3, 5},{7,6,0,1}}; // const
    int matrix[4][4] = {{3,5,6,9},{2,1,8,4},{6,6,-3, 5},{7,6,0,1}}; // to be changed

    printMatrix((int*)matrix, 4, 4, "Before");
	
	//	scalar multiplication (by 5)
	int* S = scalar(5, (int*)matrix, 4, 4);
	printMatrix(S, 4, 4, "x5");


//	do the swap
    int k = 2; // row
    int buf = 0;
    for(int i = 0; i < 4; i++) {
        buf = matrix[i][i]; // the diagonal value

        matrix [i][i] = matrix [k][i]; // the diagonal value is changed to the value of the k-row

        matrix [k][i] = buf; // the swap procedure for the k row values
    }
    printMatrix((int*)matrix, 4, 4, "After");




//	Print diagonals (first and second)
    getPrincipalDiag((int*)matrix, 4,4);
	getSecondaryDiag((int*)matrix, 4,4);

//	Mutliplication
    int* x = multiplication(matrixfirst, matrix, 4,4,4,4);
    printMatrix((int*)x, 4,4, "Multiplication");
	
	
    free(x);
	free(S);


    return 0;
}
