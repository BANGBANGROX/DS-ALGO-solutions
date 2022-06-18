// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<string> ans;
    vector<vector<bool>> visited;
    pair<int, int> directions[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, 
        {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
    unordered_set<string> done;
    int m, n;

    void dfs(int x, int y, vector<vector<char>>& board, string& word, int index) {
        if (index == (int)word.size()) {
            if (done.find(word) != done.end()) return;
            ans.push_back(word);
            done.insert(word);
            return;
        }

        if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || 
            board[x][y] != word[index]) return;

        visited[x][y] = true;

        for (int i = 0; i < 8; ++i) {
            dfs(x + directions[i].first, y + directions[i].second, board, word, index + 1);
        }

        visited[x][y] = false;
    }

public:
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        // Code here
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n));

        for (string& word : dictionary) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == word[0]) dfs(i, j, board, word, 0);
                }
            }
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }

        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends