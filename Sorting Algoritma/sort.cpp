#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    
#include <chrono>   

using namespace std;

vector<int> generateRandomNumbers(int N) {
    vector<int> numbers(N);
    srand(time(0));  

    for(int i = 0; i < N; ++i) {
        numbers[i] = rand() % 100;  
    }

    return numbers;
}

vector<int> generateOrderedNumbers(int N) {
    vector<int> numbers(N);

    for(int i = 0; i < N; ++i) {
        numbers[i] = i + 1;  
    }

    return numbers;
}

vector<int> generateReverseOrderedNumbers(int N) {
    vector<int> numbers(N);

    for(int i = 0; i < N; ++i) {
        numbers[i] = N - i;  
    }

    return numbers;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

template <typename Func>
void measureTime(Func sortFunction, vector<int> arr, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(arr);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << sortName << " membutuhkan " << duration << " mikrodetik." << endl;
}

int main() {
    vector<int> sizes = {10, 100, 500, 1000, 10000};

    for (int N : sizes) {
        cout << "N = " << N << endl;

        vector<int> randomNumbers = generateRandomNumbers(N);
        vector<int> orderedNumbers = generateOrderedNumbers(N);
        vector<int> reverseOrderedNumbers = generateReverseOrderedNumbers(N);

        cout << "Bilangan acak:" << endl;
        measureTime(bubbleSort, randomNumbers, "Bubble Sort");
        measureTime(insertionSort, randomNumbers, "Insertion Sort");
        measureTime(selectionSort, randomNumbers, "Selection Sort");
        measureTime([](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }, randomNumbers, "Merge Sort");
        measureTime([](vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, randomNumbers, "Quick Sort");

        cout << "Bilangan terurut:" << endl;
        measureTime(bubbleSort, orderedNumbers, "Bubble Sort");
        measureTime(insertionSort, orderedNumbers, "Insertion Sort");
        measureTime(selectionSort, orderedNumbers, "Selection Sort");
        measureTime([](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }, orderedNumbers, "Merge Sort");
        measureTime([](vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, orderedNumbers, "Quick Sort");

        cout << "Bilangan terurut terbalik:" << endl;
        measureTime(bubbleSort, reverseOrderedNumbers, "Bubble Sort");
        measureTime(insertionSort, reverseOrderedNumbers, "Insertion Sort");
        measureTime(selectionSort, reverseOrderedNumbers, "Selection Sort");
        measureTime([](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }, reverseOrderedNumbers, "Merge Sort");
        measureTime([](vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, reverseOrderedNumbers, "Quick Sort");

        cout << endl;
    }

    return 0;
}
