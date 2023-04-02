#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = (int) profits.size();
        int ans = w;
        int idx = 0;
        vector<vector<int>> investments;
        priority_queue<int> pq;

        for (int i = 0; i < n; ++i) {
            investments.push_back({capital[i], profits[i]});
        }

        sort(investments.begin(), investments.end());

        while (k > 0) {
            while (idx < n && investments[idx][0] <= ans) {
                pq.push(investments[idx][1]);
                ++idx;
            }
            if (pq.empty()) break;
            ans += pq.top();
            pq.pop();
            --k;
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int k, w, n;
        cin >> k >> w >> n;
        vector<int> profits(n);
        for (int &x: profits) {
            cin >> x;
        }
        vector<int> capital(n);
        for (int &x: capital) {
            cin >> x;
        }

        Solution solution;
        cout << solution.findMaximizedCapital(k, w, profits, capital);
    }

    return 0;
}
