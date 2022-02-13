// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isPrime(int n) {
        if (n == 1) return false;

        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }

        return true;
    }

public:
    vector<int> primeRange(int m, int n) {
        // code here
        vector<int> ans;

        for (int i = m; i <= n; ++i) {
            if (isPrime(i)) ans.push_back(i);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends