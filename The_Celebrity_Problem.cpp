#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& m, int n) {
	stack<int> ids;
	for (int i = 0; i < n; ++i) ids.push(i);

	while (ids.size() > 1) {
		int a = ids.top();
		ids.pop();
		int b = ids.top();
		ids.pop();
		if (m[a][b]) {
			ids.push(b);
		}
		else if (m[b][a]) {
			ids.push(a);
		}
	}

	if (ids.empty()) return -1;

	int potentialCelebrity = ids.top(), knowsPeople = 0, knownByPeople = 0;
	for (int i = 0; i < n; ++i) {
		if (i != potentialCelebrity) {
			knowsPeople += m[potentialCelebrity][i];
			knownByPeople += m[i][potentialCelebrity];
		}
	}

	if (knowsPeople == 0 && knownByPeople == n - 1) return potentialCelebrity;

	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> m(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cin >> m[i][j];
		}

		cout << celebrity(m, n) << endl;
	}

	return 0;
}