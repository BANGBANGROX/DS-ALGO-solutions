// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    int find_min(int a[], int n, int k) {
        // Your code geos here
        int totalPairs = 0, optimal = 0;

        for (int i = 0; i < n; ++i) {
            totalPairs += a[i] / 2;
            if (a[i] % 2 == 0) optimal += (a[i] - 2) / 2;
            else optimal += (a[i] - 1) / 2;
        }

        int ans = totalPairs >= k ? optimal >= k ? 2 * k + n - 1 : optimal + k + n : -1;

        return ans;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int* a = new int[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        Solution obj;
        cout << obj.find_min(a, n, k) << endl;
    }
    return 1;
}
// } Driver Code Ends