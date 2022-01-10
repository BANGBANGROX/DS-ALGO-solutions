// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
private:
    void merge(int arr[], int temp[], int l, int m, int r) {
        // Your code here
        int i = l, j = m + 1, k = l;

        while (i <= m && j <= r) {
            if (arr[i] < arr[j]) {
                temp[k] = arr[i];
                ++i;
                ++k;
            }
            else {
                temp[k] = arr[j];
                ++j;
                ++k;
            }
        }

        while (i <= m) {
            temp[k] = arr[i];
            ++i;
            ++k;
        }

        while (j <= r) {
            temp[k] = arr[j];
            ++j;
            ++k;
        }

        for (int i = l; i <= r; ++i) {
            arr[i] = temp[i];
        }
    }

    void mergeSortUtil(int arr[], int temp[], int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;

        mergeSortUtil(arr, temp, l, mid);
        mergeSortUtil(arr, temp, mid + 1, r);

        merge(arr, temp, l, mid, r);
    }

public:
    void mergeSort(int arr[], int l, int r) {
        //code here
        int* temp = new int[r + 1];

        mergeSortUtil(arr, temp, 0, r);
    }
};

// { Driver Code Starts.


int main()
{
    int n, T, i;

    scanf_s("%d", &T);

    while (T--) {

        scanf_s("%d", &n);
        int* arr = new int[n + 1];
        for (i = 0; i < n; i++)
            scanf_s("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends