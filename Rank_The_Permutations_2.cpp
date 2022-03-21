// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/rank-the-permutations2323/1#

// } Driver Code Ends
// User function Template for C++

class Solution {
    typedef long long ll;

    const int mod = 1000003;

    ll calculateFactorial(ll n) {
        if (n < 2) return 1;

        return ((n % mod) * calculateFactorial(n - 1)) % mod;
    }

    ll binExp(ll a, ll b) {
        ll res = 1;

        while (b > 0) {
            if ((b & 1) > 0) {
                res = ((res % mod) * (a % mod)) % mod;
                --b;
            }
            a = ((a % mod) * (a % mod)) % mod;
            b /= 2;
        }

        return res;
    }

    void updateCount(char ch, vector<ll>& count) {
        for (char c = ch; c <= 'z'; ++c) {
            --count[c - 'a'];
        }
    }

public:
    int rank(string s) {
        // code here
        ll n = s.size();
        ll fact = calculateFactorial(n);
        ll ans = 1;
        vector<ll> count(26);

        for (char ch : s) {
            ++count[ch - 'a'];
            if (count[ch - 'a'] > 1) return 0;
        }

        for (int i = 1; i < 26; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            fact = (fact * binExp(n - i, (ll)mod - 2)) % mod;
            //cout << fact << endl;
            ll countLesser = s[i] == 'a' ? 0 : count[s[i] - 'a' - 1];
            //cout << countLesser << endl;
            ans = (ans + (fact * countLesser) % mod) % mod;
            updateCount(s[i], count);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.rank(S) << endl;
    }
    return 0;
}  // } Driver Code Ends