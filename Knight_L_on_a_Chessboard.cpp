#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

bool isValid(int x, int y, int n, vector<vector<bool>>& visited) {
    return x >= 0 && x < n&& y >= 0 && y < n&& visited[x][y] == false;
}



int knightlOnAChessboardHandler(int n, int a, int b) {
    queue<vector<int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n));
    vector<vector<int>> directions = { {-1, 1}, {1, 1}, {-1, -1}, {1, -1} };
    int result = 0;

    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            vector<int> cell = q.front();
            q.pop();
            int x = cell[0];
            int y = cell[1];
            for (vector<int>& direction : directions) {
                int x1 = x + a * direction[0];
                int y1 = y + b * direction[1];
                if (isValid(x1, y1, n, visited)) {
                    if (x1 == n - 1 && y1 == n - 1) {
                        return result + 1;
                    }
                    visited[x1][y1] = true;
                    q.push({ x1, y1 });
                }
                int x2 = x + b * direction[0];
                int y2 = y + a * direction[1];
                if (isValid(x2, y2, n, visited)) {
                    if (x2 == n - 1 && y2 == n - 1) {
                        return result + 1;
                    }
                    visited[x2][y2] = true;
                    q.push({ x2, y2 });
                }
            }
        }
        ++result;
    }

    return -1;
}

/*
 * Complete the 'knightlOnAChessboard' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> answer(n - 1, vector<int>(n - 1));

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            answer[i - 1][j - 1] = knightlOnAChessboardHandler(n, i, j);
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
