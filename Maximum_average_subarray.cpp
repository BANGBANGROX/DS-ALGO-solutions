// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMaxAverage(int arr[], int n, int k) {
        // code here
        int maxSum = INT_MIN;
        int currentSum = 0;
        int start = -1;
        int l = 0;
        int r = k - 1;

        for (int i = 0; i < k; ++i) {
            currentSum += arr[i];
        }

        while (r < n) {
            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = l;
            }
            currentSum -= arr[l];
            ++l;
            ++r;
            if (r < n) currentSum += arr[r];
        }

        return start;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends