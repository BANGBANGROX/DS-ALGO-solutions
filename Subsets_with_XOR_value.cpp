// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int subsetXOR(vector<int>& nums, int n, int k) {
        // code here
        int maxElement = *max_element(nums.begin(), nums.end());
        int size = (1 << ((int)log2(maxElement) + 1)) - 1;
        vector<vector<int>> dp(n + 1, vector<int>(size + 1));

        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= size; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ nums[i - 1]];
            }
        }

        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int K;
        cin >> K;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        Solution ob;
        cout << ob.subsetXOR(v, N, K) << endl;
    }
    return 0;
}  // } Driver Code Ends