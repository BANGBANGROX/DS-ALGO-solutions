#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '[') {
                st.push(s[i]);
            }
            else if (!st.empty() && st.top() == '[') {
                st.pop();
            }
        }

        return (st.size() + 1) / 2;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.minSwaps(s) << endl;
    }

    return 0;
}