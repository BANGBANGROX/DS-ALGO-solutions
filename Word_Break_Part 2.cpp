#include<bits/stdc++.h>
using namespace std;

map<string, vector<string>> m;
set <string> dict;

vector<string> combine(vector<string> prev, string word) {
	for (int i = 0; i < prev.size(); ++i) {
		prev[i] += (" " + word);
	}
	return prev;
}

vector<string> wordBreakUtil(string s) {
	if (m.find(s) != m.end()) return m[s];

	vector<string> res;

	if (dict.find(s) != dict.end()) res.push_back(s);

	for (int i = 1; i < s.size(); ++i) {
		string subst = s.substr(i);
		if (dict.find(subst) != dict.end()) {
			string rem = s.substr(0, i);
			vector<string> prev = combine(wordBreakUtil(rem), subst);
			res.insert(res.end(), prev.begin(), prev.end());
		}
	}
	m[s] = res;
	
	return res;
}

vector<string> wordBreak(int n, vector<string>& dictionary, string s) {
	dict.clear();
	m.clear();
	dict.insert(dictionary.begin(), dictionary.end());

	return wordBreakUtil(s);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n;
		cin >> n;
		vector<string> dictionary;
		while (n--) {
			string t;
			cin >> t;
			dictionary.push_back(t);
		}

		vector<string> ans = wordBreak(n, dictionary, s);
		for (string x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}
