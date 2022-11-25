//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    typedef long long ll;

    void multiply(vector<vector<ll>>& a, vector<vector<ll>>& b, ll MOD) {
        int n = (int)a.size();
        vector<vector<long>> ans(n, vector<long>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = ans[i][j];
            }
        }
    }

    void matrixExponentiation(vector<vector<ll>>& ans, ll a, ll b, ll n, ll m) {
        vector<vector<ll>> startingMatrix = { {a, b, 1}, {1, 0, 0}, {0, 0, 1} };

        while (n > 0) {
            if ((n & 1) > 0) {
                multiply(ans, startingMatrix, m);
                --n;
            }
            multiply(startingMatrix, startingMatrix, m);
            n >>= 1;
        }
    }

public:
    ll genFibNum(ll a, ll b, ll c, ll n, ll m) {
        // code here
        if (n <= 2) return 1 % m;

        vector<vector<ll>> ans = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

        matrixExponentiation(ans, a, b, n - 2, m);

        return (ans[0][0] + ans[0][1] + c * ans[0][2]) % m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c, n, m;

        cin >> a >> b >> c >> n >> m;

        Solution ob;
        cout << ob.genFibNum(a, b, c, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends