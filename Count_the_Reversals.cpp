#include<bits/stdc++.h>
using namespace std;

int countRev(string s) {
	int n = s.size();

	if (n % 2 == 1) return -1;

	stack<char> st;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '}' && !st.empty()) {
			if (st.top() == '{') st.pop();
			else st.push(s[i]);
		}
		else st.push(s[i]);
	}

	int left = 0, rightPlusLeft = st.size();

	while (!st.empty() && st.top() == '{') {
		++left;
		st.pop();
	}

	int res = rightPlusLeft / 2 + left % 2; 

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << countRev(s) << endl;
	}

	return 0;
}