#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumbers(vector<int> nums) {
	int n = nums.size(), XOR = nums[0], num1 = 0, num2 = 0;

    for (int i = 1; i < n; ++i) {
		XOR ^= nums[i];
	}
	int set_bit = XOR and ~(XOR - 1);
	for (int i = 0; i < n; ++i) {
		if (nums[i] & set_bit) {
			num1 ^= nums[i];
		}
		else {
			num2 ^= nums[i];
		}
	}
	if (num1 > num2) swap(num1, num2);
	vector<int> v;
	v.push_back(num1);
	v.push_back(num2);

	return v;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(2 * n + 2);
		for (int& x : a) cin >> x;

        vector<int> ans = singleNumbers(a);
		cout << ans[0] << " " << ans[1] << endl;
	}

	return 0;
}