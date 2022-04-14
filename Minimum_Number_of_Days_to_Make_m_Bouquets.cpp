#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& bloomDay, int m, int k, int days) {
        int completed = 0;
        int n = bloomDay.size();

        for (int i = 0; i < n; ++i) {
            int taken = 0;
            while (i < n && taken < k && bloomDay[i] <= days) {
                ++taken;
                ++i;
            }
            if (taken == k) {
                ++completed;
                --i;
            }
            if (completed == m) return true;
        }

        return false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if (m * k > n) return -1;

        int l = 1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (check(bloomDay, m, k, mid)) {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
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
        vector<int> bloomDay(n);
        for (int& x : bloomDay) cin >> x;
        int m, k;
        cin >> m >> k;

        Solution solution;
        cout << solution.minDays(bloomDay, m, k) << endl;
    }
}