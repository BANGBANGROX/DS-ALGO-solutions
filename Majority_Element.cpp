#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 0;
		int ans = -1;

		for (int& num : nums) {
			if (count == 0) {
				ans = num;
				++count;
			}
			else if (ans == num) ++count;
			else --count;
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

		Solution solution;
		cout << solution.majorityElement(nums) << endl;
	}

	return 0;
}