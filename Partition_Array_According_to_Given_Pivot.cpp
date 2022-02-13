#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		vector<int> lesserNums;
		vector<int> greaterNums;
		vector<int> equalNums;
		vector<int> ans;

		for (int num : nums) {
			if (num == pivot) {
				equalNums.push_back(num);
			}
			else if (num > pivot) {
				greaterNums.push_back(num);
			}
			else {
				lesserNums.push_back(num);
			}
		}

		for (int num : lesserNums) {
			ans.push_back(num);
		}

		for (int num : equalNums) {
			ans.push_back(num);
		}

		for (int num : greaterNums) {
			ans.push_back(num);
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
		int pivot;
		cin >> pivot;

		Solution solution;
		vector<int> ans = solution.pivotArray(nums, pivot);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}