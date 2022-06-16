#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int longestStrChain(vector<string>& words) {
		sort(words.begin(), words.end(), [](string& a, string& b) {
			return a.size() < b.size();
			});

		unordered_map<string, int> distance;
		int ans = 1;

		for (string word : words) {
			int longest = 0;
			for (int i = 0; i < (int)word.size(); ++i) {
				string nextWord = word.substr(0, i) + word.substr(i + 1);
				longest = max(longest, distance[nextWord]);
			}
			distance[word] = 1 + longest;
			ans = max(ans, distance[word]);
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
		for (string& x : words) cin >> x;

		Solution solution;
		cout << solution.longestStrChain(words) << endl;
	}

	return 0;
}