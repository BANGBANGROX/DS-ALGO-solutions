#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		int ans = 0;
		unordered_map<int, int> mp;

		for (int num : nums) {
			++mp[num];
		}

		for (int num : nums) {
			if (mp[num] == 0) continue;
			if (k == 0 && mp[num] > 1) ++ans;
			else if (k != 0) {
				if (mp[num + k] > 0) ++ans;
				if (mp[num - k] > 0) ++ans;
			}
			mp[num] = 0;
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
		for (int& x : nums) cin >> x;
		int k;
		cin >> k;

		Solution solution;
		cout << solution.findPairs(nums, k) << endl;
	}

	return 0;
}