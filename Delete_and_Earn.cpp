#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int deleteAndEarnUtil(vector<int>& nums) {
	unordered_map<int, int> freq;
	int n = nums.size();
	int maxVal = *max_element(nums.begin(), nums.end());
	vector<int> vec(maxVal + 1), include(maxVal + 1), exclude(maxVal + 1);

	for (int i = 0; i < n; ++i) ++freq[nums[i]];

	for (pair<int, int> x : freq) {
		vec[x.first] = x.second;
	}

	for (int i = 1; i <= maxVal; ++i) {
		include[i] = exclude[i - 1] + i * vec[i];
		exclude[i] = max(include[i - 1], exclude[i - 1]);
	}

	return max(include[maxVal], exclude[maxVal]);
}

int deleteAndEarn(vector<int>& nums) {
	int ans = deleteAndEarnUtil(nums);

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << deleteAndEarn(nums) << endl;
	}

	return 0;
}