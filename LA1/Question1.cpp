#include <iostream>
using namespace std;

const int MAX = 100;

// Print
void printArray(int arr[], int size, const string title) {
    cout << title << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

// Create
void createArray(int arr[], int size) {
    printArray(arr, size, "Create");
}

// Insert
void insertElement(int arr[], int& size, int pos, int value) {
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
    printArray(arr, size, "Insert");
}

// Delete 
void deleteElement(int arr[], int& size, int pos) {
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printArray(arr, size, "Delete");
}

// LinearSearch
void linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << "Element " << target << " found at index: " << i << endl;
            return;
        }
    }
    cout << "Element " << target << " not found." << endl;
}

int main() {
    int arr[MAX] = {1, 1, 3, 5, 7, 5};
    int size = 6;

    createArray(arr, size);

    int insertPos = 2;
    int insertVal = 10;
    insertElement(arr, size, insertPos, insertVal);

    int deletePos = 2;
    deleteElement(arr, size, deletePos);

    int searchVal = 10;
    linearSearch(arr, size, searchVal);

    return 0;
}