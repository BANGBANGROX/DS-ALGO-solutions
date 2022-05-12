// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    typedef long long int ll;

public:
    ll killinSpree(ll n) {
        // Code Here
        ll l = 1;
        ll r = 1e5;
        ll ans = -1;

        while (l <= r) {
            ll mid = (l + ((r - l) >> 1));
            ll sum = mid * (mid + 1) * (2 * mid + 1) / 6;
            if (sum <= n) {
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
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
        long long int n; cin >> n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends