#include<bits/stdc++.h>
using namespace std;

class Solution {
	static bool comparator(string a, string b) {
		string concatA = a + b;
		string concatB = b + a;

		return concatA > concatB;
	}

public:
	string largestNumber(vector<int>& nums) {
		string ans("");
		vector<string> stringNums;

		for (int num : nums) {
			string stringNum = to_string(num);
		    stringNums.push_back(stringNum);
		}

		sort(stringNums.begin(), stringNums.end(), comparator);
		
		for (string s : stringNums) {
			ans += s;
		}

		if (ans.empty() || ans[0] == '0') return "0";

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
		cout << solution.largestNumber(nums) << endl;
	}

	return 0;
}