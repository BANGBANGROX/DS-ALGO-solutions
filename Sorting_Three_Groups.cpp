#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(3, n);

        for (const int& x : nums) {
            --dp[x - 1];
            dp[1] = min(dp[0], dp[1]);
            dp[2] = min(dp[1], dp[2]);
        }

        return dp[2];
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
            assert(x > 0 && x < 4);
        }

        Solution solution;
        cout << solution.minimumOperations(nums) << endl;
    }

    return 0;
}