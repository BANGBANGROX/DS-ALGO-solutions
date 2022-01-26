#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool isOpenBracket(char ch) {
		return ch == '(' || ch == '{' || ch == '[';
	}

public:
	bool isValid(string s) {
		int n = s.size();
		stack<char> st;

		for (int i = 0; i < n; ++i) {
			if (isOpenBracket(s[i])) {
				st.push(s[i]);
				continue;
			}
			if (st.empty()) return false;
			char openBracket = '\0';
			char topBracket = st.top();
			st.pop();
			if (s[i] == ']') openBracket = '[';
			if (s[i] == '}') openBracket = '{';
			if (s[i] == ')') openBracket = '(';
			if (topBracket != openBracket) return false;
		}

		return st.empty();
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		if (solution.isValid(s)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}