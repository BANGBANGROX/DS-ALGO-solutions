#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int firstSum = accumulate(nums1.begin(), nums1.end(), 0);

        if (firstSum <= x) {
            return 0;
        }

        int secondSum = accumulate(nums2.begin(), nums2.end(), 0);
        int n = (int)nums1.size();
        int answer = n + 1;
        vector<vector<int>> nums2AndNums1(n, vector<int>(2));
        vector<int> dp(n + 1);

        for (int i = 0; i < n; ++i) {
            nums2AndNums1[i][0] = nums2[i];
            nums2AndNums1[i][1] = nums1[i];
        }

        sort(nums2AndNums1.begin(), nums2AndNums1.end());

        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, answer); j > 0; --j) {
                dp[j] = max(dp[j], dp[j - 1] + 
                    nums2AndNums1[i - 1][0] * j + nums2AndNums1[i - 1][1]);
                if (firstSum + secondSum * j - dp[j] <= x) {
                    answer = j;
                }
            }
        }

        return answer <= n ? answer : -1;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums1(n), nums2(n);
        for (int& x : nums1) {
            cin >> x;
        }
        for (int& x : nums2) {
            cin >> x;
        }
        int x;
        cin >> x;

        Solution solution;
        cout << solution.minimumTime(nums1, nums2, x) << endl;
    }

    return 0;
}