#include<bits/stdc++.h>
using namespace std;

vector<int> graph[50005], compGraph[50005];
stack<int> vertex;
vector<bool> vis;

void dfs1(int node) {
    vis[node] = 1;

    for (int child : graph[node]) {
        if (!vis[child]) dfs1(child);
    }

    vertex.push(node);
}

void dfs2(int node) {
    vis[node] = 1;

    for (int child : compGraph[node]) {
        if (!vis[child]) dfs2(child);
    }
}

int kosaraju(int n, vector<int>* adj) {
    int scc = 0;

    for (int i = 0; i < n; ++i) {
        graph[i] = adj[i];
        compGraph[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        for (int child : graph[i]) {
            compGraph[child].push_back(i);
        }
    }
    vis.resize(n);

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs1(i);
    }

    for (int i = 0; i < n; ++i) vis[i] = 0;
    
    while (!vertex.empty()) {
        int node = vertex.top();
        vertex.pop();
        if (!vis[node]) {
            dfs2(node);
            ++scc;
        }
    }

    return scc;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int>* adj = new vector<int>[n];

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << kosaraju(n, adj) << endl;
    }

    return 0;
}