#include<bits/stdc++.h>
using namespace std;

void computeLPS(string s, vector<int>& lps) {
	int n = s.size();
	lps.resize(n);
	int i = 1, len = 0;

	while (i < n) {
		if (s[i] == s[len]) {
			++len;
			lps[i] = len;
			++i;
		}
		else {
			if (len != 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				++i;
			}
		}
	}
}

vector <int> search(string p, string t) {
	vector<int> res;
	int n = t.size();
	int m = p.size();
	int i = 0, j = 0;
	vector<int> lps;
	computeLPS(p, lps);

	while (i < n) {

		if (t[i] == p[j]) {
			++i;
			++j;
		}

		if (j == m) {
			res.push_back(i - j + 1);
			j = lps[j - 1];
		}

		else if (j < m && t[i] != p[j]) {
			if (j != 0) j = lps[j - 1];
			else ++i;
		}
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string p, t;
		cin >> p >> t;

		vector<int> ans = search(p, t);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}