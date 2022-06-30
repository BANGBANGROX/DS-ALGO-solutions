// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int removals(vector<int>& a, int k) {
        //Code here
        int n = a.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;

        sort(a.begin(), a.end());

        while (r < n) {
            if (a[r] - a[l] <= k) {
                maxLen = max(maxLen, r - l + 1);
                ++r;
            }
            else {
                ++l;
            }
        }

        return n - maxLen;
    }
};


// { Driver Code Starts.


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;
        int ans = ob.removals(a, k);

        cout << ans << endl;
    }
}


// } Driver Code Ends