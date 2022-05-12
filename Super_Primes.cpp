// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    int superPrimes(int n) {
        // Your code goes here
        vector<int> primes;
        vector<bool> sieve(n + 1, true);
        int ans = 0;

        for (int i = 2; i <= n; ++i) {
            if (sieve[i]) {
                primes.push_back(i);
                for (int j = 2 * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }

        for (int i = 1; i < primes.size(); ++i) {
            if (primes[i] + 2 <= n && sieve[primes[i] + 2]) ++ans;
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.superPrimes(n) << "\n";
    }

    return 0;
}
// } Driver Code Ends