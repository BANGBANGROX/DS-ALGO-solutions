#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
	bool check(unordered_map<char, int>& map1, unordered_map<char, int>& map2) {
		for (const pair<char, int>& x : map1) {
			if (map2.find(x.first) == map2.end()) return false;
			if (map2[x.first] != x.second) return false;
		}

		return true;
	}

public:
	bool checkInclusion(string s1, string s2) {
		unordered_map<char, int> map1;
		unordered_map<char, int> map2;
		int m = s1.size();
		int n = s2.size();
		int l = 0;
		int r = m - 1;

		if (m > n) return false;

		for (char& c : s1) {
			++map1[c];
		}

		for (int i = 0; i < m; ++i) {
			++map2[s2[i]];
		}

		while (r < n) {
			if (check(map1, map2)) return true;
			--map2[s2[l]];
			++l;
			++r;
			if (r < n) ++map2[s2[r]];
		}

		return false;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;

		Solution solution;
		if (solution.checkInclusion(s1, s2)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}