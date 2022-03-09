#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minMovesToMakePalindrome(string s) {
		int n = s.size();
		int left = 0;
		int right = n - 1;
		int ans = 0;

		while (left < right) {
			int l = left;
			int r = right;
			while (s[l] != s[r]) --r;
			if (l == r) {
				swap(s[r], s[r + 1]);
				++ans;
				continue;
			}
			while (r < right) {
				swap(s[r], s[r + 1]);
				++ans;
				++r;
			}
			++left;
			--right;
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
		cout << solution.minMovesToMakePalindrome(s) << endl;
	}

	return 0;
}