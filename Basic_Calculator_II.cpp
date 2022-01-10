#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size(), currentNumber = 0;
        char operation = '+';
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                currentNumber = currentNumber * 10 + (s[i] - '0');
            }
            if (!isdigit(s[i]) && !iswspace(s[i]) || i == n - 1) {
                if (operation == '-') {
                    st.push(-1 * currentNumber);
                }
                if (operation == '+') {
                    st.push(currentNumber);
                }
                if (operation == '*') {
                    int a = st.top();
                    st.pop();
                    st.push(a * currentNumber);
                }
                if (operation == '/') {
                    int a = st.top();
                    st.pop();
                    st.push(a / currentNumber);
                }
                currentNumber = 0;
                operation = s[i];
            }
        }
        
        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
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

        Solution obj;
        cout << obj.calculate(s) << endl;
    }

    return 0;
}