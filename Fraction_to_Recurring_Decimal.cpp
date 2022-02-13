#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
	typedef long long ll;
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";

		bool sign = ((numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0));
		ll num = abs(numerator);
		ll den = abs(denominator);
		ll remainder = num % den;
		string res = to_string(num / den);
		unordered_map<int, int> remainders;
		
		if (!sign) res = "-" + res;

		if (remainder == 0) return res;

		res += '.';

		while (remainder > 0) {
			if (remainders.find(remainder) != remainders.end()) {
				res.insert(remainders[remainder], "(");
				res += ')';
				break;
			}
			remainders[remainder] = res.size();
			remainder *= 10;
			res += to_string(remainder / den);
			remainder %= den;
		}

		return res;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int numerator, denominator;
		cin >> numerator >> denominator;

		Solution solution;
		cout << solution.fractionToDecimal(numerator, denominator) << endl;
	}

	return 0;
}