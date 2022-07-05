// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution {
    typedef long long ll;
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, ll k) {
        ll product = 1;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; ++r) {
            product *= a[r];
            while (product >= k) {
                product /= a[l];
                ++l;
            }
            ans += (r - l + 1);
        }

        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends