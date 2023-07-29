#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

    ll computePower(ll x, ll p) {
        ll result = 1;

        while (p > 0) {
            result *= x;
            --p;
        }

        return result;
    }

public:
    int numberOfWays(int n, int x) {
        vector<ll> dp(n + 1);
        const int MOD = (int)1e9 + 7;

        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            ll power = computePower(i, x);
            for (int j = n; j >= power; --j) {
                dp[j] = (dp[j] + dp[j - power]) % MOD;
            }
        }

        return (int)dp[n];
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, x;
        cin >> n >> x;

        Solution solution;
        cout << solution.numberOfWays(n, x) << endl;
    }
}