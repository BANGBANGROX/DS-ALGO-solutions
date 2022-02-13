#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	int divide(int dividend, int divisor) {
		ll longDividend = abs((ll)dividend);
		ll longDivisor = abs((ll)divisor);
		int sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ? -1 : 1;
		ll quotient = 0;
		ll temp = 0;

		for (int i = 31; i >= 0; --i) {
			if (temp + (longDivisor << i) <= longDividend) {
				temp += (longDivisor << i);
				quotient |= (1LL << i);
			}
		}
        
		ll ans = sign * quotient;

		if (ans > INT_MAX) return INT_MAX;
		
		if (ans < INT_MIN) return INT_MIN;

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int dividend, divisor;
		cin >> dividend >> divisor;

		Solution solution;
		cout << solution.divide(dividend, divisor) << endl;
	}

	return 0;
}