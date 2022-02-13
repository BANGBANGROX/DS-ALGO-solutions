#include<bits/stdc++.h>
using namespace std;

class Solution {
	int sumDigits(int num) {
		int ans = 0;

		while (num > 0) {
			ans += num % 10;
			num /= 10;
		}

		return ans;
	}

public:
	int addDigits(int num) {
		int ans = sumDigits(num);

		while (ans >= 10) {
			ans = sumDigits(ans);
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}