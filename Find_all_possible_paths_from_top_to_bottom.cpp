// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    vector<vector<int>> ans;
    vector<int> current;
    vector<vector<int>> grid;
    int m;
    int n;

    void generate(int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n) return;

        if (x == m - 1 && y == n - 1) {
            current.push_back(grid[x][y]);
            ans.push_back(current);
            current.pop_back();
            return;
        }

        current.push_back(grid[x][y]);

        generate(x + 1, y);
        generate(x, y + 1);

        current.pop_back();
    }

public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>>& grid) {
        // code here
        this->grid = grid;
        this->m = n;
        this->n = m;

        generate(0, 0);

        return ans;
    }
};
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends