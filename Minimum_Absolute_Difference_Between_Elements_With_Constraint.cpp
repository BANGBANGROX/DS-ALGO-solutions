#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> st;
        int n = (int)nums.size();
        int answer = INT_MAX;

        for (int i = n - x - 1; i >= 0; --i) {
            st.insert(nums[i + x]);
            set<int>::iterator it = st.lower_bound(nums[i]);
            if (it == st.end()) {
                --it;
            }
            answer = min(answer, abs(nums[i] - *it));
            if (it != st.begin()) {
                --it;
                answer = min(answer, abs(nums[i] - *it));
            }
        }

        return answer;
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
        int x;
        cin >> x;

        Solution solution;
        cout << solution.minAbsoluteDifference(nums, x);
    }
}