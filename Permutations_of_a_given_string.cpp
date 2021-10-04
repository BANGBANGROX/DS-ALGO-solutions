#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<string>& ans, string& curr, string s, set<int>& pos) {
	if (curr.size() == s.size()) {
		ans.push_back(curr);
		return;
	}
    
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (pos.find(i) == pos.end()) {
			curr.push_back(s[i]);
			pos.insert(i);
			nextPermutation(ans, curr, s, pos);
			curr.pop_back();
			pos.erase(i);
		}
	}
}

vector<string> find_permutation(string s) {
	vector<string> ans;
	string curr("");
	set<int> pos;

	nextPermutation(ans, curr, s, pos);
	sort(ans.begin(), ans.end());

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		vector<string> ans = find_permutation(s);

		for (string x : ans) cout << x << " ";
	}

	return 0;
}