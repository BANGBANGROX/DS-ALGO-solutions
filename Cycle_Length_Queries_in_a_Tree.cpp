#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
		vector<int> ans;

		for (vector<int>& query : queries) {
			int a = query[0];
			int b = query[1];
			int result = 1;
			while (a != b) {
				if (a < b) swap(a, b);
				a /= 2;
				++result;
			}
			ans.push_back(result);
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
		vector<vector<int>> queries(n, vector<int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> queries[i][0] >> queries[i][1];
		}

		Solution solution;
		vector<int> ans = solution.cycleLengthQueries(n, queries);
		for (int& x : ans) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}