#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

public:
    ll maxArrayValue(vector<int>& nums) {
        vector<ll> longNums(nums.begin(), nums.end());
        int n = (int)nums.size();

        for (int i = n - 2; i >= 0; --i) {
            if (longNums[i] <= longNums[i + 1]) {
                longNums[i] += longNums[i + 1];
            }
        }

        return *max_element(longNums.begin(), longNums.end());
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
        cout << solution.maxArrayValue(nums) << endl;
    }

    return 0;
}