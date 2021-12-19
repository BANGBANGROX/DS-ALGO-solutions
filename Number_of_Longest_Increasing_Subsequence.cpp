#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 1, ans = 0;
        vector<int> len(n, 1), cnt(n, 1);
        // len[i] is the length of the lis till nums[i] and cnt[i] is the count of such sequences

        if (n == 1) return 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (len[i] == len[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                    else if (len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            maxLen = max(maxLen, len[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (len[i] == maxLen) {
                ans += cnt[i];
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
        for (int& x : nums) cin >> x;

        Solution obj;
        cout << obj.findNumberOfLIS(nums) << endl;
    }

    return 0;
}