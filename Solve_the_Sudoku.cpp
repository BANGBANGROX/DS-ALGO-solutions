#include<bits/stdc++.h>
using namespace std;

bool isSafeRow(vector<vector<int>>& grid, int row, int num) {
	for (int i = 0; i < 9; ++i) {
		if (grid[row][i] == num) {
			return true;
		}
	}

	return false;
}

bool isSafeColoumn(vector<vector<int>>& grid, int col, int num) {
	for (int i = 0; i < 9; ++i) {
		if (grid[i][col] == num) {
			return true;
		}
	}

	return false;
}

bool isSafeGrid(vector<vector<int>>& grid, int num, int rowStart, int colStart) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; ++j) {
			if (grid[i + rowStart][j + colStart] == num) {
				return true;
			}
		}
	}

	return false;
}

bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
	return !isSafeColoumn(grid, col, num) && !isSafeRow(grid, row, num)
		&& !isSafeGrid(grid, num, row - row % 3, col - col % 3) && grid[row][col] == 0;
}

bool findAssigned(vector<vector<int>>& grid, int* row, int* col) {
	for (*row = 0; *row < 9; ++ * row) {
		for (*col = 0; *col < 9; ++ * col) {
			if (grid[*row][*col] == 0) {
				return true;
			}
		}
	}

	return false;
}

bool solveSudokuUtil(vector<vector<int>>& grid) {
	int row, col;
	if (!findAssigned(grid, &row, &col)) return true;

	for (int i = 1; i <= 9; ++i) {
		if (isSafe(grid, row, col, i)) {
			grid[row][col] = i;
			if (solveSudokuUtil(grid)) return true;
			grid[row][col] = 0;
		}
	}

	return false;
}

void print(vector<vector<int>>& grid) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

bool SolveSudoku(int a[9][9]) {
	vector<vector<int>> grid(9, vector<int>(9));
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			grid[i][j] = a[i][j];
		}
	}

	int ans = solveSudokuUtil(grid);

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a[9][9];
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cin >> a[i][j];
			}
		}
		SolveSudoku(a);
	}

	return 0;
}