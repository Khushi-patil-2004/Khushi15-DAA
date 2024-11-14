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

    void quicksort(int arr[], int low, int high) {
        if (low < high) {
            int p = partition(arr, low, high);
            quicksort(arr, low, p - 1);
            quicksort(arr, p + 1, high);
        }
    }

private:
   int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    
    int s = low;             
    int e = high - 1;      

    while (s <= e) {
        while (s <= e && arr[s] <= pivot) {
            s++;
        }
        while (s <= e && arr[e] > pivot) {
            e--;
        }
        if (s < e) {
            swap(arr[s], arr[e]);
        }
    }
    swap(arr[s], arr[high]);  
    return s;                 
}

};

int main() {
    quick q;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << "Original array: ";
    q.printarray(A, n);
    q.quicksort(A, 0, n - 1);
    cout << "Sorted array: ";
    q.printarray(A, n);
    return 0;
}

