#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		int maxXor = 0;
		int mask = 0;

		for (int i = 31; i >= 0; --i) {
			mask = mask | (1 << i);
			unordered_map<int, bool> mp;
			for (int num : nums) {
				mp[mask & num] = true;
			}
			int temp = maxXor | (1 << i);
			for (const pair<int, bool>& prefix : mp) {
				if (mp.find(prefix.first ^ temp) != mp.end()) {
					maxXor = temp;
				}
			}
		}

		return maxXor;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) {
			cin >> x;
		}

		Solution solution;
		cout << solution.findMaximumXOR(nums) << endl;
	}

	return 0;
}