// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int MaxGold(vector<vector<int>>& matrix) {
		// Code here
		int m = matrix.size();
		int n = matrix[0].size();

		for (int i = m - 2; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				if (matrix[i][j] == -1) continue;
				int value1 = matrix[i + 1][j] == -1 ? 0 : matrix[i + 1][j];
				int value2 = (j + 1 < n) ? matrix[i + 1][j + 1] == -1 ? 0 : matrix[i + 1][j + 1] : 0;
				int value3 = (j - 1 >= 0) ? matrix[i + 1][j - 1] == -1 ? 0 : matrix[i + 1][j - 1] : 0;
				matrix[i][j] += max({ value1,value2,value3 });
			}
		}

		int ans = *max_element(matrix[0].begin(), matrix[0].end());

		return ans == -1 ? 0 : ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans << '\n';
	}
	return 0;
}  // } Driver Code Ends