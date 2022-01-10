#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int m = heightMap.size();
		int n = heightMap[0].size();
		int ans = 0;
		int maxHeight = 0;
		int dx[4] = { -1,0,1,0 };
		int dy[4] = { 0,1,0,-1 };
		vector<vector<bool>> vis(m, vector<bool>(n));
		priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, 
			greater<pair<int, pair<int, int>>>> pq;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
					pq.push({ heightMap[i][j],{i,j} });
					vis[i][j] = true;
				}
			}
		}

		while (!pq.empty()) {
			int currHeight = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			maxHeight = max(maxHeight, currHeight);
			for (int i = 0; i < 4; ++i) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newX < m && newY >= 0 && newY < n && !vis[newX][newY]) {
					pq.push({ heightMap[newX][newY],{newX,newY} });
					vis[newX][newY] = true;
					if (heightMap[newX][newY] < maxHeight) ans += (maxHeight - heightMap[newX][newY]);
				}
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> heightMap(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> heightMap[i][j];
			}
		}

		Solution obj;
		cout << obj.trapRainWater(heightMap) << endl;
	}

	return 0;
}