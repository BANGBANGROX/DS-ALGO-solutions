#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

    vector<vector<ll>> dp;
    vector<int> nums;
    int n;
    const int MOD = (int) 1e9 + 7;

    int getMask(int num) {
        int result = 0;
        vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        for (int i = 0; i < (int) prime.size(); ++i) {
            if (prime[i] > num) break;
            if (num % prime[i] == 0) {
                num /= prime[i];
                if (num % prime[i] == 0) return -1;
                result |= (1 << (i + 1));
            }
        }

        return result;
    }

    ll squareFreeSubsetsUtil(int ind, int prodMask) {
        if (ind == n) return 1;

        if (dp[ind][prodMask] != -1) return dp[ind][prodMask];

        ll result = squareFreeSubsetsUtil(ind + 1, prodMask);
        int mask = getMask(nums[ind]);

        if ((prodMask & mask) == 0) {
           result = (result +
                   squareFreeSubsetsUtil(ind + 1, prodMask | mask)) % MOD;
        }

        return dp[ind][prodMask] = result;
    }

public:
    int squareFreeSubsets(vector<int>& nums) {
        n = (int) nums.size();
        this->nums = nums;
        dp = vector<vector<ll>>(n, vector<ll>((1 << 11), -1));

        int ans = (int) squareFreeSubsetsUtil(0, 1);

        return (ans - 1 + MOD) % MOD;
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

        Solution solution;
        cout << solution.squareFreeSubsets(nums);
    }

    return 0;
}
