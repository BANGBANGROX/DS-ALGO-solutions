#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<int> findMaxAndSecondMax(vector<int>& nums, int start) {
		int maxNumber = *max_element(nums.begin(), nums.end());
		int n = nums.size();
		int maxNum = 0;
		int maxNumFrequency = 0;
		int secondMaxNum = 0;
		int secondMaxNumFrequency = 0;
		vector<int> frequency(maxNumber + 1);

		for (int i = start; i < n; i += 2) {
			++frequency[nums[i]];
		}

		for (int i = 0; i <= maxNumber; ++i) {
			if (frequency[i] > maxNumFrequency) {
				secondMaxNumFrequency = maxNumFrequency;
				secondMaxNum = maxNum;
				maxNumFrequency = frequency[i];
				maxNum = i;
			}
			else if (frequency[i] > secondMaxNumFrequency) {
				secondMaxNumFrequency = frequency[i];
				secondMaxNum = i;
			}
		}

		return { maxNum, maxNumFrequency, secondMaxNum, secondMaxNumFrequency };
	}

public:
	int minimumOperations(vector<int>& nums) {
		int n = nums.size();
		vector<int> oddScore = findMaxAndSecondMax(nums, 1);
		vector<int> evenScore = findMaxAndSecondMax(nums, 0);

		if (oddScore[0] != evenScore[0]) return n - oddScore[1] - evenScore[1];

		return min(n - oddScore[1] - evenScore[3], n - oddScore[3] - evenScore[1]);
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
		cout << solution.minimumOperations(nums) << endl;
	}

	return 0;
}