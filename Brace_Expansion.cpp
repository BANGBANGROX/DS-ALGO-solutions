#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> expand(string s) {
		int n = s.size();
		vector<string> ans;
		string previousString("");

		ans.push_back("");

		for (int i = 0; i < n; ++i) {
			if (s[i] == '{') {
				++i;
				for (string& x : ans) x += previousString;
				previousString = "";
				vector<char> current;
				while (i < n && s[i] != '}') {
					if (s[i] == ',') {
						++i;
						continue;
					}
					current.push_back(s[i]);
					++i;
				}
				vector<string> newAns;
				for (string& x : ans) {
					for (char c : current) {
						newAns.push_back(x + c);
					}
				}
				ans = newAns;
			}
			else previousString += s[i];
		}

		for (string& x : ans) x = x + previousString;

		sort(ans.begin(), ans.end());

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
		vector<string> ans = solution.expand(s);
		for (string& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}