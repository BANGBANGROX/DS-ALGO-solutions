#include<bits/stdc++.h>
using namespace std;

int minIndexChar(string s, string p) {
	int res = INT_MAX, n = s.size(), m = p.size();
	vector<int> firstPos(26, -1);

	for (int i = 0; i < n; ++i) {
		if (firstPos[s[i] - 'a'] == -1) firstPos[s[i] - 'a'] = i;
	}

	for (int i = 0; i < m; ++i) {
		if (firstPos[p[i] - 'a'] != -1) {
			res = min(res, firstPos[p[i] - 'a']);
		}
	}
	if (res == INT_MAX) res = -1;

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s, p;
		cin >> s >> p;

		cout << minIndexChar(s, p) << endl;
	}

	return 0;
}