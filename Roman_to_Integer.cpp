#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int ans = 0;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                if (i + 1 < n && s[i + 1] == 'V') {
                    ans += 4;
                    ++i;
                }
                else if (i + 1 < n && s[i + 1] == 'X') {
                    ans += 9;
                    ++i;
                }
                else ans += 1;
            }
            else if (s[i] == 'X') {
                if (i + 1 < n && s[i + 1] == 'L') {
                    ans += 40;
                    ++i;
                }
                else if (i + 1 < n && s[i + 1] == 'C') {
                    ans += 90;
                    ++i;
                }
                else ans += 10;
            }
            else if (s[i] == 'C') {
                if (i + 1 < n && s[i + 1] == 'D') {
                    ans += 400;
                    ++i;
                }
                else if (i + 1 < n && s[i + 1] == 'M') {
                    ans += 900;
                    ++i;
                }
                else ans += 100;
            }
            else ans += mp[s[i]];
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        Solution solution;
        cout << solution.romanToInt(s) << endl;
    }

    return 0;
}