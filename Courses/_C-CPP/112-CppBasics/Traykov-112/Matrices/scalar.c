
#include "dynamics.h"
#include <stdlib.h>


int* scalar(int num, int* matrix, int rows, int cols){

	int* X = (int*)calloc(rows * cols, sizeof(int));

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			// X[i][j] = num * matrix[i][j]
			*((X + i * cols) + j) = *((matrix + i * cols) + j) * num;
			//*((arr+i*n) + j))
		}
	}



	return X;

}
