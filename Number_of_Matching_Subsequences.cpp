#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		unordered_map<char, vector<int>> indexOfCharacters;
		int n = s.size();
		int ans = 0;
		
		for (int i = 0; i < n; ++i) {
			indexOfCharacters[s[i]].push_back(i);
		}

		for (string& word : words) {
			int previousPosition = -1;
			bool found = true;
			for (char ch : word) {
				if (indexOfCharacters.find(ch) == indexOfCharacters.end()) {
					found = false;
					break;
				}
				int nextIndex = upper_bound(indexOfCharacters[ch].begin(), indexOfCharacters[ch].end(),
					previousPosition) - indexOfCharacters[ch].begin();
				if (nextIndex == (int)indexOfCharacters[ch].size()) {
					found = false;
					break;
				}
				previousPosition = indexOfCharacters[ch][nextIndex];
			}
			if (found) ++ans;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		int n;
		cin >> n;
		vector<string> words(n);
		for (string& x : words) cin >> x;

		Solution solution;
		cout << solution.numMatchingSubseq(s, words) << endl;
	}

	return 0;
}