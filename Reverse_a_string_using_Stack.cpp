#include<bits/stdc++.h>
using namespace std;

char* reverse(char* s, int n) {
	stack<char> st;
	int ind = 0;

	for (int i = 0; i < n; ++i) st.push(s[i]);

	while (!st.empty()) {
		s[ind] = st.top();
		++ind;
		st.pop();
	}

	return s;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		char* s = new char[n];
		for (int i = 0; i < n; ++i) cin >> s[i];

		char* reverseS = reverse(s, n);
		for (int i = 0; i < n; ++i) cout << reverseS[i];
		cout << endl;
	}

	return 0;
}
