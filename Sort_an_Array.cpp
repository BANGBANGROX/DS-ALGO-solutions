#include<bits/stdc++.h>
using namespace std;

class Solution {
    void merge(vector<int> &temp, vector<int> &nums, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (nums[i] < nums[j]) {
                temp[k] = nums[i];
                ++i;
            }
            else {
                temp[k] = nums[j];
                ++j;
            }
            ++k;
        }

        while (i <= mid) {
            temp[k] = nums[i];
            ++i;
            ++k;
        }

        while (j <= right) {
            temp[k] = nums[j];
            ++j;
            ++k;
        }

        for (i = left; i <= right; ++i) {
            nums[i] = temp[i];
        }
    }


    void mergeSort(vector<int> &temp, vector<int> &nums, int left, int right) {
        if (left >= right) return;

        int mid = (left + right) / 2;

        mergeSort(temp, nums, left, mid);
        mergeSort(temp, nums, mid + 1, right);

        merge(temp, nums, left, mid, right);
    }

public:
    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> temp(n);

        mergeSort(temp, nums, 0, n - 1);

        return nums;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int &x: nums) cin >> x;

        Solution solution;
        vector<int> ans = solution.sortArray(nums);
        for (int &x: ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}