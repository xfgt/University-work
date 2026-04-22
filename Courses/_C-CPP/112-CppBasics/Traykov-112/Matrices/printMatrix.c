//
// Created by MRSLAVE on 03-Feb-25.
//

#include <stdio.h>
#include "dynamics.h"

void printMatrix(int* matrix, int rows, int columns, const char* name) {
    printf("%s:\n", name);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++)
            printf("%d\t",
                *((matrix + i * columns) + j) // important
            );

        printf("\n");
    }
}