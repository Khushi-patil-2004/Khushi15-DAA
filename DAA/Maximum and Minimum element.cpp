#include <iostream>
using namespace std;

void findMinMax(int arr[], int low, int high, int &minVal, int &maxVal) {
    if (low == high) {
        minVal = maxVal = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            minVal = arr[low];
            maxVal = arr[high];
        } else {
            minVal = arr[high];
            maxVal = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;

    int leftMin, leftMax, rightMin, rightMax;

    findMinMax(arr, low, mid, leftMin, leftMax);
    findMinMax(arr, mid + 1, high, rightMin, rightMax);
     // Combine results
    minVal = (leftMin < rightMin) ? leftMin : rightMin;
    maxVal = (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minVal, maxVal;

    findMinMax(arr, 0, n - 1, minVal, maxVal);

    cout << "Minimum element: " << minVal << endl;
    cout << "Maximum element: " << maxVal << endl;

    return 0;
}
