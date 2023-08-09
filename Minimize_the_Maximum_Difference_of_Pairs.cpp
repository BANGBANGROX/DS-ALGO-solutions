#include<bits/stdc++.h>
using namespace std;

class Solution {
    int countValidPairs(vector<int>& nums, int threshold) {
        int n = (int)nums.size();
        int idx = 0;
        int cnt = 0;

        while (idx < n - 1) {
            if (nums[idx + 1] - nums[idx] <= threshold) {
                ++cnt;
                ++idx;
            }
            ++idx;
        }

        return cnt;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        int l = 0;
        int r = (int)1e9 + 5;

        sort(nums.begin(), nums.end());

        while (l < r) {
            int mid = (l + ((r - l) >> 1));
            if (countValidPairs(nums, mid) >= p) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
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
        int p;
        cin >> p;

        Solution solution;
        cout << solution.minimizeMax(nums, p) << endl;
    }

    return 0;
}