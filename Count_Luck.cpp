#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

bool isValid(int x, int y, int m, int n, vector<string>& matrix) {
    return x >= 0 && y >= 0 && x < m && y < n && matrix[x][y] != 'X';
}

int oppositeDirection(int dir) {
    if (dir == 0) return 1;

    if (dir == 1) return 0;

    if (dir == 2) return 3;

    if (dir == 3) return 2;

    return -1;
}

/*
 * Complete the 'countLuck' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY matrix
 *  2. INTEGER k
 */

string countLuck(vector<string> matrix, int k) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    int sx = -1;
    int sy = -1;
    int valid = 0;
    int answer = -1;
    bool done = false;
    stack<vector<int>> st;
    vector<vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 'M') {
                sx = i;
                sy = j;
                break;
            }
        }
        if (sx != -1) break;
    }

    for (int i = 0; i < 4; ++i) {
        int newX = sx + directions[i][0];
        int newY = sy + directions[i][1];
        if (isValid(newX, newY, m, n, matrix)) {
            ++valid;
        }
    }

    for (int i = 0; i < 4; ++i) {
        int newX = sx + directions[i][0];
        int newY = sy + directions[i][1];
        if (isValid(newX, newY, m, n, matrix)) {
            if (valid > 1) {
                st.push({ sx, sy, 1, i });
            }
            else {
                st.push({ sx, sy, 0, i });
            }
        }
    }

    while (!st.empty() && !done) {
        vector<int> cell = st.top();
        st.pop();
        int x = cell[0];
        int y = cell[1];
        int taken = cell[2];
        int dir = cell[3];
        int newX = x;
        int newY = y;
        while (true) {
            newX += directions[dir][0];
            newY += directions[dir][1];
            if (!isValid(newX, newY, m, n, matrix)) break;
            if (matrix[newX][newY] == '*') {
                answer = taken;
                done = true;
            }
            int nextValid = 0;
            for (int i = 0; i < 4; ++i) {
                int nextX = newX + directions[i][0];
                int nextY = newY + directions[i][1];
                if (isValid(nextX, nextY, m, n, matrix) && 
                    i != oppositeDirection(dir)) {
                    ++nextValid;
                }
            }
            if (nextValid > 1) {
                ++taken;
            }
            for (int i = 0; i < 4; ++i) {
                int nextX = newX + directions[i][0];
                int nextY = newY + directions[i][1];
                if (isValid(nextX, nextY, m, n, matrix) &&
                    i != oppositeDirection(dir) && i != dir) {
                    st.push({ newX, newY, taken, i });
                }
            }
        }
    }

    return answer == k ? "Impressed" : "Oops!";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        string result = countLuck(matrix, k);

        fout << result << "\n";
    }

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
