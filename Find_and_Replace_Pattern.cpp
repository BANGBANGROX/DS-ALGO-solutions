#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> ans;
		int m = pattern.size();

		for (string& word : words) {
			unordered_map<char, char> patternToWord;
			unordered_map<char, char> wordToPattern;
			int n = word.size();
			if (m != n) continue; 
			bool match = true;
			for (int i = 0; i < n; ++i) {
				if (patternToWord.find(pattern[i]) == patternToWord.end()) {
					if (wordToPattern.find(word[i]) != wordToPattern.end()) {
						match = false;
						break;
					}
					patternToWord[pattern[i]] = word[i];
					wordToPattern[word[i]] = pattern[i];
				}
				else {
					if (word[i] != patternToWord[pattern[i]]) {
						match = false;
						break;
					}
				}
			}
			if (match) ans.push_back(word);
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
		vector<string> words(n);
		for (string& word : words) cin >> word;
		string pattern;
		cin >> pattern;

		Solution solution;
		vector<string> ans = solution.findAndReplacePattern(words, pattern);
		for (string& word : ans) cout << word << " ";
		cout << endl;
	}

	return 0;
}