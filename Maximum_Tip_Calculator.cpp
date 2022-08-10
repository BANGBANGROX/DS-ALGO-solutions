//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
    typedef long long ll;

public:
    ll maxTip(int a[], int b[], int n, int x, int y) {
        // code here
        vector<pair<int,int>> differenceWithIndex(n);

        for (int i = 0; i < n; ++i) {
            differenceWithIndex[i] = {a[i] - b[i], i};
        }

        sort(differenceWithIndex.begin(), differenceWithIndex.end());
        reverse(differenceWithIndex.begin(), differenceWithIndex.end());

        int l = 0;
        int r = n - 1;
        int cnt1 = 0;
        int cnt2 = 0;
        ll ans = 0;

        while (cnt1 + cnt2 < n && cnt1 < x && cnt2 < y) {
            if (differenceWithIndex[l].first >= abs(differenceWithIndex[r].first)) {
                ans += a[differenceWithIndex[l].second];
                ++cnt1;
                ++l;
            }
            else {
                ans += b[differenceWithIndex[r].second];
                ++cnt2;
                --r;
            }
        }

        while (cnt1 + cnt2 < n && cnt1 < x) {
            ans += a[differenceWithIndex[l].second];
            ++cnt1;
            ++l;
        }

        while (cnt1 + cnt2 < n && cnt2 < y) {
            ans += b[differenceWithIndex[r].second];
            ++cnt2;
            --r;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        Solution obj;
        auto ans = obj.maxTip(a, b, n, x, y);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends