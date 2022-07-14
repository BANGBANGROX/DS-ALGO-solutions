#include<bits/stdc++.h>
using namespace std;

class Solution {
	int operate(int a, int b, string op) {
		if (op.compare("+") == 0) {
			return a + b;
		}
		
		if (op.compare("-") == 0) {
			return a - b;
		}

		if (op.compare("*") == 0) {
			return a * b;
		}

		return a / b;
	}

public:
	int evalRPN(vector<string>& tokens) {
		stack<string> st;

		for (string& token : tokens) {
			if (isdigit(token[0]) || (token[0] == '-' && (int)token.size() > 1)) {
				st.push(token);
			}
			else {
				int b = stoi(st.top());
				st.pop();
				int a = stoi(st.top());
				st.pop();
				cout << operate(a, b, token) << endl;
				st.push(to_string(operate(a, b, token)));
			}
		}

		return stoi(st.top());
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<string> tokens(n);
		for (string& x : tokens) cin >> x;

		Solution solution;
		cout << solution.evalRPN(tokens) << endl;
	}

	return 0;
}