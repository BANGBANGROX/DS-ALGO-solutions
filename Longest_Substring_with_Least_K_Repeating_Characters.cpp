#include<bits/stdc++.h>
using namespace std;

class Solution {
	int longestSubstringUtil(string s, int start, int end, int k) {
		if (end < k) return 0;

		vector<int> count(26);

		for (int i = start; i < end; ++i) {
			++count[s[i] - 'a'];
		}

		for (int mid = start; mid < end; ++mid) {
			if (count[s[mid] - 'a'] >= k) continue;
			int midNext = mid + 1;
			while (midNext < end && count[s[midNext] - 'a'] < k) ++midNext;
			return max(longestSubstringUtil(s, start, mid, k), 
				longestSubstringUtil(s, midNext, end, k));
		}

		return (end - start);
	}

public:
	int longestSubstring(string s, int k) {
		int n = s.size();

		return longestSubstringUtil(s, 0, n, k);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		int k;
		cin >> k;

		Solution solution;
		cout << solution.longestSubstring(s, k) << endl;
	}

	return 0;
}