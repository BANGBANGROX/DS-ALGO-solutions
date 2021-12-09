#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size(), maxInd = -1;
    vector<int> dp(n, 1), pred(n, -1), ans;

    // dp[i] is the size of the largest subset which ends on nums[i]
    // pred[i] is the index of the next element in that maximum size subset
    // maxInd is the index of the last element of the maximum size subset

    sort(begin(nums), end(nums));

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pred[i] = j;
            }
            if (maxInd == -1 || dp[i] > dp[maxInd]) maxInd = i;
        }
    }

    for (; maxInd > -1; maxInd = pred[maxInd]) ans.push_back(nums[maxInd]);
    
    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int& x : nums) cin >> x;

        vector<int> ans = largestDivisibleSubset(nums);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}