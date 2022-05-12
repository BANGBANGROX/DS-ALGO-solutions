#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removeDuplicates(string s, int k) {
		stack<int> st;
		int n = s.size();
		string ans("");
		vector<int> count(n, 1);

		st.push(0);

		for (int i = 1; i < n; ++i) {
			if (!st.empty()) {
				if (s[st.top()] == s[i]) count[i] = count[st.top()] + 1;
			}
			st.push(i);
			if (count[i] == k) {
				for (int i = 0; i < k; ++i) {
					st.pop();
				}
			}
		}

		while (!st.empty()) {
			ans += s[st.top()];
			st.pop();
		}

		reverse(ans.begin(), ans.end());

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		int k;
		cin >> s >> k;

		Solution solution;
		cout << solution.removeDuplicates(s, k) << endl;
	}

	return 0;
}