#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> bomberMan(int n, vector<string>& grid) {
    int row = (int)grid.size();
    int col = (int)grid[0].size();
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    
    if (n > 12) n = n % 12 + 12;

    for (int i = 0; i < n; ++i) {
        vector<string> copy = grid;
        for (int x = 0; x < row; ++x) {
            for (int y = 0; y < col; ++y) {
                if (copy[x][y] == 'O' || copy[x][y] == 'P') {
                    if (grid[x][y] != '.') ++grid[x][y];
                }
                else if (copy[x][y] == 'Q') {
                    grid[x][y] = '.';
                    for (vector<int>& direction : directions) {
                        int newX = x + direction[0];
                        int newY = y + direction[1];
                        if (newX >= 0 && newX < row && newY >= 0 && newY < col) {
                            grid[newX][newY] = '.';
                        }
                    }
                }
            }
        }
        if ((i & 1) > 0) {
            for (int x = 0; x < row; ++x) {
                for (int y = 0; y < col; ++y) {
                    if (grid[x][y] == '.') {
                        grid[x][y] = 'O';
                    }
                }
            }
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (grid[i][j] == 'P' || grid[i][j] == 'Q') {
                grid[i][j] = 'O';
            }
        }
    }

    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

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
