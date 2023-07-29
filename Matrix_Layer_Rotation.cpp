#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>>& matrix, int r) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    int layers = min(m, n) / 2;
    vector<vector<int>> layerWiseMatrix;

    for (int i = 0; i < layers; ++i) {
        vector<int> currentLayer;
        for (int j = i; j < (n - i - 1); ++j) {
            currentLayer.push_back(matrix[i][j]);
        }
        for (int j = i; j < (m - i - 1); ++j) {
            currentLayer.push_back(matrix[j][n - i - 1]);
        }
        for (int j = (n - i - 1); j > i; --j) {
            currentLayer.push_back(matrix[m - i - 1][j]);
        }
        for (int j = (m - i - 1); j > i; --j) {
            currentLayer.push_back(matrix[j][i]);
        }
        layerWiseMatrix.push_back(currentLayer);
    }

    for (int i = 0; i < layers; ++i) {
        int len = (int)layerWiseMatrix[i].size();
        int idx = r % len;
        for (int j = i; j < (n - i - 1); ++j) {
            matrix[i][j] = layerWiseMatrix[i][idx];
            idx = (idx + 1) % len;
        }
        for (int j = i; j < (m - i - 1); ++j) {
            matrix[j][n - i - 1] = layerWiseMatrix[i][idx];
            idx = (idx + 1) % len;
        }
        for (int j = (n - i - 1); j > i; --j) {
            matrix[m - i - 1][j] = layerWiseMatrix[i][idx];
            idx = (idx + 1) % len;
        }
        for (int j = (m - i - 1); j > i; --j) {
            matrix[j][i] = layerWiseMatrix[i][idx];
            idx = (idx + 1) % len;
        }
    }

    for (vector<int>& row : matrix) {
        for (int& x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
