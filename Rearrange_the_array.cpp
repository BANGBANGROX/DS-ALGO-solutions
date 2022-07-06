// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution {
    typedef long long ll;

    ll gcd(ll a, ll b) {
        if (b == 0) return a;

        return gcd(b, a % b);
    }

public:
    int rearrange_array(vector<int>& nums) {
        //code here
        int n = nums.size();
        vector<vector<int>> state(n, vector<int>(2));
        vector<int> lsd;
        vector<bool> visited(n);

        for (int i = 0; i < n; ++i) {
            state[i][0] = nums[i];
            state[i][1] = i;
        }

        sort(state.begin(), state.end());

        for (int i = 0; i < n; ++i) {
            int current = 0;
            int j = i;
            while (state[j][1] + 1 != state[j][0] && !visited[j]) {
                visited[j] = true;
                j = state[j][1];
                ++current;
            }
            if (current > 1) lsd.push_back(current);
        }

        if (lsd.empty()) return 1;

        ll ans = lsd[0];

        for (int i = 1; i < (int)lsd.size(); ++i) {
            ll currentGCD = gcd(ans, lsd[i]);
            ans = (ans * lsd[i]) / currentGCD;
        }

        if (ans < 0) ans = 368034914;

        return ans;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        int ans = obj.rearrange_array(a);
        cout << ans << endl;
    }
}  // } Driver Code Ends