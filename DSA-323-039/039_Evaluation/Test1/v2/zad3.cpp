#include <iostream>

using namespace std;

struct CharFreq {
    char ch;
    int freq;
};

void countFrequency(const char* str, int freq[26], int& length) {
    for (length = 0; str[length] != '\0'; ++length)
        freq[str[length] - 'a']++;
}

void heapify(CharFreq heap[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].freq > heap[largest].freq)
        largest = left;

    if (right < size && heap[right].freq > heap[largest].freq)
        largest = right;

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify(heap, size, largest);
    }
}

void buildMaxHeap(CharFreq heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(heap, size, i);
}

CharFreq extractMax(CharFreq heap[], int& size) {
    CharFreq maxElement = heap[0];
    heap[0] = heap[size - 1];
    --size;
    heapify(heap, size, 0);
    return maxElement;
}

void insertHeap(CharFreq heap[], int& size, CharFreq element) {
    heap[size] = element;
    int i = size;
    ++size;
    while (i > 0 && heap[(i - 1) / 2].freq < heap[i].freq) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool rearrangeString(const char* str, char* result) {
    int freq[26] = {0}, length = 0;
    countFrequency(str, freq, length);

    CharFreq heap[26];
    int heapSize = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            if (freq[i] > (length + 1) / 2) return false;
            heap[heapSize++] = {char(i + 'a'), freq[i]};
        }
    }

    buildMaxHeap(heap, heapSize);

    int index = 0;
    CharFreq prev = {'#', 0};

    while (heapSize > 0) {
        CharFreq current = extractMax(heap, heapSize);
        result[index++] = current.ch;

        if (prev.freq > 0)
            insertHeap(heap, heapSize, prev);

        --current.freq;
        prev = current;
    }
    result[index] = '\0';
    return true;
}

int main() {
    char input[100], output[100];
    cin >> input;
    if (rearrangeString(input, output))
        cout << output << endl;
    else
        cout << "Not Possible" << endl;
    return 0;
}