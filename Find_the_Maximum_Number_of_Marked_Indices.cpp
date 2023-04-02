#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = (int) nums.size();
        int l = 0;
        int ans = 0;

        sort(nums.begin(), nums.end());

        for (int r = (n + 1) / 2; r < n; ++r) {
            if (2 * nums[l] <= nums[r]) {
                ans += 2;
                ++l;
            }
        }

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
        for (int &x: nums) {
            cin >> x;
        }

        Solution solution;
        cout << solution.maxNumOfMarkedIndices(nums) << endl;
    }

    return 0;
}
