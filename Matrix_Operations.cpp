// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	pair<int, int> endPoints(vector<vector<int>> matrix) {
		//code here
		int m = matrix.size();
		int n = matrix[0].size();
		int dx[4] = { 0,1,0,-1 };
		int dy[4] = { 1,0,-1,0 };
		int direction = 0;
		queue<pair<int, int>> q;

		q.push({ 0,0 });

		while (!q.empty()) {
			pair<int, int> currentPoint = q.front();
			q.pop();
			int x = currentPoint.first;
			int y = currentPoint.second;
			if (matrix[x][y] == 1) {
				matrix[x][y] = 0;
				direction = (direction + 1) % 4;
			}
			int newX = x + dx[direction];
			int newY = y + dy[direction];
			if (newX < 0 || newY < 0 || newX >= m || newY >= n) return { x, y };
			q.push({ newX,newY });
		}
		
		return {};
	}

};

// { Driver Code Starts.


int main()
{
	int tc;
	scanf_s("%d", &tc);
	while (tc--) {
		int row, col;
		scanf_s("%d", &row);
		scanf_s("%d", &col);
		vector<vector<int>> matrix(row, vector<int>(col));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		pair<int, int> p = obj.endPoints(matrix);

		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends