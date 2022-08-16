#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
         int n = grid.size();
         vector<vector<int>> ans(n - 2, vector<int>(n - 2));

         for (int i = 1; i < n - 1; ++i) {
             for (int j = 1; j < n - 1; ++j) {
                 int top = i - 1;
                 int bottom = i + 1;
                 int left = j - 1;
                 int right = j + 1;
                 int maxValue = INT_MIN;
                 for (int l = top; l <= bottom; ++l) {
                     for (int s = left; s <= right; ++s) {
                         maxValue = max(maxValue, grid[l][s]);
                     }
                 }
                 ans[i - 1][j - 1] = maxValue;
             }
         }

         return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        Solution solution;
        vector<vector<int>> ans = solution.largestLocal(matrix);
        for (vector<int> &x: ans) {
            for (int &y: x) cout << y << " ";
            cout << endl;
        }
    }

    return 0;
}