
#include "dynamics.h"
#include <stdlib.h>
int* transpose(int* A, int ar, int ac){

	int* X = (int*)calloc(ar * ac, sizeof(int));
	
	for(int i = 0; i < ar; i++){
		
		for(int j = 0; j < ac; j++){
			
//			X[i][j] = A[j][i]

			*((X + i * ac) + j) = *((A + j * ac) + i);

		}
	}

	

	return X;
}

