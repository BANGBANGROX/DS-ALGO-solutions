#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
        int n = stations.size();
        vector<long> dp(n + 1);

        dp[0] = startFuel;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (dp[j] >= stations[i][0]) {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }

        for (int i = 0; i <= n; ++i) {
            if (dp[i] >= target) return i;
        }

        return -1;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int target;
        cin >> target;
        int startFuel;
        cin >> startFuel;
        int n;
        cin >> n;
        vector<vector<int>> stations(n, vector<int>(2));
        for (vector<int> &x: stations) cin >> x[0] >> x[1];

        Solution solution;
        cout << solution.minRefuelStops(target, startFuel, stations) << endl;
    }

    return 0;
}