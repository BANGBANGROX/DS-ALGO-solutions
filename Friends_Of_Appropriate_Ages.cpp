#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		int n = ages.size();
		int l = 0;
		int r = 0;
		int ans = 0;

		sort(ages.begin(), ages.end());

		for (int age : ages) {
			while (l < n && ages[l] <= age / 2.0 + 7) ++l;
			while (r < n && ages[r] <= age) ++r;
			if (r - 1 >= l) ans += (r - l - 1);
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
		vector<int> ages(n);
		for (int& age : ages) cin >> age;

		Solution solution;
		cout << solution.numFriendRequests(ages) << endl;
	}

	return 0;
}