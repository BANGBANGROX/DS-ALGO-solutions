#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> ans;
	unordered_map<string, vector<string>> mp;

	for (string s : strs) {
		string str = s;
		sort(str.begin(), str.end());
		mp[str].push_back(s);
	}

	for (const pair<string, vector<string>>& x : mp) {
		ans.push_back(x.second);
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<string> strs(n);
		for (string& x : strs) cin >> x;

		vector<vector<string>> ans = groupAnagrams(strs);
		for (const vector<string>& x : ans) {
			for (const string& y : x) cout << y << " ";
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
