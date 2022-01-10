#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int count = 0;

    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& vis) {
        vis[node] = true;

        for (int child : rooms[node]) {
            if (!vis[child]) {
                dfs(child, rooms, vis);
            }
        }

        ++count;
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);

        dfs(0, rooms, vis);

        return count == n;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> rooms(n);
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                int x;
                cin >> x;
                rooms[i].push_back(x);
            }
        }

        Solution obj;
        if (obj.canVisitAllRooms(rooms)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}