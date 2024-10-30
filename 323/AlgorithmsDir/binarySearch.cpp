int binarySearch(int* a, int low, int high, int x){

  while(low <= high){

    int mid = low + (high - low) / 2;

    if(a[mid] == x) return mid;

    if(a[mid] < x) low = mid + 1;
    else high = mid - 1;

  }
    return -1;
}

