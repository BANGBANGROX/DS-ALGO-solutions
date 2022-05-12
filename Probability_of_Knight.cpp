// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	double findProb(int n, int start_x, int start_y, int steps) {
		// Code here
		vector<vector<double>> current(n, vector<double>(n));
		vector<vector<double>> next(n, vector<double>(n));
		double ans = 0;
		int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
		int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

		current[start_x][start_y] = 1;

		for (int step = 1; step <= steps; ++step) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (current[i][j] != 0.0) {
						for (int k = 0; k < 8; ++k) {
							int newX = i + dx[k];
							int newY = j + dy[k];
							if (newX >= 0 && newY >= 0 && newX < n && newY < n) {
								next[newX][newY] += current[i][j] * 0.125;
							}
						}
					}
				}
			}
			current = next;
			next = vector<vector<double>>(n, vector<double>(n));
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans += current[i][j];
			}
		}

		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends