// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int count(int n, vector<int>& a, int x) {
        // code here
        vector<bool> changed(n);
        int oneChanges = 0, ans = INT_MAX;

        for (int i = 31; i >= 0; --i) {
            int bit = (1 << i) & x, zeroChanges = 0;
            for (int j = 0; j < n; ++j) {
                int currBit = (1 << i) & a[j];
                if (bit > 0) {
                    if (currBit == 0 && !changed[j]) {
                        changed[j] = 1;
                        ++oneChanges;
                    }
                }
                else {
                    if (currBit == 0 && !changed[j]) {
                        ++zeroChanges;
                    }
                }
            }
            if (bit == 0) ans = min(ans, oneChanges + zeroChanges);
        }

        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, X;
        cin >> N >> X;
        vector<int> A(N);
        for (auto& i : A)
            cin >> i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout << ans << endl;
    }
}  // } Driver Code Ends