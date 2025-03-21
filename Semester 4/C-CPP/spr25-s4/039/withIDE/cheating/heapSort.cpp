#if 0

#include <iostream>


void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


void heapify(int* tree, int n, int i) {

	if (i >= n) return;

	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max = i;

	if (l < n && tree[l] > tree[max]) {
		max = l;
	}
	else {
		max = i;
	}


	if (r < n && tree[r] > tree[max]) {
		max = r;
	}

	if (max != i) {
		swap(tree, max, i);
		heapify(tree, n, max);
	}

}


void build_heap(int* tree, int n) {
	int last_node = n - 1;
	int parent = (last_node - 1) / 2;
	for (int i = parent; i >= 0; i--) {
		heapify(tree, n, i);
	}
}

void heap_sort(int* tree, int n) {
	build_heap(tree, n);
	for (int i = n - 1; i >= 0; i--) {
		swap(tree, i, 0);
		heapify(tree, i, 0);
	}
}


int main() {

	//int tree[] = { 4, 10,3, 5, 1, 2 }; // before build heap check
	int tree[] = { 2, 5, 3, 1, 10, 4 };
	int n = 6;

	//heapify(tree, sz, 0);
	//build_heap(tree, n);
	heap_sort(tree, n);


	for (int i = 0; i < n; i++) {
		std::cout << tree[i] << ' ';
	}


	return 0;

}

#endif