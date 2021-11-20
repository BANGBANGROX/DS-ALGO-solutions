#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& mat) {
        matrix = mat;
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0) matrix[i][j] += matrix[i - 1][j];
                if (j > 0) matrix[i][j] += matrix[i][j - 1];
                if (i > 0 && j > 0) matrix[i][j] -= matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return matrix[row2][col2] - ((row1 > 0) ? matrix[row1 - 1][col2] : 0) - 
            ((col1 > 0) ? matrix[row2][col1 - 1] : 0) + ((row1 > 0 && col1 > 0) ? matrix[row1 - 1][col1 - 1] : 0);
    }
};

int main() {
    int n, m, q;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> mat[i][j];
    }
    cin >> q;

    NumMatrix numMatrix(mat);

    while (q--) {
        int row1, row2, col1, col2;
        cin >> row1 >> col1 >> row2 >> col2;

        cout << numMatrix.sumRegion(row1, col1, row2, col2) << endl;
    }

    return 0;
}