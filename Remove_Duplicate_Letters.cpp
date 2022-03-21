// https://leetcode.com/problems/remove-duplicate-letters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		string ans("");
		vector<int> count(26);
		vector<bool> visited(26);

		for (char ch : s) {
			++count[ch - 'a'];
		}

		for (char ch : s) {
			--count[ch - 'a'];
			if (!visited[ch - 'a']) {
				while (!ans.empty() && ans.back() > ch && count[ans.back() - 'a'] > 0) {
					visited[ans.back() - 'a'] = false;
					ans.pop_back();
				}
				ans.push_back(ch);
				visited[ch - 'a'] = true;
			}
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

		Solution solution;
		cout << solution.removeDuplicateLetters(s) << endl;
	}

	return 0;
}