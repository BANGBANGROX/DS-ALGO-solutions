#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
	for (int i = 0; i < 26; ++i) {
		if (a[i] != b[i]) return false;
	}

	return true;
}

bool isShuffeled(string s1, string s2) {
	int n = s1.size(), m = s2.size();
	vector<int> freqs1(26), freqs2(26);

	if (n > m) return false;

	for (int i = 0; i < n; ++i) {
		++freqs1[s1[i] - 'a'];
		++freqs2[s2[i] - 'a'];
	}

	if (compare(freqs1, freqs2)) return true;

	int l = 0, r = n - 1;
	--freqs2[s2[l] - 'a'];
	++l;
	++r;
	if (r < m) ++freqs2[s2[r] - 'a'];

	while (r < m) {
		if (compare(freqs1, freqs2)) return true;
		--freqs2[s2[l] - 'a'];
		++l;
		++r;
		if (r < m) ++freqs2[s2[r] - 'a'];
	}

	return false;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;

		if (isShuffeled(s1, s2)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}