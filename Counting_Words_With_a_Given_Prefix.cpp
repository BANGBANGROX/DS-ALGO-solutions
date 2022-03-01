#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int prefixCount(vector<string>& words, string pref) {
		int ans = 0;

		for (string& word : words) {
			if (pref.size() > word.size()) continue;
			bool match = true;
			for (int i = 0; i < pref.size(); ++i) {
				if (pref[i] != word[i]) {
					match = false;
					break;
				}
			}
			if (match) ++ans;
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
		vector<string> words;
		for (string& word : words) cin >> word;
		string pref;
		cin >> pref;

		Solution solution;
		cout << solution.prefixCount(words, pref) << endl;
	}

	return 0;
}