#include<bits/stdc++.h>
using namespace std;

bool check(const vector<int>& hash, const vector<int>& key) {
	for (int i = 0; i < 26; ++i) {
		if (hash[i] < key[i]) return false;
	}

	return true;
}

string smallestWindow(string s, string p) {
	int n = s.size(), m = p.size(), l = 0, r = 0, minLen = INT_MAX; // We consider a window of l...r-1
	string ans = "-1";

	vector<int> hash(26), target(26);
	for (int i = 0; i < m; ++i) ++target[p[i] - 'a'];

	while (r <= n) {
		if (!check(hash, target)) { // If no match found we need to increase the size i.e l...r+1
			if (r == n) break;
			++hash[s[r] - 'a'];
			++r;
			continue;
		}
		if (r - l < minLen) { // Match found then check if the size is minimum if it is then update ans
			minLen = r - l;
			ans = s.substr(l, r - l);
		}
		--hash[s[l] - 'a']; // Decrease the window size to l+1...r-1
		++l;
	}

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s, p;
		cin >> s >> p;

		cout << smallestWindow(s, p) << endl;
	}

	return 0;
}