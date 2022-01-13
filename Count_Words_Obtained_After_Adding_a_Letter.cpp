#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
	int computeMask(string s) {
		int mask = 0;

		for (char ch : s) {
			mask += (1 << (ch - 'a'));
		}

		return mask;
	}

public:
	int wordCount(vector<string>& startWords, vector<string>& targetWords) {
		unordered_map<int, bool> mp;
		int ans = 0;

		for (string word : startWords) {
			int mask = computeMask(word);
			mp[mask] = true;
		}

		for (string word : targetWords) {
			int mask = computeMask(word);
			for (int i = 0; i < 26; ++i) {
				if ((mask & (1 << i)) > 0) {
					mask -= (1 << i);
					if (mp.find(mask) != mp.end()) {
						++ans;
						break;
					}
					mask += (1 << i);
				}
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<string> startWords(n);
		for (int i = 0; i < n; ++i) {
			cin >> startWords[i];
		}
		int m;
		cin >> m;
		vector<string> targetWords(m);
		for (int i = 0; i < m; ++i) {
			cin >> targetWords[i];
		}

		Solution solution;
		cout << solution.wordCount(startWords, targetWords) << endl;
	}

	return 0;
}