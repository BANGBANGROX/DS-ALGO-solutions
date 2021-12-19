#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int idx;
    
    string decodeStringUtil(string s) {
        string ans("");

        while (idx < s.size() && s[idx] != ']') {
            if (isalpha(s[idx])) {
                ans += s[idx];
            }
            else if (s[idx] >= '0' && s[idx] <= '9') {
                ans += decodeInt(s);
            }
            ++idx;
        }

        return ans;
    }

    string decodeInt(string s) {
        string ans(""), numString("");

        while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
            numString += s[idx];
            ++idx;
        }

        int num = stoi(numString);
        string dec = decodeStringUtil(s);

        for (int i = 0; i < num; ++i) {
            ans += dec;
        }

        return ans;
    }

public:
    string decodeString(string s) {
        idx = 0;
        
        return decodeStringUtil(s);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.decodeString(s) << endl;
    }

    return 0;
}