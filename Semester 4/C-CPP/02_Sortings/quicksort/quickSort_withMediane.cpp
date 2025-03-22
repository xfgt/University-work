#include <iostream>
#include <string.h>

using namespace std;

int partition(int array[], int left, int right)
{
    int pivot = array[left]; // определя оста

    while (left <= right) {
        //търси елемент, който е по-голям от оста
        while (array[left] < pivot)
            left++;

        //търси елемент, който е по-малък от оста
        while (array[right] > pivot)
            right--;

        // разменя елементите
        if (left <= right) {
            int tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;

            left++; //увеличава левия индекс
            right--; //намаля десния индекс
        }
    }
    return left;
}

void QuickSort(int array[], int start, int end)
{
    // Разделя входната последователност на лява и дясна част
    // idx - показва до къде е обработена входната последователност
    int idx = partition(array, start, end);

    // Рекурсивно извикване за лявата част
    if (start < idx - 1)
        QuickSort(array, start, idx - 1);

    // Рекурсивно извикване за дясната част
    if (end > idx)
        QuickSort(array, idx, end);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << (i+1) << ": ";
        cin >> arr[i];
    }

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;

    if (n % 2 != 0)
        cout << "The median is: " << arr[n/2] << endl;
    else
    {
        int tmp1 = arr[n/2];
        int tmp2 = arr[n/2-1];
        cout << "The median is: " << ((double)(tmp1 + tmp2)/2) << endl;
    }

    return 0;
}
