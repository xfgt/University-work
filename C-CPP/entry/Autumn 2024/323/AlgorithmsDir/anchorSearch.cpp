//
// Created by Slave on / Tuesday / 05-Nov-24.
//

bool anchorSearch(int* a, int n, int x) {
    int index = 0;

    while (a[index] != x)
        index++;

    if(index < n+1)
        return true;


    return false;
}
