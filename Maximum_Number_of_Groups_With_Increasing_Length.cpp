#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        ll totalSum = 0;
        ll answer = 0;

        sort(usageLimits.begin(), usageLimits.end());

        for (int limit : usageLimits) {
            totalSum += limit;
            if (totalSum >= (answer + 1) * (answer + 2) / 2) {
                ++answer;
            }
        }

        return (int)answer;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> usageLimits(n);
        for (int& x : usageLimits) {
            cin >> x;
        }

        Solution solution;
        cout << solution.maxIncreasingGroups(usageLimits) << endl;
    }

    return 0;
}