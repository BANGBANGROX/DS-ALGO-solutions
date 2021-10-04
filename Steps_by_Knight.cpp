#include<bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n) {
	return x > 0 && y > 0 && x <= n && y <= n;
}

int findMinSteps(int sx, int sy, int ex, int ey, int n) {
	vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
	int dx[] = { -2,-1,1,2,2,1,-1,-2 };
	int dy[] = { 1, 2, 2,1,-1,-2,-2,-1 };
	queue<pair<int, int>> q;

	dist[sx][sy] = 0;

	q.push({ sx,sy });

	while (!q.empty()) {
		pair<int, int> top = q.front();
		q.pop();
		int x = top.first;
		int y = top.second;
		vis[x][y] = 1;
		for (int i = 0; i < 8; ++i) {
			if (isValid(x + dx[i], y + dy[i], n) && !vis[x + dx[i]][y + dy[i]]) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				dist[newX][newY] = min(dist[newX][newY], 1 + dist[x][y]);
				vis[newX][newY] = 1;
				q.push({ newX,newY });
			}
		}
	}

	return dist[ex][ey];
}

int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int n) {

	return findMinSteps(KnightPos[0], KnightPos[1], TargetPos[0], TargetPos[1], n);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, sx, sy, ex, ey;
		cin >> n >> sx >> sy >> ex >> ey;
		vector<int> kp = { sx,sy };
		vector<int> tp = { ex,ey };

		cout << minStepToReachTarget(kp, tp, n) << endl;
	}

	return 0;
}