// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    void prank(long long a[], int n) {
        // code here
        int* rollToIndex = new int[n];
        int* ans = new int[n];

        for (int i = 0; i < n; ++i) {
            rollToIndex[a[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            ans[rollToIndex[i]] = a[i];
        }

        for (int i = 0; i < n; ++i) {
            a[i] = ans[i];
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long *a = new long long[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        ob.prank(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}

// } Driver Code Ends