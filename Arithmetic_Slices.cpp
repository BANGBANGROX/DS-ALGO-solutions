#include<bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size(), total = 0, seqNum = 1;
    vector<int> dp(n, INT_MAX); // dp[i] is the common difference of the ap where nums[i] is the last element

    for (int i = 1; i < n - 1; ++i) {
        if (2 * nums[i] == (nums[i - 1] + nums[i + 1])) {
            int d = nums[i] - nums[i - 1];
            if (dp[i - 1] == d) ++seqNum; // if the ap with d common diff already exists then we can extend the seqNum
            else seqNum = 1; // else restart
            total += seqNum;
            dp[i] = d;
        }
    }

    return total;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int& x : nums) cin >> x;

        cout << numberOfArithmeticSlices(nums) << endl;
    }

    return 0;
}