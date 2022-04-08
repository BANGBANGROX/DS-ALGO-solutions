#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool isSubsequence(string& s, string& p) {
		int m = s.size();
		int n = p.size();
		int i = 0;
		int j = 0;

		if (m < n) return false;

		while (i < m) {
			if (j == n) return true;
			if (s[i] == p[j]) ++j;
			++i;
		}

		return j == n;
	}

	bool check(string& s, string& p, vector<int>& removable, int k) {
		string newS("");
		vector<char> removed;
		int n = s.size();
		
		for (int i = 0; i < k; ++i) {
			removed.push_back(s[removable[i]]);
			s[removable[i]] = '#';
		}

		reverse(removed.begin(), removed.end());

		bool ans = isSubsequence(s, p);

		for (int i = 0; i < k; ++i) {
			s[removable[i]] = removed.back();
			removed.pop_back();
		}

		return ans;
	}

public:
	int maximumRemovals(string s, string p, vector<int>& removable) {
		int l = 1;
		int r = removable.size();
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (check(s, p, removable, mid)) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s, p;
		cin >> s >> p;
		int n;
		cin >> n;
		vector<int> removable(n);
		for (int& x : removable) cin >> x;

		Solution solution;
		cout << solution.maximumRemovals(s, p, removable) << endl;
	}

	return 0;
}