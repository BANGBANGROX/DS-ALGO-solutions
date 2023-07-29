#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

    vector<vector<ll>> dp;
    vector<int> nums;
    int x;
    int n;

    ll maxScoreHandler(int idx, int lastParity) {
        if (idx == n) return 0;

        if (dp[idx][lastParity] == -1) {
            int currentParity = nums[idx] % 2;
            ll leave = maxScoreHandler(idx + 1, lastParity);
            ll take = nums[idx] + maxScoreHandler(idx + 1, currentParity) - 
                (lastParity != currentParity ? x : 0);
            dp[idx][lastParity] = max(leave, take);
        }

        return dp[idx][lastParity];
    }

public:
    ll maxScore(vector<int>& nums, int x) {
        this->nums = nums;
        n = (int)nums.size();
        this->x = x;
        dp = vector<vector<ll>>(n, vector<ll>(2, -1));

        return nums[0] + maxScoreHandler(1, nums[0] % 2);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int& x : nums) {
            cin >> x;
        }
        int x;
        cin >> x;

        Solution solution;
        cout << solution.maxScore(nums, x);
    }
}