// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool partitionArray(int n, int k, int m, vector<int>& nums) {
        // code here
        vector<bool> dp(n + 1);

        dp[0] = true;

        sort(nums.begin(), nums.end());

        for (int i = k; i <= n; ++i) {
            int idx = lower_bound(nums.begin(), nums.end(), nums[i - 1] - m) - nums.begin();
            int end = i - k;
            for (int j = idx; j <= end; ++j) {
                dp[i] = dp[i] | dp[j];
                if (dp[i]) break;
            }
        }

        return dp[n];
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
// } Driver Code Ends