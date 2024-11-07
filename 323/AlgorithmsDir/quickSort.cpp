#include "algorithms.h"
static int cnt{};

void quickSort(int* A, int li, int di) {
    cnt++;
   //printf("\n---> lyavo: %d, dyasno: %d\n", li, di);

    if(li > di) {
       //std::cout << "\n\t==== DUNO! ====\n\n";
    } else {
        int Etalon = A[(li+di) / 2];
        //int Etalon = A[li];
        //printf("\tEtalon = %d\n", Etalon);

        int j = li;
        int k = di;

        do {
            while(A[j] < Etalon) j++;
            while(A[k] > Etalon) k--;

            if(j <= k) {
                //printf("Razmyana na %d i %d\n", A[j], A[k]);
                //printarr(A, k);
                swap(A[j], A[k]);
                j++; k--;
            }
        } while(j <= k);

        //printf("Kray na razmenite.\nPotuvane nalqvo..\n");
        quickSort(A, li, k);

        //printf("Izpluvane.\nPotuvane nadqsno.");
        quickSort(A, j, di);
        std::cout << cnt << std::endl;
    }
}


