#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& nums, int val) {
    for (int x : nums) {
        val += x;
        if (val < 1) return false;
    }

    return true;
}

int minStartValue(vector<int>& nums) {
    int l = 1, r = 10000;

    while (l < r) {
        int mid = (l + r) / 2;
        if (isValid(nums, mid)) r = mid;
        else l = mid + 1;
    }

    return l;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int& x : nums) cin >> x;

        cout << minStartValue(nums) << endl;
    }

    return 0;
}