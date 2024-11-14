#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int x) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            return binarySearchRecursive(arr, mid + 1, high, x);
        } else {
            return binarySearchRecursive(arr, low, mid - 1, x);
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    char ch;
    do {
        int x;
        cout << "Enter the number you want to search: ";
        cin >> x;
        int n = sizeof(arr) / sizeof(arr[0]);
        int choice;
        int result;
        
        cout << "........MENU........" << endl;
        cout << "1. Iterative Binary Search" << endl;
        cout << "2. Recursive Binary Search" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                result = binarySearch(arr, 0, n - 1, x);
                break;
            case 2:
                result = binarySearchRecursive(arr, 0, n - 1, x);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }
        
        if (result == -1) {
            cout << "Element is not found." << endl;
        } else {
            cout << "Element found at index: " << result << endl;
        }
        cout << endl;
        cout << "Do you want to continue Y/N: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}

