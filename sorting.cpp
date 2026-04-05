#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printArray(const string& msg, const vector<int>& arr) {
    cout << msg << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> arr) {
    cout << "\n--- BUBBLE SORT ---" << endl;
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        printArray("Iterasi ke-" + to_string(i + 1), arr);
        if (!swapped) break;
    }
    printArray("Hasil Akhir Bubble Sort", arr);
}

void selectionSort(vector<int> arr) {
    cout << "\n--- SELECTION SORT ---" << endl;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
        printArray("Iterasi ke-" + to_string(i + 1), arr);
    }
    printArray("Hasil Akhir Selection Sort", arr);
}

void insertionSort(vector<int> arr) {
    cout << "\n--- INSERTION SORT ---" << endl;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printArray("Iterasi ke-" + to_string(i), arr);
    }
    printArray("Hasil Akhir Insertion Sort", arr);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortRecursive(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printArray("Proses Partisi (pivot " + to_string(arr[pi]) + ")", arr);
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

void runQuickSort(vector<int> arr) {
    cout << "\n--- QUICK SORT ---" << endl;
    quickSortRecursive(arr, 0, arr.size() - 1);
    printArray("Hasil Akhir Quick Sort", arr);
}

void mergeSortRecursive(vector<int>& arr) {
    if (arr.size() > 1) {
        int mid = arr.size() / 2;
        vector<int> L(arr.begin(), arr.begin() + mid);
        vector<int> R(arr.begin() + mid, arr.end());

        mergeSortRecursive(L);
        mergeSortRecursive(R);

        int i = 0, j = 0, k = 0;
        while (i < L.size() && j < R.size()) {
            if (L[i] < R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < L.size()) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < R.size()) {
            arr[k] = R[j];
            j++;
            k++;
        }
        printArray("Proses Merge", arr);
    }
}

void runMergeSort(vector<int> arr) {
    cout << "\n--- MERGE SORT ---" << endl;
    mergeSortRecursive(arr);
    printArray("Hasil Akhir Merge Sort", arr);
}

int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    printArray("\nData awal", data);

    bubbleSort(data);
    selectionSort(data);
    insertionSort(data);
    runQuickSort(data);
    runMergeSort(data);

    return 0;
}
