#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int minimumRounds(vector<int>& tasks) {
		unordered_map<int, int> count;
		int ans = 0;

		for (int task : tasks) {
			++count[task];
		}

		for (const pair<int, int>& cnt : count) {
			int x = cnt.second;
			if (x == 1) return -1;
			if (x % 3 == 0) ans += x / 3;
			else if (x % 3 == 1) {
				ans += (x / 3 - 1 + (x - (x / 3 - 1) * 3) / 2);
			}
			else {
				ans += (x / 3 + 1);
			}
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
		vector<int> tasks(n);
		for (int& x : tasks) cin >> x;

		Solution solution;
		cout << solution.minimumRounds(tasks) << endl;
	}

	return 0;
}