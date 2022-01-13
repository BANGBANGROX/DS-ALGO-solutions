#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;
public:
    int minMoves(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> pos;

        if (k == 1 || n <= 2) return 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) pos.push_back(i);
        }

        n = pos.size();
        vector<ll> prefix(n);

        for (int i = 0; i < n; ++i) {
            prefix[i] = (i > 0) ? prefix[i - 1] + pos[i] : pos[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i <= n - k; ++i) {
            int mid = i + k / 2;
            ll right = prefix[i + k - 1] - prefix[mid];
            ll left = prefix[mid - 1] - ((i > 0) ? prefix[i - 1] : 0);
            ll r = (k - 1) / 2;
            ll currentAns = right - left + ((k % 2 == 0) ? pos[mid] : 0) - r * (r + 1) - ((k % 2 == 0) ? r + 1 : 0);
            ans = min((ll)ans, currentAns);
        }
        ans = max(ans, 0);

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        int k;
        cin >> k;

        Solution solution;
        cout << solution.minMoves(nums, k) << endl;
    }

    return 0;
}