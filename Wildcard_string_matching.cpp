#include<bits/stdc++.h>
using namespace std;

bool matchUtil(int i, int j, int n, int m, string& w, string& p) {
	if (i == n && j != m) return false;

	if (i == n && j == m) return true;

	if (w[j] == '?' || p[i] == w[j]) return matchUtil(i + 1, j + 1, n, m, w, p);

	if (w[j] == '*') {
		for (int k = i; k < n; ++k) {
			if (matchUtil(k, j + 1, n, m, w, p)) return true;
		}
	}

	return false;
}

bool match(string w, string p) {
	w += '#';
	p += '#';

	int n = p.size(), m = w.size();

	return matchUtil(0, 0, n, m, w, p);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		string w, p;
		cin >> w >> p;

		if (match(w, p)) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}
