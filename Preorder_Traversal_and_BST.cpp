// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int index = 0;

    void canRepresentBSTUtil(int nums[], int n, int maxValue, int minValue) {
        if (index >= n || nums[index] >= maxValue || nums[index] <= minValue) return;

        int value = nums[index];

        ++index;

        // Left part
        canRepresentBSTUtil(nums, n, value, minValue);

        // Right part
        canRepresentBSTUtil(nums, n, maxValue, value);
    }

public:
    int canRepresentBST(int nums[], int n) {
        // code here
        canRepresentBSTUtil(nums, n, INT_MAX, INT_MIN);

        return index >= n;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int* arr = new int[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends