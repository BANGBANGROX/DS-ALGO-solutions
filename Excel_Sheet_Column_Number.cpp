#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int titleToNumber(string columnTitle) {
		int ans = 0;

		for (char ch : columnTitle) {
			ans = ans * 26 + (ch - 'A' + 1);
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string coloumnTitle;
		cin >> coloumnTitle;

		Solution solution;
		cout << solution.titleToNumber(coloumnTitle) << endl;
	}

	return 0;
}