#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int takeCharacters(string s, int k) {
        int n = (int) s.size();
        vector<int> count(3);

        for (char ch : s) {
            ++count[ch - 'a'];
        }

        if (count[0] < k || count[1] < k || count[2] < k) return -1;

        int i = n - 1;
        int j = n - 1;
        int ans = n;

        while (i >= 0) {
            --count[s[i] - 'a'];
            while (count[0] < k || count[1] < k || count[2] < k) {
                ++count[s[j] - 'a'];
                --j;
            }
            ans = min(ans, i - j + n - 1);
            --i;
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
         string s;
         int k;
         cin >> s >> k;

         cout << Solution::takeCharacters(s, k) << endl;
    }

    return 0;
}
