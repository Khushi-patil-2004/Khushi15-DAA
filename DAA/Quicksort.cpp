#include <iostream>
using namespace std;

class quick {
public:
    void printarray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << "|";
        }
        cout << endl;
    }

    void quicksort(int arr[], int low, int high, int pivotType) {
        if (low < high) {
            int p = partition(arr, low, high, pivotType);
            quicksort(arr, low, p - 1, pivotType);
            quicksort(arr, p, high, pivotType);
        }
    }

private:
    int partition(int arr[], int low, int high, int pivotType) {
        int pivot;
        switch (pivotType) {
            case 1: // First element as pivot
                pivot = arr[low];
                break;
            case 2: // Last element as pivot
                pivot = arr[high];
                break;
            case 3: // Middle element as pivot 
                pivot = arr[low + (high - low) / 2];
                break;
            default:
                cout << "Invalid pivot type." << endl;
                
                break;
        }

        int s = low;
        int e = high;

        while (s <= e) {
            while (arr[s] < pivot) {
                s++;
            }
            while (arr[e] > pivot) {
                e--;
            }
            if (s <= e) {
                swap(arr[s], arr[e]);
                s++;
                e--;
            }
        }
        return s;
    }
};

int main() {
    quick q;
    int n, pivotType;

    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Choose pivot type:\n1. First element\n2. Last element\n3. Middle element\n";
    cout << "Enter your choice  like 1,2,3: ";
    cin >> pivotType;

    cout << "Original array: ";
    q.printarray(A, n);
    q.quicksort(A, 0, n - 1, pivotType);
    cout << "Sorted array: ";
    q.printarray(A, n);

    return 0;
}

