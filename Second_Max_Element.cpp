#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int secondMaxElement(vector<int>& nums) {
		int firstMax = INT_MIN;
		int secondMax = INT_MIN;

		for (int num : nums) {
			if (num > firstMax) {
				secondMax = firstMax;
				firstMax = num;
			}
			else if (num == firstMax || num > secondMax) {
				secondMax = num;
			}
		}

		return secondMax;
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
		cout << solution.secondMaxElement(nums) << endl;
	}

	return 0;
}