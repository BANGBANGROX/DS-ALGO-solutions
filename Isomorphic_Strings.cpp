#include<bits/stdc++.h>
using namespace std;

bool areIsomorphic(string s, string t) {
	int n = s.size(), m = t.size();

	if (m != n) return false;

	vector<int> freqS(26), freqT(26);

	for (int i = 0; i < n; ++i) {
		++freqS[s[i] - 'a'];
		++freqT[t[i] - 'a'];
	}

	for (int i = 0; i < n; ++i) {
		if (freqS[s[i] - 'a'] != freqT[t[i] - 'a']) return false;
	}

	return true;
}

int main() {
	int T;
	cin >> T;
	
	while (T--) {
		string s, t;
		cin >> s >> t;

		if (areIsomorphic(s, t)) cout << "Isomorphic\n";
		else cout << "Not isomorphic\n";
	}

	return 0;
}
