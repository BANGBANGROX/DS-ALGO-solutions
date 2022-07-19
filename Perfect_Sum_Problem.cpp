//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int perfectSum(int nums[], int n, int sum) {
        // Your code goes here
        vector<int> dp(sum + 1);
        const int mod = 1e9 + 7;

        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = sum; j >= 0; --j) {
                if (nums[i] <= j) {
                    dp[j] = (dp[j] + dp[j - nums[i]]) % mod;
                }
            }
        }

        return dp[sum];
    }

};

//{ Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int* a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";

    }
    return 0;
}

// } Driver Code Ends