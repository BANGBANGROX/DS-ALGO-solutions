//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int getMinDiff(int heights[], int n, int k) {
        // code here
        sort(heights, heights + n);

        int ans = heights[n - 1] - heights[0];

        for (int i = 1; i < n; ++i) {
            int maxValue = max(heights[i - 1] + k, heights[n - 1] - k);
            int minValue = min(heights[0] + k, heights[i] - k);
            ans = min(ans, maxValue - minValue);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends