#include<bits/stdc++.h>

using namespace std;

class Solution {
    bool check(vector<int> &price, int diff, int k) {
        int n = (int) price.size();
        int next = price[0] + diff;
        --k;

        for (int i = 1; i < n; ++i) {
            if (price[i] >= next) {
                --k;
                if (k == 0) break;
                next = price[i] + diff;
            }
        }

        return k == 0;
    }

public:
    int maximumTastiness(vector<int> &price, int k) {
         sort(begin(price), end(price));

         int l = 1;
         int r = (int) 1e9;

         while (l <= r) {
             int mid = (l + ((r - l) >> 1));
             if (check(price, mid, k)) {
                 l = mid + 1;
             }
             else {
                 r = mid - 1;
             }
         }

         return l - 1;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> price(n);
        for (int &x: price) cin >> x;
        int k;
        cin >> k;

        Solution solution;
        cout << solution.maximumTastiness(price, k) << endl;
    }

    return 0;
}
