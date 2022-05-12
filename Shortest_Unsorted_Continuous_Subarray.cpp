#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size();
		int l = n;
		int r = 0;
		stack<int> st;

		for (int i = 0; i < n; ++i) {
			while (!st.empty() && nums[st.top()] > nums[i]) {
				l = min(l, st.top());
				st.pop();
			}
			st.push(i);
		}

		while (!st.empty()) st.pop();

		for (int i = n - 1; i >= 0; --i) {
			while (!st.empty() && nums[st.top()] < nums[i]) {
				r = max(r, st.top());
				st.pop();
			}
			st.push(i);
		}

		return r - l >= 0 ? r - l + 1 : 0;
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
		cout << solution.findUnsortedSubarray(nums) << endl;
	}

	return 0;
}