// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		// Code here
		int m = image.size();
		int n = image[0].size();
		int oldColor = image[sr][sc];

		if (oldColor == newColor) return image;

		int dx[4] = { -1, 0, 1, 0 };
		int dy[4] = { 0, -1, 0, 1 };
		queue<pair<int, int>> q;

		q.push({ sr,sc });
		image[sr][sc] = newColor;

		while (!q.empty()) {
			pair<int, int> currentPixel = q.front();
			q.pop();
			int x = currentPixel.first;
			int y = currentPixel.second;
			for (int i = 0; i < 4; ++i) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newX < m && newY >= 0 && newY < n && image[newX][newY] == oldColor) {
					image[newX][newY] = newColor;
					q.push({ newX,newY });
				}
			}
		}

		return image;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for (auto i : ans) {
			for (auto j : i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends