#include<bits/stdc++.h>
using namespace std;

void lastIndex(string s, vector<int>& last) {
	int n = s.size();

	for (int i = 0; i < n; ++i) {
		last[s[i]] = i;
	}
}

vector<int> matching(string txt, string pat) {
	int n = txt.size(), m = pat.size();
	vector<int> last(256, -1);
	vector<int> res;

	lastIndex(pat, last);

	int i = 0;

	while (i <= (n - m)) {
		int j = m - 1;
		while (j >= 0 && pat[j] == txt[i + j]) --j;
		if (j < 0) {
			res.push_back(i);
			if (i + m < n) i += (m - last[txt[i + m]]);
			else ++i;
		}
		else {
			i += max(1, j - last[txt[i + j]]);
		}
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string txt, pat;
		cin >> txt >> pat;

		vector<int> res = matching(txt, pat);

		for (int x : res) cout << x << " ";
		cout << endl;
	}

	return 0;
}