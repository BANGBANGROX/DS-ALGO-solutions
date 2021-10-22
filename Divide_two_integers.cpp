#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
	int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1, q = 0, temp = 0;
	dividend = abs(dividend);
	divisor = abs(divisor);

	for (int i = 31; i > -1; --i) {
		if (temp + (divisor << i) <= dividend) {
			temp += divisor << i;
			q |= (1 << i);
		}
	}

	if (sign == -1) q *= -1;

	return q;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int dividend, divisor;
		cin >> dividend >> divisor;

		cout << divide(dividend, divisor) << endl;
	}

	return 0;
}
