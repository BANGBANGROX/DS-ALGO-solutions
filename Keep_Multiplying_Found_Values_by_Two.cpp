#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int findFinalValue(vector<int>& nums, int original) {
		unordered_map<int, bool> mp;

		for (int num : nums) {
			mp[num] = true;
		}

		while (mp.find(original) != mp.end()) {
			original *= 2;
		}

		return original;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, original;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		cin >> original;

		Solution solution;
		cout << solution.findFinalValue(nums, original) << endl;
	}

	return 0;
}