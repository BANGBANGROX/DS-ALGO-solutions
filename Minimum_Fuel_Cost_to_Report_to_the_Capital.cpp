#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

    vector<vector<int>> tree;
    int seats;
    ll ans;

    ll dfs(int node, int parent) {
        ll rep = 1;

        for (int child : tree[node]) {
            if (child != parent) {
                rep += dfs(child, node);
            }
        }

        if (node > 0) {
            ans += ceil((double) rep / seats);
        }

        return rep;
    }

public:
    ll minimumFuelCost(vector<vector<int>>& roads, int seats) {
          int n = (int) roads.size() + 1;
          this->seats = seats;
          ans = 0;
          tree = vector<vector<int>>(n);

          for (const vector<int>& road : roads) {
              int u = road[0];
              int v = road[1];
              tree[u].push_back(v);
              tree[v].push_back(u);
          }

          dfs(0, -1);

          return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
         int n;
         cin >> n;
         vector<vector<int>> roads(n - 1, vector<int>(2));
         for (int i = 0; i < n - 1; ++i) {
             cin >> roads[i][0] >> roads[i][1];
         }
         int seats;
         cin >> seats;

         Solution solution;
         cout << solution.minimumFuelCost(roads, seats);
    }

    return 0;
}
