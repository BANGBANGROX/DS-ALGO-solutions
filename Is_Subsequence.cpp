#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
	int n = s.size(), m = t.size(), sPos = 0, tPos = 0;

	while (sPos < n && tPos < m) {
		if (s[sPos] == t[tPos]) ++sPos;
		++tPos;
	}

	return sPos == n;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s, t;
		cin >> s >> t;

		if (isSubsequence(s, t)) cout << "Subsequence\n";
		else cout << "Not a subsequence\n";
	}

	return 0;
}
