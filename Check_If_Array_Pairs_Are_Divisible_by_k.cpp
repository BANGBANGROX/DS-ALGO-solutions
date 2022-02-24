#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canArrange(vector<int>& arr, int k) {
		vector<int> remainders(k);
		int pairs = 0;
		int n = arr.size();

		for (int& num : arr) {
			num %= k;
			if (num < 0) num += k;
			++remainders[num];
		}

		for (int& num : arr) {
			if (remainders[num] == 0) continue;
			int requiredRemainder = (num == 0) ? 0 : k - num;
			if (num == requiredRemainder) {
				if (remainders[num] > 1) ++pairs;
			}
			else if (remainders[requiredRemainder] > 0) ++pairs;
			--remainders[num];
			--remainders[requiredRemainder];
		}

		return pairs == n / 2;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		cin >> k;

		Solution solution;
		if (solution.canArrange(nums, k)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}