#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
	int getNextPosition(vector<int>& nums, int index, bool direction) {
		bool currentDirection = nums[index] > 0;
		int n = nums.size();

		if (currentDirection != direction) return -1;

		int newIndex = (index + nums[index]) % n;

		if (newIndex < 0) newIndex += n;

		if (newIndex == index) return -1;

		return newIndex;
	}

public:
	bool circularArrayLoop(vector<int>& nums) {
		int n = nums.size();

		if (n < 2) return false;

		for (int i = 0; i < n; ++i) {
			int slow = i;
			int fast = i;
			bool direction = nums[i] > 0;
			while (true) {
				slow = getNextPosition(nums, slow, direction);
				if (slow == -1) break;
				fast = getNextPosition(nums, fast, direction);
				if (fast == -1) break;
				fast = getNextPosition(nums, fast, direction);
				if (fast == -1) break;
				if (slow == fast) return true;
			}
		}

		return false;
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
		if (solution.circularArrayLoop(nums)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}