// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution {
    typedef long long ll;
public:
    vector<ll> factorial(vector<ll>& a, int n) {
        ll maxElement = *max_element(a.begin(), a.end());
        vector<ll> factorial(maxElement + 1);
        vector<ll> ans;
        const int mod = 1e9 + 7;

        factorial[0] = 1;

        for (ll i = 1; i <= maxElement; ++i) {
            factorial[i] = (factorial[i - 1] * i) % mod;
        }

        for (int i = 0; i < n; ++i) {
            ans.push_back(factorial[a[i]]);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends