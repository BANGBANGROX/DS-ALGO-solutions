#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int calPoints(vector<string>& ops) {
		stack<int> s;
		int ans = 0;

		for (string op : ops) {
			if (op.compare("+") == 0) {
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(b);
				s.push(a);
				s.push(a + b);
			}
			else if (op.compare("D") == 0) {
				int a = s.top();
				s.push(2 * a);
			}
			else if (op.compare("C") == 0) {
				s.pop();
			}
			else s.push(stoi(op));
		}

		while (!s.empty()) {
			ans += s.top();
			s.pop();
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<string> ops(n);
		for (string& x : ops) cin >> x;

		Solution solution;
		cout << solution.calPoints(ops) << endl;
	}

	return 0;
}