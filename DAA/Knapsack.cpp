#include <iostream>
using namespace std;

void computeRatio(int weight[], int profit[], double ratio[], int n) {
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)profit[i] / weight[i];
    }
}

void sortItems(int weight[], int profit[], double ratio[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) { 
                
                double tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                int tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;

                int tempProfit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempProfit;
            }
        }
    }
}

int knapsack(int weight[], int profit[], double ratio[], int n, int capacity) {
    int maxProfit = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= capacity) {
            currentWeight += weight[i];
            maxProfit += profit[i];
        }
        else {
            int remainingCapacity = capacity - currentWeight;
            maxProfit += ratio[i] * remainingCapacity;
            break; 
        }
    }

    return maxProfit;
}

int main() {
    int n; 
    int capacity; 

    cout << "Enter the number of items: ";
    cin >> n;

    int weight[n], profit[n];
    double ratio[n];

    
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    computeRatio(weight, profit, ratio, n);
    
    sortItems(weight, profit, ratio, n);

    
    cout << "\nItems after sorting by profit-to-weight ratio (in descending order):\n";
    cout << "Weight\tProfit\tRatio\n";
    for (int i = 0; i < n; i++) {
        cout << weight[i] << "\t" << profit[i] << "\t" << ratio[i] << endl;
    }

    
    int maxProfit = knapsack(weight, profit, ratio, n, capacity);

    cout << "\nMaximum profit: " << maxProfit << endl;

    return 0;
}

