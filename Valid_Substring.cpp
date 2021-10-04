#include<bits/stdc++.h>
using namespace std;

int findMaxLen(string s) {
	int n = s.size(), maxLen = 0;
	stack<int> st;
	st.push(-1);

	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			st.push(i);
			continue;
		}
		if (!st.empty()) st.pop();
		if (!st.empty()) {
			maxLen = max(maxLen, i - st.top());
		}
		else st.push(i);
	}

	return maxLen;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		cout << findMaxLen(s) << endl;
	}

	return 0;
}
