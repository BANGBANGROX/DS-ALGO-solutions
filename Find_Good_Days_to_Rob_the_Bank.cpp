#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> pref(n, 1), suff(n, 1), ans;

        for (int i = 1; i < n; ++i) {
            if (security[i] <= security[i - 1]) pref[i] = pref[i - 1] + 1;
        }
        for (int i = n - 2; i > -1; --i) {
            if (security[i] <= security[i + 1]) suff[i] = suff[i + 1] + 1;
        }

        for (int i = time; i < n - time; ++i) {
            if (pref[i] >= time && suff[i] >= time) ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, time;
        cin >> n;
        vector<int> security(n);
        for (int& x : security) cin >> x;
        cin >> time;

        Solution obj;
        vector<int> ans = obj.goodDaysToRobBank(security, time);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}