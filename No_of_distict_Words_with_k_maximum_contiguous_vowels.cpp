// { Driver Code Starts
//Initial Template for C++

// https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1

#include<bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    typedef long long ll;

    const int mod = 1e9 + 7;

    ll binExp(ll a, ll b) {
        ll res = 1;

        while (b > 0) {
            if ((b & 1) > 0) {
                res = (res * a) % mod;
                --b;
            }
            a = (a * a) % mod;
            b /= 2;
        }

        return res;
    }

public:
    int kvowelwords(int n, int k) {
        // Write Your Code here
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
        ll sum = 1;

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = (sum * 21) % mod;
            sum = dp[i][0];
            for (int j = 1; j <= k; ++j) {
                if (i < j) dp[i][j] = 0;
                else if (i == j) dp[i][j] = binExp((ll)5, i);
                else dp[i][j] = (dp[i - 1][j - 1] * 5) % mod;
                sum = (sum + dp[i][j]) % mod;
            }
        }

        return (int)sum;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N; int K;
        cin >> N >> K;

        Solution ob;
        int ans = ob.kvowelwords(N, K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends