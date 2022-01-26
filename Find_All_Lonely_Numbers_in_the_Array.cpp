#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findLonely(vector<int>& nums) {
		unordered_map<int, int> count;
		vector<int> ans;

		for (int num : nums) {
			++count[num];
		}

		for (int num : nums) {
			if (count[num] == 1 && count.count(num - 1) == 0 && count.count(num + 1) == 0) {
				ans.push_back(num);
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}

		Solution solution;
		vector<int> ans = solution.findLonely(nums);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}