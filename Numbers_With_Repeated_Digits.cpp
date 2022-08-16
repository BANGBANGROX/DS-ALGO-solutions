#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
         int ans = 0;
         string s = to_string(n);
         int len = s.size();
         vector<int> visited(10);

         for (int i = 1; i < len; ++i) {
             int mul = 9;
             int res = 1;
             for (int j = 1; j < i; ++j) {
                 res *= mul;
                 --mul;
             }
             ans += 9 * res;
         }

         for (int i = 0; i < len; ++i) {
             int smaller = 0;
             for (int dig = 0; dig < s[i] - '0'; ++dig) {
                 if (visited[dig] == 0) {
                     ++smaller;
                 }
             }
             if (i == 0) --smaller;
             int res = 1;
             int mul = 10 - i - 1;
             for (int j = i + 1; j < len; ++j) {
                 res *= mul;
                 --mul;
             }
             ans += smaller * res;
             if (visited[s[i] - '0'] == 0) visited[s[i] - '0'] = 1;
             else break;
         }

         if (accumulate(visited.begin(), visited.end(), 0) == len) ++ans;

         return n - ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        Solution solution;
        cout << solution.numDupDigitsAtMostN(n) << endl;
    }

    return 0;
}