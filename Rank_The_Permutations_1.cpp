// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/rank-the-permutations2229/1#

// } Driver Code Ends
//User function template for C++

class Solution {
    typedef long long ll;

    ll calculateFactorial(ll n) {
        if (n <= 1) return 1;

        return n * calculateFactorial(n - 1);
    }

    void updateCount(char ch, vector<ll>& count) {
        for (char c = ch; c <= 'z'; ++c) {
            --count[c - 'a'];
        }
    }

public:
    ll findRank(string str) {
        //code here
        ll ans = 1;
        ll n = str.size();
        ll fact = calculateFactorial(n);
        vector<ll> count(26);
        
        for (char ch : str) {
            ++count[ch - 'a'];
        }

        for (int i = 1; i < 26; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            fact /= (n - i);
            int lesserCount = str[i] == 'a' ? 0 : count[str[i] - 'a' - 1];
            ans += (ll)lesserCount * fact;
            updateCount(str[i], count);
        }

        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout << ans << endl;
    }
}  // } Driver Code Ends