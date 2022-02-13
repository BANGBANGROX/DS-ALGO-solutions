#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	bool judgeSquareSum(int c) {
		ll a = 0;
		ll b = sqrt(c);

		while (a * a <= b * b) {
			ll sum = a * a + b * b;
			if (sum == c) return true;
			else if (sum > c) --b;
			else ++a;
		}

		return false;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int c;
		cin >> c;

		Solution solution;
		if (solution.judgeSquareSum(c)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}