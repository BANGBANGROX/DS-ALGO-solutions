#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
    unordered_map<int, bool> dp;
    vector<int> nums;

    bool validPartitionHandler(int index) {
        if (dp.find(index) != dp.end()) {
            return dp[index];
        }

        dp[index] = false;

        if (index > 0 && nums[index] == nums[index - 1]) {
            dp[index] |= validPartitionHandler(index - 2);
        }

        if (index > 1 && nums[index] == nums[index - 1] && 
            nums[index - 1] == nums[index - 2]) {
            dp[index] |= validPartitionHandler(index - 3);
        }

        if (index > 1 && nums[index] == nums[index - 1] + 1 &&
            nums[index - 1] == nums[index - 2] + 1) {
            dp[index] |= validPartitionHandler(index - 3);
        }

        return dp[index];
    }

public:
    bool validPartition(vector<int>& nums) {
        this->nums = nums;
        dp[-1] = true;

        return validPartitionHandler((int)nums.size() - 1);
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

        Solution solution;
        if (solution.validPartition(nums)) {
            cout << "true\n";
        }
        else {
            cout << "false\n";
        }
    }

    return 0;
}