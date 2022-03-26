// https://leetcode.com/problems/broken-calculator/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	const int inf = 1e9;
public:
	int brokenCalc(int startValue, int target) {
		if (startValue == 0 || target == 0) return inf;

		if (startValue >= target) return startValue - target;

		if (2 * startValue >= target) {
			if (2 * (startValue - 1) >= target) return brokenCalc(startValue - 1, target) + 1;
			return 2 * startValue - target + 1;
		}

		return (target % 2 == 1 ? brokenCalc(startValue, target / 2 + 1) + 2 : 
			brokenCalc(startValue, target / 2) + 1);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int startValue, target;
		cin >> startValue >> target;

		Solution solution;
		cout << solution.brokenCalc(startValue, target) << endl;
	}

	return 0;
}