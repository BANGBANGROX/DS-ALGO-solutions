#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = 0, j = matrix[0].size() - 1, n = matrix.size();

    while (i < n && j > -1) {
        if (matrix[i][j] == target) return true;
        if (matrix[i][j] > target) --j;
        else ++i;
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m, target;
        cin >> n >> m;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
        cin >> target;

        if (searchMatrix(matrix, target)) cout << "Element found\n";
        else cout << "Element not found\n";
    }

    return 0;
}
