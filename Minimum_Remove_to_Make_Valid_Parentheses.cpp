#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size(), balancingFactor = 0;
        string str("");

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++balancingFactor;
                str += s[i];
            }
            else if (s[i] == ')') {
                if (balancingFactor > 0) {
                    --balancingFactor;
                    str += s[i];
                }
            }
            else str += s[i];
        }

        if (balancingFactor == 0) return str;

        string ans("");

        for (int i = str.size() - 1; i > -1; --i) {
            if (str[i] == '(' && balancingFactor > 0) {
                --balancingFactor;
            }
            else ans += str[i];
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.minRemoveToMakeValid(s) << endl;
    }

    return 0;
}
