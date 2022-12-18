//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    typedef long long ll;

    ll calculateGCD(ll a, ll b) {
        if (b == 0) return a;

        return calculateGCD(b, a % b);
    }

public:
    ll maxGcd(int n) {
        // code here
        ll ans = 1;
        int cnt = 0;

        while (n > 0) {
            if (calculateGCD(ans, n) == 1) {
                ans *= n;
                ++cnt;
            }
            if (cnt == 4) break;
            --n;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends-