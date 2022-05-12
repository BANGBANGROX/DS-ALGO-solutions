#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string digitSum(string s, int k) {
		string ans = s;

		while ((int) ans.size() > k) {
			string next("");
			int n = ans.size();
			int count = 0;
			int sum = 0;
			for (int i = 0; i < n; ++i) {
				sum += (ans[i] - '0');
				++count;
				if (count == k) {
					next += to_string(sum);
					count = 0;
					sum = 0;
				}
			}
			if (count > 0) next += to_string(sum);
			ans = next;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		int k;
		cin >> k;

		Solution solution;
		cout << solution.digitSum(s, k) << endl;
	}

	return 0;
}