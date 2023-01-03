#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

    vector<int> nums;
    vector<ll> power;
    vector<vector<ll>> dp1;
    vector<vector<ll>> dp2;
    int n;
    int k;
    const int MOD = (int) 1e9 + 7;

    void init(vector<int> &nums, int k) {
        this->k = k;
        this->nums = nums;
        n = (int) nums.size();
        power = vector<ll>(n + 1);
        dp1 = vector<vector<ll>>(n, vector<ll>(k + 1, -1));
        dp2 = vector<vector<ll>>(n, vector<ll>(k + 1, -1));

        power[0] = 1;

        for (int i = 1; i <= n; ++i) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
    }

    ll countPartitionsUtil(int idx, ll group1Sum, ll group2Sum) {
        if (idx >= n) {
            if (group1Sum >= k && group2Sum >= k) return 1;
            return 0;
        }

        if (group1Sum >= k && group2Sum >= k) return power[n - idx];

        if (group1Sum <= k && dp1[idx][group1Sum] != -1) return dp1[idx][group1Sum];

        if (group2Sum <= k && dp2[idx][group2Sum] != -1) return dp2[idx][group2Sum];

        ll ans = (countPartitionsUtil(idx + 1, group1Sum + nums[idx], group2Sum) +
                countPartitionsUtil(idx + 1, group1Sum, group2Sum + nums[idx])) % MOD;

        if (group1Sum <= k) return dp1[idx][group1Sum] = ans;

        return dp2[idx][group2Sum] = ans;
    }

public:
    int countPartitions(vector<int> &nums, int k) {
         init(nums, k);

         return (int) countPartitionsUtil(0, 0, 0);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
         int n;
         cin >> n;
         vector<int> nums(n);
         for (int &x: nums) {
             cin >> x;
         }
         int k;
         cin >> k;

         Solution solution;
         cout << solution.countPartitions(nums, k) << endl;
    }

    return 0;
}
