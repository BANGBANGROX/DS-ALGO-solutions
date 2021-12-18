#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> curr;
vector<int> nums;
int n;

void generate(int index, int target) {
	if (target == 0) {
		ans.push_back(curr);
		return;
	}

	if (index == n || target < 0) return;

	curr.push_back(nums[index]);
	generate(index, target - nums[index]);
	curr.pop_back();
	generate(index + 1, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	n = candidates.size();
	nums = candidates;
	sort(nums.begin(), nums.end());

	generate(0, target);

	return ans;
}

int main() {
	int n, target;
	cin >> n;
	vector<int> nums(n);
	for (int& x : nums) cin >> x;
	cin >> target;

	vector<vector<int>> res = combinationSum(nums, target);
	for (vector<int>x : res) {
		for (int y : x) cout << y << " ";
		cout << endl;
	}

	return 0;
}
