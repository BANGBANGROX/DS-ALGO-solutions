#include<bits/stdc++.h>
using namespace std;

bool dictionaryContains(string word, vector<string>& dict) {
	int n = dict.size();

	for (int i = 0; i < n; ++i) {
		if (dict[i].compare(word) == 0) {
			return true;
		}
	}

	return false;
}

bool wordBreak(string s, vector<string>& dict) {
	int n = s.size();
	vector<bool> dp(n);
	vector<int> matchedIndex;
	matchedIndex.push_back(-1);

	for (int i = 0; i < n; ++i) {
		int msize = matchedIndex.size();
		bool res = 0;
		for (int j = msize - 1; j > -1; --j) {
			string word = s.substr(matchedIndex[j] + 1, i - matchedIndex[j]);
			if (dictionaryContains(word, dict)) {
				res = 1;
				break;
			}
		}
		dp[i] = res;
		if (dp[i]) matchedIndex.push_back(i);
	}

	return dp[n - 1];
}

int main() {
	int n;
	cin >> n;
	vector<string> dict;
	while (n--) {
		string a;
		cin >> a;
		dict.push_back(a);
	}
	string s;
	cin >> s;

	cout << wordBreak(s, dict) << endl;
	
	return 0;
}
