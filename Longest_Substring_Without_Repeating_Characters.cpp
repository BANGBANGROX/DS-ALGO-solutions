#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		int maxLength = 1;
		int left = 0;
		unordered_map<char, int> index;

		if (n == 0) return 0;

		for (int i = 0; i < n; ++i) {
			if (index.find(s[i]) == index.end()) {
				index[s[i]] = i;
				continue;
			}
			maxLength = max(i - left, maxLength);
			left = max(left, index[s[i]] + 1);
			index[s[i]] = i;
		}
		maxLength = max(n - left, maxLength);

		return maxLength;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		cout << solution.lengthOfLongestSubstring(s) << endl;
	}

	return 0;
}