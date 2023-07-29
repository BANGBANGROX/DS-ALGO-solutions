#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);


bool isValid(int x, int y, int m, int n, vector<string>& grid, char ch) {
    return x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == ch;
}

/*
 * Complete the 'twoPluses' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY grid as parameter.
 */

int twoPluses(vector<string>& grid) {
    int m = (int)grid.size();
    int n = (int)grid[0].size();
    int answer = 0;

    for (int a = 0; a < m; ++a) {
        for (int b = 0; b < n; ++b) {
            int r1 = 0;
            while(isValid(a + r1, b, m, n, grid, 'G') && 
                isValid(a, b + r1, m, n, grid, 'G') && 
                isValid(a - r1, b, m, n, grid, 'G') && 
                isValid(a, b - r1, m, n, grid, 'G')) {
                grid[a + r1][b] = grid[a][b + r1] = grid[a - r1][b] = 
                    grid[a][b - r1] = 'g';
                for (int c = 0; c < m; ++c) {
                    for (int d = 0; d < n; ++d) {
                        int r2 = 0;
                        while (isValid(c + r2, d, m, n, grid, 'G') && 
                            isValid(c, d + r2, m, n, grid, 'G') && 
                            isValid(c - r2, d, m, n, grid, 'G') && 
                            isValid(c, d - r2, m, n, grid, 'G')) {
                            answer = max(answer, (4 * r1 + 1) * (4 * r2 + 1));
                            ++r2;
                        }
                    }
                }
                ++r1;
            }
            r1 = 0;
            while (isValid(a + r1, b, m, n, grid, 'g') && 
                isValid(a, b + r1, m, n, grid, 'g') && 
                isValid(a - r1, b, m, n, grid, 'g') && 
                isValid(a, b - r1, m, n, grid, 'g')) {
                grid[a + r1][b] = grid[a][b + r1] = grid[a - r1][b] =
                    grid[a][b - r1] = 'G';
                ++r1;
            }
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    fout << result << "\n";

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
