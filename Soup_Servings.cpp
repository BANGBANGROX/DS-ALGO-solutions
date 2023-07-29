#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
    unordered_map<int, unordered_map<int, double>> dp;

    double soupServingsHandler(int i, int j) {
        if (i <= 0 && j <= 0) return 0.5;

        if (i <= 0) return 1.0;

        if (j <= 0) return 0.0;

        if (dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end()) return dp[i][j];

        double result = (soupServingsHandler(i - 4, j) + 
            soupServingsHandler(i - 3, j - 1) + soupServingsHandler(i - 2, j - 2) + 
            soupServingsHandler(i - 1, j - 3)) / 4.0;

        return dp[i][j] = result;
    }

public:
    double soupServings(int n) {
        int m = (int)ceil(n / 25.0);
        double maxGap = 1 - 1e-5;

        for (int i = 1; i <= m; ++i) {
            if (soupServingsHandler(i, i) > maxGap) {
                return 1.0;
            }
        }

        return soupServingsHandler(m, m);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        Solution solution;
        cout << solution.soupServings(n) << endl;
    }

    return 0;
}