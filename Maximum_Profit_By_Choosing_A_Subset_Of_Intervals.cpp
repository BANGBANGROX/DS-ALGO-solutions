//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    int lowerBound(vector<vector<int>> &nums, int key) {
        int n = (int) nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (nums[mid][0] < key) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }

  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        vector<int> dp(n);

        sort(intervals.begin(), intervals.end());

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = intervals[i][2];
            int idx = lowerBound(intervals, intervals[i][1]);
            if (idx < n) dp[i] += dp[idx];
            if (i < n - 1) dp[i] = max(dp[i], dp[i + 1]);
        }

        return dp[0];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends