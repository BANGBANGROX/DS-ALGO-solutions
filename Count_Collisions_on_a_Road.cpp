// https://leetcode.com/problems/count-collisions-on-a-road/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countCollisions(string directions) {
		int n = directions.size();
		int left = 0;
		int right = n - 1;
		int ans = 0;

		while (left < n && directions[left] == 'L') ++left;

		while (right >= 0 && directions[right] == 'R') --right;

		for (int i = left; i <= right; ++i) {
			if (directions[i] != 'S') ++ans;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string directions;
		cin >> directions;

		Solution solution;
		cout << solution.countCollisions(directions) << endl;
	}

	return 0;
}