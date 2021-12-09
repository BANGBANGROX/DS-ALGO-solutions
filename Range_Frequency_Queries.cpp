#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class RangeFreqQuery {
public:
    vector<int> nums;
    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int>& arr) {
        nums = arr;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        int low = lower_bound(mp[value].begin(), mp[value].end(), left) - mp[value].begin();
        int high = upper_bound(mp[value].begin(), mp[value].end(), right) - mp[value].begin() - 1;

        return high - low + 1;
    }
};
