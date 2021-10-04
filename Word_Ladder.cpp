#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> dict(wordList.begin(), wordList.end());

	if (dict.find(endWord) == dict.end()) return 0;

	queue<string> q;
	int ladder = 1;

	q.push(beginWord);

	while (!q.empty()) {
		++ladder;
		int level = q.size();
		while (level--) {
			string curr = q.front();
			q.pop();
			int n = curr.size();
			for (int i = 0; i < n; ++i) {
				string temp = curr;
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					temp[i] = ch;
					if (temp == curr) continue;
					if (temp == endWord) return ladder;
					if (dict.find(temp) != dict.end()) {
						q.push(temp);
						dict.erase(temp);
					}
				}
			}
		}
	}

	return 0;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		int n;
		cin >> n;
		vector<string> wordList(n);
		for (string& x : wordList) cin >> x;

		cout << ladderLength(s1, s2, wordList) << endl;
	}

	return 0;
}