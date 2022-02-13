#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	ll smallestNumber(ll num) {
		if (num == 0) return 0;

		bool sign = (num > 0);
		num = abs(num);
		string numString = to_string(num);

		sort(numString.begin(), numString.end());

		if (sign) {
			int zeroes = 0;
			int indexOfNonZero = -1;
			string ans("");

			for (int i = 0; i < numString.size(); ++i) {
				if ((numString[i] - '0') > 0) {
					indexOfNonZero = i;
					break;
				}
				++zeroes;
			}

			ans += numString[indexOfNonZero];

			while (zeroes > 0) {
				ans += '0';
				--zeroes;
			}

			for (int i = indexOfNonZero + 1; i < numString.size(); ++i) {
				ans += numString[i];
			}

			return stoll(ans);
		}

		reverse(numString.begin(), numString.end());

		return -1 * stoll(numString);

	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		long long n;
		cin >> n;

		Solution solution;
		cout << solution.smallestNumber(n) << endl;
	}

	return 0;
}