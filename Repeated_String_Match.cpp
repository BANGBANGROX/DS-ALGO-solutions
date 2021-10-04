#include<bits/stdc++.h>
using namespace std;

bool isSubstring(string a, string b) {
	int n = a.size();
	int m = b.size();

	for (int i = 0; i <= n - m; ++i) {
		bool flag = true;
		for (int j = 0; j < m; ++j) {
			if (a[i + j] != b[j]) {
				flag = false;
				break;
			}
		}
		if (flag) return true;
	}

	return false;
}

int repeatedStringMatch(string s, string t) {
	string tp = s;
	int ans = 1;

	while (s.size() < t.size()) {
		s += tp;
		++ans;
	}

	if (isSubstring(s, t)) return ans;

	if (isSubstring(s + tp, t)) return ans + 1;

	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s, t;
		cin >> s >> t;

		cout << repeatedStringMatch(s, t) << endl;
	}

	return 0;
}