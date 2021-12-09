#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, ans = nums.size();

    while (l <= r) {
        int mid = (l + ((r - l) >> 2));
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, target;
        cin >> n;
        vector<int> nums(n);
        for (int& x : nums) cin >> x;
        cin >> target;

        cout << searchInsert(nums, target) << endl;
    }

    return 0;
}