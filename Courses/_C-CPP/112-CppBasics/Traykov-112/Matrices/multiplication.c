//
// Created by MRSLAVE on 03-Feb-25.
//


#include <stdio.h>
#include <stdlib.h>
#include "dynamics.h"


int* multiplication(int* A, int* B, int ar, int ac, int br, int bc) {
    if(ac != br) {
        printf("Cannot complete matrix multiplication! (%d != %d)\n", ac, br);
        return 0;
    }

    int* C = (int*) calloc(ar * bc , sizeof(int));
    int sum = 0;

    for(int i = 0; i < ar; i++) {
        for(int j = 0; j < bc; j++) {
            for(int k = 0; k < br; k++) {
                //sum += A[i][k] * B[k][j];
                //      sample   ->  *((matrix + i * columns) + j)

                //*((A + i * br) + k)
                //*((B + k * br) + j)
                sum += *((A + i * br) + k) * (*((B + k * br) + j));
            }
            //      sample   ->  *((matrix + i * columns) + j)
            //C[i][j] = sum;
            // *((C + i * bc) + j)
            *((C + i * bc) + j) = sum;
            sum = 0;
        }
    }

    return C;
}
