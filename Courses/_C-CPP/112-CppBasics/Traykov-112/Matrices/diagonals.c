//
// Created by MRSLAVE on 04-Feb-25.
//


#include <stdio.h>
#include "dynamics.h"



void getPrincipalDiag(int* A, int ar, int ac) {
    printf("Principal (main) diagonal:\n");
    for(int i = 0; i < ar; i++) {
        for(int j = 0; j < ac; j++) {
			// A[i][i]
			if(i == j)
            	printf("%d ", *((A + i * ac) + j));
        }
    }

    printf("\n");
}

void getSecondaryDiag(int* A, int ar, int ac) {
    printf("Secondary diagonal:\n");
    for(int i = 0; i < ar; i++) {
        for(int j = 0; j < ac; j++) {
			
			if((i+j) == (ac-1))
            	printf("%d ", *((A + i * ac) + j));
			
        }
    }

    printf("\n");

}
