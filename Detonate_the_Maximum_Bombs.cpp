#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis, int* cnt) {
        vis[node] = true;
        *cnt = *cnt + 1;

        for (int child : graph[node]) {
            if (!vis[child]) {
                dfs(child, graph, vis, cnt);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), ans = 0;
        vector<vector<int>> graph(n);
        vector<bool> vis(n);

        for (int i = 0; i < n; ++i) {
            ll h = bombs[i][0], k = bombs[i][1], r = bombs[i][2];
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                ll x = bombs[j][0], y = bombs[j][1];
                if ((x - h) * (x - h) + (y - k) * (y - k) - r * r <= 0) {
                    graph[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            dfs(i, graph, vis, &cnt);
            ans = max(ans, cnt);
            for (int i = 0; i < n; ++i) {
                vis[i] = false;
            }
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> bombs;
        for (int i = 0; i < n; ++i) {
            int x, y, r;
            cin >> x >> y >> r;
            bombs.push_back({ x,y,r });
        }

        Solution obj;
        cout << obj.maximumDetonation(bombs) << endl;
    }

    return 0;
}
