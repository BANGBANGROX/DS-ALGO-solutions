#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();
		int ans = 0;
		
		for (int i = 0; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				matrix[i][j] += matrix[i][j - 1];
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				unordered_map<int, int> count;
				count[0] = 1;
				int currentSum = 0;
				for (int k = 0; k < m; ++k) {
					currentSum += (matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0));
					if (count.find(currentSum - target) != count.end()) 
						ans += count[currentSum - target];
					++count[currentSum];
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
		vector<vector<int>> matrix(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> matrix[i][j];
			}
		}
		int target;
		cin >> target;

		Solution solution;
		cout << solution.numSubmatrixSumTarget(matrix, target) << endl;
	}

	return 0;
}