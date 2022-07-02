// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    string kthPermutation(int n, int k) {
        // code here
        string initialPermutation("");
        string ans("");
        vector<int> factorial(n + 1);

        factorial[0] = 1;
        --k;

        for (int i = 1; i <= n; ++i) {
            initialPermutation += to_string(i);
            factorial[i] = factorial[i - 1] * i;
        }

        for (int i = n - 1; i >= 0; --i) {
            int fact = factorial[i];
            int idx = k / fact;
            ans += initialPermutation[idx];
            initialPermutation.erase(idx, 1);
            k %= fact;
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends