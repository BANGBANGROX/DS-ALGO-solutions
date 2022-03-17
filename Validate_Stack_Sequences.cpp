#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> st;
		int i = 0;
		int n = pushed.size();

		for (int num : pushed) {
			st.push(num);
			if (st.top() == popped[i]) {
				while (!st.empty() && i < n && st.top() == popped[i]) {
					++i;
					st.pop();
				}
				if (i == n) return true;
			}
		}

		while (!st.empty() && i < n) {
			if (st.top() != popped[i]) return false;
			st.pop();
			++i;
		}

		return st.empty() && i == n;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> pushed(n), popped(n);
		for (int& x : pushed) cin >> x;
		for (int& x : popped) cin >> x;

		Solution solution;
		if (solution.validateStackSequences(pushed, popped)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}