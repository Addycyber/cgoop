#include<iostream>
using namespace std;

// Template function for selection sort
template<typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}

// Template function to print array elements
template<typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example with integers
    int intArray[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArray) / sizeof(int);
    
    cout << "Original array (integers): ";
    printArray(intArray, intSize);

    selectionSort(intArray, intSize);

    cout << "Sorted array (integers): ";
    printArray(intArray, intSize);

    // Example with doubles
    double doubleArray[] = {3.14, 2.71, 1.618, 0.0, -1.0};
    int doubleSize = sizeof(doubleArray) / sizeof(double);

    cout << "\nOriginal array (doubles): ";
    printArray(doubleArray, doubleSize);

    selectionSort(doubleArray, doubleSize);

    cout << "Sorted array (doubles): ";
    printArray(doubleArray, doubleSize);

    return 0;
}
