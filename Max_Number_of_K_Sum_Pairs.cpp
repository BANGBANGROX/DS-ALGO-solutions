#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {
		unordered_map<int, int> count;
		int ans = 0;

		for (int num : nums) {
			++count[num];
		}

		for (int a : nums) {
			int next = k - a;
			if (count.find(next) == count.end() || count[a] == 0 || count[next] == 0) continue;
			if (next == a) {
				ans += count[next] / 2;
			}
			else {
				ans += min(count[a], count[next]);
			}
			count[next] = count[a] = 0;
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
		cout << solution.maxOperations(nums, k) << endl;
	}

	return 0;
}