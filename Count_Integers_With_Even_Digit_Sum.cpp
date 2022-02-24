#include<bits/stdc++.h>
using namespace std;

class Solution {
	int digitSum(int num) {
		int sum = 0;

		while (num > 0) {
			sum += (num % 10);
			num /= 10;
		}

		return sum;
	}

public:
	int countEven(int num) {
		int ans = 0;

		for (int i = 1; i <= num; ++i) {
			if ((digitSum(i) & 1) == 0) ++ans;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int num;
		cin >> num;

		Solution solution;
		cout << solution.countEven(num) << endl;
	}

	return 0;
}