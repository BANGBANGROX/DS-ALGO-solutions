#include<bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int n = image.size(), m = image[0].size();
	int dx[] = { -1,0,0,1 };
	int dy[] = { 0,-1,1,0 };
	vector<vector<bool>> vis(n, vector<bool>(m));
	queue<pair<int, int>> q;

	q.push({ sr,sc });

	while (!q.empty()) {
		pair<int, int> top = q.front();
		q.pop();
		int x = top.first;
		int y = top.second;
		for (int i = 0; i < 4; ++i) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (isValid(newX, newY, n, m) && !vis[newX][newY] && image[newX][newY] == image[x][y]) {
				vis[newX][newY] = 1;
				q.push({ newX,newY });
			}
		}
		image[x][y] = newColor;
	}

	return image;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, col, sr, sc;
		cin >> n >> m >> col >> sr >> sc;
		vector<vector<int>> image(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cin >> image[i][j];
		}
		vector<vector<int>> res = floodFill(image, sr, sc, col);

		for (vector<int>x : res) {
			for (int y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}