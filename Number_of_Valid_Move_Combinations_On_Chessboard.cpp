#include<bits/stdc++.h>
using namespace std;

int dir[8][2] = { {0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1} };
int b[4][8][8] = { 0 };

int countCombinations(vector<string>& pieces, vector<vector<int>>& positions, int ind = 0) {
	if (ind >= pieces.size()) return 1;

	int x = positions[ind][0] - 1, y = positions[ind][1] - 1, res = 0;

	for (int d = 0; d < 8; ++d) {
		if (d < 4 && pieces[ind] == "bishop" || d >= 4 && pieces[ind] == "rook") continue;
		bool blocked = false;
		for (int steps = res == 0 ? 1 : 2; !blocked; ++steps) {
			int newX = x + (steps - 1) * dir[d][0], newY = y + (steps - 1) * dir[d][1];
			if (min(newX, newY) < 0 || max(newX, newY) > 7) break;
			bool canStop = true;
			for (int p = 0; p < ind; ++p) {
				canStop &= (b[p][newX][newY] >= 0 && b[p][newX][newY] < steps);
				blocked |= (b[p][newX][newY] < 0 && -1 * b[p][newX][newY] <= steps) | (b[p][newX][newY] == steps);
			}
			if (canStop) {
				b[ind][newX][newY] = -1 * steps;
				res += countCombinations(pieces, positions, ind + 1);
			}
			b[ind][newX][newY] = steps;
		}
		fill_n(b[ind][0], 64, 0);
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<string> pieces(n);
		vector<vector<int>> positions;

		memset(b, 0, sizeof(b));

		for (int i = 0; i < n; ++i) cin >> pieces[i];

		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			positions.push_back({ a,b });
		}

		cout << countCombinations(pieces, positions) << endl;
	}

	return 0;
}