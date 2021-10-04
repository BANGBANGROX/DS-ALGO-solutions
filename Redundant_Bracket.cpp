#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
	return ch == '*' || ch == '+' || ch == '/' || ch == '-' || ch == '^';
}

bool containsRedundant(string s) {
	stack<char> st;
	int n = s.size();

	for (int i = 0; i < n; ++i) {
		if (s[i] != ')') {
			st.push(s[i]);
			continue;
		}
		char top = st.top();
		bool res = true;
		while (!st.empty() && top != '(') {
			if (isOperator(top)) res = false;
			top = st.top();
			st.pop();
		}
		if (res) return true;
	}

	return false;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << containsRedundant(s) << endl;
	}

	return 0;
}