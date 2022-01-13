#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string ans("");
		vector<int> unused, factorial(n + 1);

		factorial[0] = 1;

		for (int i = 1; i <= n; ++i) {
			unused.push_back(i);
			factorial[i] = i * factorial[i - 1];
		}

		--k;

		while (n > 0) {
			int partLength = factorial[n] / n;
			int i = k / partLength;
			ans += to_string(unused[i]);
			unused.erase(unused.begin() + i);
			--n;
			k = k % partLength;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n >> k;

		Solution solution;
		cout << solution.getPermutation(n, k) << endl;
	}

	return 0;
}