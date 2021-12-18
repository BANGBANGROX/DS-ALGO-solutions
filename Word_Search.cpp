#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dx[4] = { -1,0,0,1 };
    int dy[4] = { 0,1,-1,0 };
    vector<vector<bool>> vis;

    bool isValid(int x, int y, vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        return x > -1 && y > -1 && x < m && y < n && vis[x][y] == false;
    }

    bool search(int x, int y, vector<vector<char>>& board, string word, int ind) {
        int size = word.size();

        if (ind == size) return true;

        if (board[x][y] != word[ind]) return false;

        vis[x][y] = true;
        
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i], newY = y + dy[i];
            if (isValid(newX, newY, board)) {
                bool res = search(newX, newY, board, word, ind + 1);
                if (res) return true;
            }
        }

        vis[x][y] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (word[0] == board[i][j]) {
                    if (search(i, j, board, word, 0)) return true;
                }
            }
        }

        return false;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m, n;
        string word;
        cin >> m >> n;
        vector<vector<char>> board(m, vector<char>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        cin >> word;

        Solution obj;
        if (obj.exist(board, word)) cout << "Word Found\n";
        else cout << "Not found\n";
    }

    return 0;
}