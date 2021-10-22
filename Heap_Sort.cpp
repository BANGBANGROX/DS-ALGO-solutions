// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
public:
    //Heapify function to maintain heap property.
    void heapify(int a[], int n, int index) {
        // Your Code Here
        int left = 2 * index + 1, right = 2 * index + 2, largest = index;

        if (left < n && a[left] > a[largest]) {
            largest = left;
        }
        if (right < n && a[right] > a[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(a[largest], a[index]);
            heapify(a, n, largest);
        }

        return;
    }

public:
    //Function to build a Heap from array.
    void buildHeap(int a[], int n) {
        // Your Code Here
        int start = n / 2 - 1;

        for (int i = start; i > -1; --i) {
            heapify(a, n, i);
        }
    }

public:
    //Function to sort an array using Heap Sort.
    void heapSort(int a[], int n) {
        //code here
        buildHeap(a, n);

        for (int i = n - 1; i > 0; --i) {
            swap(a[i], a[0]);
            heapify(a, i, 0);
        }
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000], n, T, i;
    scanf_s("%d", &T);
    while (T--) {
        scanf_s("%d", &n);
        for (i = 0; i < n; i++)
            scanf_s("%d", &arr[i]);
        Solution ob;
        ob.heapSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends