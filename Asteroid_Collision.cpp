#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> ans;
		int n = asteroids.size();

		ans.push_back(asteroids[0]);

		for (int i = 1; i < n; ++i) {
			bool flag = false;
			while (!ans.empty() && ans.back() > 0 && asteroids[i] < 0) {
				int posValue = ans.back();
				int negValue = -1 * asteroids[i];
				if (posValue == negValue) {
					ans.pop_back();
					flag = true;
					break;
				}
				else if (posValue > negValue) {
					flag = true;
					break;
				}
				else ans.pop_back();
			}
			if (!flag) ans.push_back(asteroids[i]);
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
		vector<int> asteroids(n);
		for (int& x : asteroids) cin >> x;

		Solution solution;
		vector<int> ans = solution.asteroidCollision(asteroids);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}