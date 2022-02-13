#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int n = numbers.size();
		int l = 0;
		int r = n - 1;

		while (l < r) {
			int sum = numbers[l] + numbers[r];
			if (sum == target) break;
			else if (sum > target) --r;
			else ++l;
		}

		return { l + 1,r + 1 };
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, target;
		cin >> n;
		vector<int> numbers(n);
		for (int& x : numbers) cin >> x;
		cin >> target;

		Solution solution;
		vector<int> ans = solution.twoSum(numbers, target);
		cout << ans[0] << " " << ans[1] << endl;
	}

	return 0;
}