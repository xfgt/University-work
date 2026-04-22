//
// Created by MRSLAVE on 02-Feb-25.
//

#include <stdio.h>
#include <stdlib.h>
#include "../dynamics.h"

int main() {

    int ar, ac, br, bc;
    printf("A[r][c] =  ");
    scanf("%d %d", &ar, &ac);

    printf("B[r][c] =  ");
    scanf("%d %d", &br, &bc);

    if(ac != br) {
        printf("Cannot complete matrix multiplication! (%d != %d)\n", ac, br);
        return -1;
    }


    int A[ar][ac];
    int B[br][bc];



    printf("Fill A:\n");
    for(int i = 0; i < ar; i++) {
        for(int j = 0; j < ac; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Fill B:\n");
    for(int i = 0; i < br; i++) {
        for(int j = 0; j < bc; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int* C = multiplication((int*) A, (int*) B, ar, ac, br, bc);







    printMatrix((int*)A, ar,ac, "A");
	int* T = transpose((int*) A, ar, ac);
	printMatrix((int*)T, ar, ac, "TransposeA");

    printMatrix((int*)B, br,bc, "B");
    printf("Making C...\n");
    printMatrix((int*)C, ar,bc, "A x B");

	getPrincipalDiag((int*)C, ac, bc);
	getSecondaryDiag((int*)C, ac, bc);


    free(C);
    free(T);

    return 0;
}

