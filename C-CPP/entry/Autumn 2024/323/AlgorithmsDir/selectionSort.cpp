#include "algorithms.h"
void selectionSort(int* a, int n){
	for(int i = 0; i < n-1; ++i){
        //find min
		int cmin = i;
		for(int j = i+1; j < n; ++j){
			if(a[j] < a[cmin])
				cmin = j;
		}
        	//endfindmin
		swap(a[i], a[cmin]);
	}
}
