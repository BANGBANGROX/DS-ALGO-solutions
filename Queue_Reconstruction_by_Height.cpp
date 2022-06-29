#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		int n = people.size();
		vector<vector<int>> ans;

		sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
			return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1]; });

		for (int i = 0; i < n; ++i) {
			int idx = people[i][1];
			ans.insert(ans.begin() + idx, people[i]);
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
		vector<vector<int>> people(n, vector<int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> people[i][0] >> people[i][1];
		}

		Solution solution;
		vector<vector<int>> ans = solution.reconstructQueue(people);
		for (vector<int>& x : ans) {
			for (int& y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}