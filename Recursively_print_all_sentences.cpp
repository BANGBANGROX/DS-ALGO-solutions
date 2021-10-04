#include<bits/stdc++.h>
using namespace std;

const int N = 10;

void findSentence(string output[], string arr[][N], int m, int n, int row, int col) {
	output[m] = arr[m][n];

	if (m == row - 1) {
		for (int i = 0; i < row; ++i) {
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < col; ++i) {
		if (arr[m + 1][i] != "") {
			findSentence(output, arr, m + 1, i, row, col);
		}
	}
}

void findAllSentences(string arr[][N], int row, int col) {
	string* output = new string[row];

	for (int i = 0; i < col; ++i) {
		if (arr[0][i] != "") {
			findSentence(output, arr, 0, i, row, col);
		}
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int row, col;
		string arr[N][N];

		cin >> row >> col;

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				cin >> arr[i][j];
			}
		}

		findAllSentences(arr, row, col);
	}

	return 0;
}