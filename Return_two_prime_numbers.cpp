// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> primeDivision(int n) {
        // code here
        vector<int> primes;
        vector<bool> sieve(n + 1, true);

        for (int i = 2; i <= n; ++i) {
            if (sieve[i]) {
                primes.push_back(i);
                for (int j = 2 * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }

        for (int& num : primes) {
            if (sieve[n - num]) {
                return { num,n - num };
            }
        }

        return {};
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends