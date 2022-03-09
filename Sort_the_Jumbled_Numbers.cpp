#include<bits/stdc++.h>
using namespace std;

class Solution {
	int mapNum(int num, vector<int>& mapping) {
		if (num == 0) return mapping[0];

		string ans("");

		while (num > 0) {
			ans = to_string(mapping[num % 10]) + ans;
			num /= 10;
		}

		cout << ans << endl;

		return stoi(ans);
	}

public:
	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
		vector<pair<int, pair<int, int>>> numsWithIndexes;

		for (int i = 0; i < nums.size(); ++i) {
			numsWithIndexes.push_back({ mapNum(nums[i],mapping),{i,nums[i]} });
		}

		sort(numsWithIndexes.begin(), numsWithIndexes.end());

		for (int i = 0; i < nums.size(); ++i) {
			nums[i] = numsWithIndexes[i].second.second;
		}

		return nums;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		vector<int> mapping(10);
		for (int i = 0; i < 10; ++i) {
			cin >> mapping[i];
		}
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		Solution solution;
		vector<int> ans = solution.sortJumbled(mapping, nums);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}