#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& f1, vector<int>& f2) {
	for (int i = 0; i < 26; ++i) {
		if (f1[i] != f2[i]) return false;
	}

	return true;
}

vector<int> findAnagrams(string s, string p) {
	int n = s.size(), m = p.size();
	vector<int> pFreq(26), freq(26), res;

	if (n < m) return res;

	for (int i = 0; i < m; ++i) {
		++pFreq[p[i] - 'a'];
		++freq[s[i] - 'a'];
	}

	int l = 0, r = m - 1;

	while (l < n && r < n) {
		if (check(pFreq, freq)) {
			res.push_back(l);
		}
		--freq[s[l] - 'a'];
		++l;
		++r;
		if (r < n) ++freq[s[r] - 'a'];
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s, p;
		cin >> s >> p;

		vector<int> ans = findAnagrams(s, p);
		for (int x : ans) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}