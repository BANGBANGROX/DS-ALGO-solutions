// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	//Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int minimumCostPath(vector<vector<int>>& grid) {
		// Code here
		int m = grid.size();
		int n = grid[0].size();
		int dx[4] = { -1,0,1,0 };
		int dy[4] = { 0,1,0,-1 };
		vector<vector<int>> minCost(n, vector<int>(n, INT_MAX));
		set<pair<int, pair<int, int>>> st;

		minCost[0][0] = grid[0][0];
		st.insert({ minCost[0][0],{0,0} });

		while (!st.empty()) {
			pair<int, pair<int, int>> current = *st.begin();
			st.erase(st.begin());
			int distance = current.first;
			int x = current.second.first;
			int y = current.second.second;
			for (int i = 0; i < 4; ++i) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newX < m && newY >= 0 && newY < n 
					&& minCost[newX][newY] > distance + grid[newX][newY]) {
					st.erase({ minCost[newX][newY],{newX,newY} });
					minCost[newX][newY] = distance + grid[newX][newY];
					st.insert({ minCost[newX][newY],{newX,newY} });
				}
			}
		}

		return minCost[m - 1][n - 1];
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends