#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        int n = nums.size();
        vector<long> dp(n, 1);
        const int MOD = 1e9 + 7;
        unordered_map<int, int> numToIndex;
        long ans = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            numToIndex[nums[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    int right = nums[i] / nums[j];
                    if (numToIndex.find(right) != numToIndex.end()) {
                        dp[i] = (dp[i] + (dp[j] * dp[numToIndex[right]]) % MOD) % MOD;
                    }
                }
            }
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T-- > 0) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int&x : nums) cin >> x;

        Solution solution;
        cout << solution.numFactoredBinaryTrees(nums) << endl;
    }
}