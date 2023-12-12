#include<iostream>
using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to perform linear search
int linearSearch(const int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

// Function to print array elements
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int size = 5;
    int arr[size] = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    printArray(arr, size);

    // Sorting the array using bubble sort
    bubbleSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    // Searching for an element using linear search
    int key;
    cout << "\nEnter the element to search: ";
    cin >> key;

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
