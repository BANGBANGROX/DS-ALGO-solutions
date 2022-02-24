// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    vector<vector<int>> findDistance(vector<vector<char>>& matrix, int m, int n) {
        // Your code goes here
        int dx[4] = { 1,0,0,-1 };
        int dy[4] = { 0,-1,1,0 };
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 'B') {
                    q.push({ i,j });
                    distance[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> currentCell = q.front();
            q.pop();
            int x = currentCell.first;
            int y = currentCell.second;
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] == 'O'
                    && distance[newX][newY] > 1 + distance[x][y]) {
                    distance[newX][newY] = 1 + distance[x][y];
                    q.push({ newX,newY });
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][j] == INT_MAX) {
                    distance[i][j] = -1;
                }
            }
        }

        return distance;
    }
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int M, N;
        cin >> M;
        cin >> N;

        vector<vector<char> > matrix(M);
        for (int i = 0; i < M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin >> matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M, N);
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout << result[i][j] << " ";
            cout << "\n";
        }
    }

    return 0;
}  // } Driver Code Ends