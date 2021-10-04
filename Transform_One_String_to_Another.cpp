#include<bits/stdc++.h>
using namespace std;

int minSteps(string s, string t) {
	int n = s.size(), m = t.size();
	int freq[26] = { 0 };

	for (int i = 0; i < n; ++i) ++freq[s[i] - 'a'];
	for (int j = 0; j < m; ++j) --freq[t[j] - 'a'];

	for (int i = 0; i < 26; ++i) {
		if (freq[i] != 0) return -1;
	}

	int res = 0, ind1 = n - 1, ind2 = m - 1;

	while (ind1 >= 0) {
		if (s[ind1] != t[ind2]) ++res;
		else --ind2;
		--ind1;
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s, t;
		cin >> s >> t;

		cout << minSteps(s, t) << endl;
	}

	return 0;
}
