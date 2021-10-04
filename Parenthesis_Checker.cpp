#include<bits/stdc++.h>
using namespace std;

bool isOpen(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

bool ispar(string s) {
    int n = s.size();
    stack<char> par;

    for (int i = 0; i < n; ++i) {
        if (isOpen(s[i])) {
            par.push(s[i]);
            continue;
        }
        else {
            char openPar = '(';
            if (s[i] == '}') openPar = '{';
            else if (s[i] == ']') openPar = '[';
            while (!par.empty() && par.top() != openPar) {
                if (par.top() != openPar && isOpen(par.top())) return false;
                par.pop();
            }
            if (par.empty()) return false;
            par.pop();
        }
    }
   
    return par.empty();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        cout << ispar(s) << endl;
    }

    return 0;
}