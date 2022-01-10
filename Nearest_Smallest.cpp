#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> nearestSmallest(vector<int>& nums) {
		int n = nums.size();
		stack<int> st;
		vector<int> ans(n);

		for (int i = 0; i < n; ++i) {
			while (!st.empty() && nums[st.top()] >= nums[i]) {
				st.pop();
			}
			ans[i] = st.empty() ? -1 : nums[st.top()];
			st.push(i);
		}

		return ans;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int& x : nums) cin >> x;

	Solution obj;
	vector<int> ans = obj.nearestSmallest(nums);
	for (int x : ans) cout << x << " ";
	cout << endl;

	return 0;
}
