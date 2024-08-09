#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int answer = 0;

        for (int first_row = 0; first_row < m - 2; ++first_row)
        {
            for (int first_col = 0; first_col < n - 2; ++first_col)
            {
                int last_row = first_row + 2;
                int last_col = first_col + 2;
                bool is_magic = true;
                unordered_set<int> row_sum;
                unordered_set<int> col_sum;
                unordered_set<int> all_nums;

                // compute sum of all rows
                for (int i = first_row; i <= last_row; ++i)
                {
                    int curr_row_sum = 0;
                    for (int j = first_col; j <= last_col; ++j)
                    {
                        if (grid[i][j] > 9 || grid[i][j] < 1)
                        {
                            is_magic = false;
                            break;
                        }
                        all_nums.insert(grid[i][j]);
                        curr_row_sum += grid[i][j];
                    }
                    if (!is_magic)
                    {
                        break;
                    }
                    row_sum.insert(curr_row_sum);
                }
                if (!is_magic || (int)all_nums.size() != 9 || (int)row_sum.size() != 1)
                {
                    continue;
                }
                int all_row_sum = *row_sum.begin();

                // compute sum of all cols
                for (int j = first_col; j <= last_col; ++j)
                {
                    int curr_col_sum = 0;
                    for (int i = first_row; i <= last_row; ++i)
                    {
                        curr_col_sum += grid[i][j];
                    }
                    col_sum.insert(curr_col_sum);
                }
                if ((int)col_sum.size() != 1)
                {
                    continue;
                }
                int all_col_sum = *col_sum.begin();
                if (all_row_sum != all_col_sum)
                {
                    continue;
                }

                // compute sum of both diagonals
                int first_diag_sum = 0;
                int second_diag_sum = 0;
                for (int i = first_row; i <= last_row; ++i)
                {
                    for (int j = first_col; j <= last_col; ++j)
                    {
                        if (i - first_row == j - first_col)
                        {
                            first_diag_sum += grid[i][j];
                        }
                        if ((i + j - first_row - first_col) == 2)
                        {
                            second_diag_sum += grid[i][j];
                        }
                    }
                }
                if (first_diag_sum != second_diag_sum || first_diag_sum != all_row_sum)
                {
                    continue;
                }
                ++answer;
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
        int m;
        cin >> m;
        int n;
        cin >> n;
        vector<vector<int>> grid(m, vector<int>(n));
        for (vector<int> &row : grid)
        {
            for (int &x : row)
            {
                cin >> x;
            }
        }

        cout << (new Solution())->numMagicSquaresInside(grid) << endl;
    }

    return 0;
}