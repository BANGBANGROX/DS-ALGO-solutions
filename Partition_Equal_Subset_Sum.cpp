#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();

        sort(begin(nums), end(nums));

        for (int x : nums) {
            sum += x;
        }

        if (sum & 1) return false;

        vector<bool> dp(sum / 2 + 1);
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            for (int j = sum / 2; j > -1; --j) {
                if (nums[i] > j) break;
                dp[j] = dp[j] | (dp[j - nums[i]]);
            }
        }
       
        return dp[sum / 2];
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int& x : nums) cin >> x;

        Solution obj;
        if (obj.canPartition(nums)) cout << "Possible\n";
        else cout << "Not possible\n";
    }

    return 0;
}