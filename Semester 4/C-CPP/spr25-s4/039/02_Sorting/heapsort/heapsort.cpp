#include <iostream>


void swap(int* arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


void heapify(int* tree, int n, int i){

	if(i >= n) return;

	int l = 2*i + 1;
	int r = 2*i + 2;
	int max = i;

	if(l < n && tree[l] > tree[max]){
		max = l;
	} else {
		max = i;
	}

	
	if(r < n && tree[r] > tree[max]){
		max = r;
	}

	if(max != i){
		swap(tree, max, i);
		heapify(tree, n, max);
	}

}



int main(){
		
	int tree[] = {4, 10,3, 5, 1, 2};
	int sz = 6;

	heapify(tree, sz, 0);


	for(int i = 0; i < sz; i++){
		std::cout << tree[i] << "\n";
	}


	return 0;

}
