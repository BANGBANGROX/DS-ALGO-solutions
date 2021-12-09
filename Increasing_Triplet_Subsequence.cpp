#include<bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
	int min1 = INT_MAX, min2 = INT_MAX;

	for (int num : nums) {
		if (num < min1) min1 = num;
		else if (num < min2 && num > min1) min2 = num;
		else if (num > min2) return true;
	}

	return false;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		if (increasingTriplet(nums)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}
