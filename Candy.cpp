#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) prefix[i] = prefix[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) suffix[i] = suffix[i + 1] + 1;
        }

        for (int i = 0; i < n; ++i) {
            ans += max(prefix[i], suffix[i]);
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
        vector<int> ratings(n);
        for (int& x : ratings) {
            cin >> x;
        }

        Solution solution;
        cout << solution.candy(ratings) << endl;
    }

    return 0;
}