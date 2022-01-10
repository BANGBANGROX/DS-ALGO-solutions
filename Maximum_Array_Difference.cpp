#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMaxDiff(vector<int>& nums) {
		int n = nums.size(), minNum = nums[0], maxDiff = -1;

		for (int i = 1; i < n; ++i) {
			if (nums[i] > minNum) {
				maxDiff = max(maxDiff, nums[i] - minNum);
				continue;
			}
			minNum = min(minNum, nums[i]);
		}

		return maxDiff;
	}
};

int main() {
	string arr;
	vector<int> nums;

	cin >> arr;

	int n = arr.size();

	for (int i = 0; i < n; ++i) {
		string num("");
		while (i < n && isdigit(arr[i])) {
			num += arr[i];
			++i;
		}
		if (!num.empty()) nums.push_back(stoi(num));
	}

	Solution obj;
	cout << obj.findMaxDiff(nums) << endl;

	return 0;
}
