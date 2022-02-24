#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		if (num.size() <= k) return "0";

		if (k == 0) return num;

		int n = num.size();
		string ans("");
		stack<char> st;

		for (int i = 0; i < n; ++i) {
			while (!st.empty() && k > 0 && num[i] < st.top()) {
				--k;
				st.pop();
			}
			st.push(num[i]);
			if (st.size() == 1 && st.top() == '0') st.pop();
		}

		while (k > 0 && !st.empty()) {
			--k;
			st.pop();
		}

		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}

		reverse(ans.begin(), ans.end());

		if (ans.empty()) ans = "0";

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string num;
		cin >> num;
		int k;
		cin >> k;

		Solution solution;
		cout << solution.removeKdigits(num, k) << endl;
	}

	return 0;
}