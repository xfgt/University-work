#include "../AlgorithmsDir/algorithms.h"
static int cnt{};
void merge(int* a, int li, int di) {
    int C[di];

    int mid = (li+di) / 2;
    int Abeg = li;
    int Bbeg = mid+1;

    int cpl = li;

    int k = mid+1; int m = di;
    while(Abeg < k && Bbeg < m+1){
        if(a[Abeg] < a[Bbeg])
          C[cpl++] = a[Abeg++];
        else
          C[cpl++] = a[Bbeg++];
    }
    //printarr(C, cpl);
    //printf("Slivam v C\n");
    for(int i = Abeg; i < k; i++)       C[cpl++] = a[i];
    for(int i = Bbeg; i <= di; i++)     C[cpl++] = a[i];
    //printarr(C, cpl);
    //printf("Prehvurlyam v A\n");
    for(int i = li; i <= di; i++)       a[i] = C[i];
    //printarr(a, di);
}


void mergeSort(int* A, int li, int di) {
    cnt++;
    if(li < di) {
        // base case
        int mid = (li+di) / 2;
       // printf("Potuvam nalyavo\tgranici:(%i, %i)\n", li, mid);
        mergeSort(A, li, mid ); // li

       // printf("Potuvam nadyasno\tgranici:(%i, %i)\n", mid+1-binary-insertion, di);
        mergeSort(A, mid+1, di); // di

        merge(A, li, di);
       // printf("Slyah gi i sa v indeksi\t(%i, %i)\n", li, di);
        std::cout << cnt << std::endl;

    } else {
        //printf("\t---===-DUNO!-===---\t\n");
    }
}

