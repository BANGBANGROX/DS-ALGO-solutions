#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool checkPrime(string s) {
		int n = s.size();

		for (int i = 1; i < n; ++i) {
			string sub = s.substr(i - 1, 2);
			if (sub.compare("10") == 0 || sub.compare("11") == 0) return true;
		}

		return false;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		if (solution.checkPrime(s)) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}