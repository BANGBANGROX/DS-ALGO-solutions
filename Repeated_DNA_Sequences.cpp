#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
	vector<string> ans;
	unordered_map<string, int> mp;
	int n = s.size();
	
	if (n < 10) return ans;

	int l = 0, r = 9;
	string seq = s.substr(l, 10);

	reverse(begin(seq), end(seq));

	while (r < n) {
		++mp[seq];
		++l;
		++r;
		seq.pop_back();
		if (r < n) seq = s[r] + seq;
	}

	for (pair<string, int> x : mp) {
		if (x.second > 1) {
			reverse(x.first.begin(), x.first.end());
			ans.push_back(x.first);
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		vector<string> ans = findRepeatedDnaSequences(s);
		for (string x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}