// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    static struct Node {
        int x;
        int y;
        int up;
        int down;
        
        Node(int x, int y, int up, int down) {
            this->x = x;
            this->y = y;
            this->up = up;
            this->down = down;
        }
    };

public:
    int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>>& grid) {
        // Your code goes here
        int ans = 0;
        queue<Node> q;
        vector<vector<bool>> visited(n, vector<bool>(m));

        if (grid[r][c] == '#') return 0;

        q.push(Node(r, c, 0, 0));
        visited[r][c] = true;

        while (!q.empty()) {
            ++ans;
            int x = q.front().x;
            int y = q.front().y;
            int up = q.front().up;
            int down = q.front().down;
            q.pop();
            // GO RIGHT
            if (y + 1 < m && !visited[x][y + 1] && grid[x][y + 1] == '.') {
                q.push(Node(x, y + 1, up, down));
                visited[x][y + 1] = true;
            }
            // GO LEFT
            if (y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] == '.') {
                q.push(Node(x, y - 1, up, down));
                visited[x][y - 1] = true;
            }
            // GO UP
            if (up < u && x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] == '.') {
                q.push(Node(x - 1, y, up + 1, down));
                visited[x - 1][y] = true;
            }
            // GO DOWN
            if (down < d && x + 1 < n && !visited[x + 1][y] && grid[x + 1][y] == '.') {
                q.push(Node(x + 1, y, up, down + 1));
                visited[x + 1][y] = true;
            }
        }

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
        int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;

        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }



        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";

    }

    return 0;
}


// } Driver Code Ends