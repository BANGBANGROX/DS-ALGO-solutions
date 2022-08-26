#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(int start, string &stamp, string &target) {
        bool res = false;
        int m = stamp.size();

        for (int i = 0; i < m; ++i) {
            if (target[start + i] == '?') continue;
            res = true;
            if (stamp[i] != target[start + i]) return false;
        }

        return res;
    }

public:
    vector<int> movesToStamp(string stamp, string target) {
          vector<int> ans;
          int m = stamp.size();
          int n = target.size();
          int remaining = n;

          while (remaining > 0) {
              bool flag = false;
              for (int i = 0; i < n - m + 1; ++i) {
                  if (check(i, stamp, target)) {
                      ans.push_back(i);
                      flag = true;
                      for (int j = 0; j < m; ++j) {
                          if (target[i + j] != '?') {
                              target[i + j] = '?';
                              --remaining;
                          }
                      }
                  }
              }
              if (!flag) return {};
          }

          reverse(ans.begin(), ans.end());

          return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string stamp, target;
        cin >> stamp >> target;

        Solution solution;
        vector<int> ans = solution.movesToStamp(stamp, target);
        for (int &x: ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}