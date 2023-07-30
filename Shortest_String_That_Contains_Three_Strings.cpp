#include<bits/stdc++.h>
using namespace std;

class Solution {
    string getLexSmallerString(string a, string b) {
        int m = (int)a.size();
        int n = (int)b.size();

        if (m < n) return a;

        if (m == n) return a.compare(b) < 0 ? a : b;

        return b;
    }

    string addTwoStrings(string& a, string& b) {
        if (b.find(a) != string::npos) return b;

        int m = (int)a.size();
        int n = (int)b.size();

        for (int i = 0; i < m; ++i) {
            string s1 = a.substr(i);
            string s2 = b.substr(0, min(m - i, n));
            if (s1.compare(s2) == 0) return a + b.substr(min(m - i, n));
        }

        return a + b;
    }

    string minimumStringHandler(string& a, string& b, string& c) {
        string s1 = addTwoStrings(a, b);
        string s2 = addTwoStrings(b, a);
        string min1 = getLexSmallerString(addTwoStrings(s1, c), addTwoStrings(c, s1));
        string min2 = getLexSmallerString(addTwoStrings(s2, c), addTwoStrings(c, s2));

        return getLexSmallerString(min1, min2);
    }

public:
    string minimumString(string a, string b, string c) {
        string s1 = minimumStringHandler(a, b, c);
        string s2 = minimumStringHandler(b, c, a);
        string s3 = minimumStringHandler(c, a, b);

        return getLexSmallerString(getLexSmallerString(s1, s2), s3);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string a, b, c;
        cin >> a >> b >> c;

        Solution solution;
        cout << solution.minimumString(a, b, c);
    }

    return 0;
}