// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    typedef long long ll;

    bool checkPrime(ll n) {
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) return false;
        }

        return true;
    }

public:
    ll sqNum(ll n) {
        // code here
        vector<ll> primeNumbersSquares;
        ll ans = 0;

        for (int i = 2; i <= sqrt(n); ++i) {
            if (checkPrime(i)) primeNumbersSquares.push_back((ll)i * i);
        }

        if (primeNumbersSquares.empty()) return ans;

        ans += n / primeNumbersSquares[0];

        for (int i = 1; i < (int)primeNumbersSquares.size(); ++i) {
            ans += n / primeNumbersSquares[i];
            for (int j = 0; j < i; ++j) {
                ll lcm = (primeNumbersSquares[i] * primeNumbersSquares[j]);
                ans -= n / lcm;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;

        cin >> N;

        Solution ob;
        cout << ob.sqNum(N) << endl;
    }
    return 0;
}  // } Driver Code Ends