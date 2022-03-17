#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		string ans("");
		stack<string> st;
		int n = path.size();
		
		for (int i = 0; i < n; ++i) {
			string intermediate("");
			while (i < n && path[i] != '/') {
				intermediate += path[i];
				++i;
			}
			if (intermediate.compare("..") == 0) {
				if (!st.empty()) st.pop();
			}
			else if (intermediate.size() > 0 && !(intermediate.compare(".") == 0)) st.push(intermediate);
		}

		while (!st.empty()) {
			ans = "/" + st.top() + ans;
			st.pop();
		}

		return ans.empty() ? "/" : ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string path;
		cin >> path;

		Solution solution;
		cout << solution.simplifyPath(path) << endl;
	}

	return 0;
}