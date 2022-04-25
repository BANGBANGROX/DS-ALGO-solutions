#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string minimizeResult(string expression) {
		int leftIndex = -1;
		int rightIndex = -1;
		int plusIndex = -1;
		int n = expression.size();
		int result = INT_MAX;
		string ans("");

		for (int i = 0; i < n; ++i) {
			if (expression[i] == '+') {
				plusIndex = i;
				break;
			}
		}

		for (int i = 0; i < plusIndex; ++i) {
			for (int j = plusIndex + 1; j < n; ++j) {
				// Partition left side
				string n1String = expression.substr(0, i);
				string n2String = expression.substr(i, plusIndex - i);
				// Partition right side
				string n3String = expression.substr(plusIndex + 1, j - plusIndex);
				string n4String = expression.substr(j + 1);
				int n1 = n1String.empty() ? 1 : stoi(n1String);
				int n2 = stoi(n2String);
				int n3 = stoi(n3String);
				int n4 = n4String.empty() ? 1 : stoi(n4String);
				int value = n1 * (n2 + n3) * n4;
				if (result > value) {
					result = value;
					leftIndex = i;
					rightIndex = j;
				}
			}
		}

		ans += expression.substr(0, leftIndex);
		ans += '(';
		ans += expression.substr(leftIndex, rightIndex - leftIndex + 1);
		ans += ')';
		ans += expression.substr(rightIndex + 1);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string expression;
		cin >> expression;

		Solution solution;
		cout << solution.minimizeResult(expression) << endl;
	}

	return 0;
}