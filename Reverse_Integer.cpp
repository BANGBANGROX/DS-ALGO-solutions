#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		if (x == 0 || x == INT_MIN || x == INT_MAX) return 0;

		bool sign = (x > 0);
		int revNum = 0;

		x = abs(x);
		
		while (x > 0) {
			int dig = x % 10;
			if (revNum > INT_MAX / 10) return 0;
			if (revNum / 10 == INT_MAX / 10 && dig > INT_MAX % 10) return 0;
			revNum = revNum * 10 + dig;
			x /= 10;
		}

		if (!sign) revNum *= -1;

		return revNum;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int x;
		cin >> x;

		Solution solution;
		cout << solution.reverse(x) << endl;
	}

	return 0;
}