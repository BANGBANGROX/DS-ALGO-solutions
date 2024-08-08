#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r_start, int c_start)
    {
        vector<vector<int>> answer;
        set<vector<int>> visited;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int current_x = r_start;
        int current_y = c_start;
        int current_dir = 0;

        answer.push_back({current_x, current_y});
        visited.insert({current_x, current_y});

        while ((int)answer.size() < rows * cols)
        {
            int next_x = current_x + directions[current_dir][0];
            int next_y = current_y + directions[current_dir][1];
            if (next_x >= 0 && next_y >= 0 && next_x < rows && next_y < cols)
            {
                answer.push_back({next_x, next_y});
                visited.insert({next_x, next_y});
            }
            current_x = next_x;
            current_y = next_y;
            int new_dir = (current_dir + 1) % 4;
            next_x = current_x + directions[new_dir][0];
            next_y = current_y + directions[new_dir][1];
            if (visited.find({next_x, next_y}) == visited.end())
            {
                current_dir = new_dir;
            }
        }

        return answer;
    }
};

int main()
{
    int test_cases;
    cin >> test_cases;

    while (test_cases-- > 0)
    {
        int rows;
        cin >> rows;
        int cols;
        cin >> cols;
        int r_start;
        cin >> r_start;
        int c_start;
        cin >> c_start;

        vector<vector<int>> answer = (new Solution())->spiralMatrixIII(rows, cols, r_start, c_start);
        for (vector<int> &cell : answer)
        {
            cout << cell[0] << " " << cell[1] << endl;
        }
        cout << endl;
    }
}