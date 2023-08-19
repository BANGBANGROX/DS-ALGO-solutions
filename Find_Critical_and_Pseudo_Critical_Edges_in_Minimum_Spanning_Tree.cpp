#include<bits/stdc++.h>
using namespace std;

class Solution {
    static class UnionFind {
        vector<int> parent;
        vector<int> size;

        int getParent(int node) {
            if (parent[node] == node) {
                return node;
            }

            return parent[node] = getParent(parent[node]);
        }

    public:
        int maxSize;

        UnionFind(int n) {
            parent = vector<int>(n);
            size = vector<int>(n, 1);
            maxSize = 1;

            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        bool computeUnion(int x, int y) {
            int rootX = getParent(x);
            int rootY = getParent(y);

            if (rootX == rootY) {
                return false;
            }

            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }

            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            maxSize = max(maxSize, size[rootX]);

            return true;
        }
    };

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n,
        vector<vector<int>>& edges) {
        int m = (int)edges.size();
        int stdWt = 0;
        vector<vector<int>> sortedEdges(m, vector<int>(4));
        vector<vector<int>> answer(2);
        UnionFind uf(n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < 3; ++j) {
                sortedEdges[i][j] = edges[i][j];
            }
            sortedEdges[i][3] = i;
        }

        sort(sortedEdges.begin(), sortedEdges.end(),
            [&](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            });

        for (int i = 0; i < m; ++i) {
            // cout << sortedEdges[i][0] << " " << sortedEdges[i][1] << " " << sortedEdges[i][2] << " " << sortedEdges[i][3] << "\n";
            if (uf.computeUnion(sortedEdges[i][0], sortedEdges[i][1])) {
                stdWt += sortedEdges[i][2];
            }
        }

        // cout << stdWt << endl;

        for (int i = 0; i < m; ++i) {
            UnionFind ufIgnore(n);
            int ignoreWt = 0;
            for (int j = 0; j < m; ++j) {
                if (i != j &&
                    ufIgnore.computeUnion(sortedEdges[j][0], sortedEdges[j][1])) {
                    ignoreWt += sortedEdges[j][2];
                }
            }
            // cout << i << " " << ufIgnore.maxSize << " " << ignoreWt << endl; 
            if (ufIgnore.maxSize < n || ignoreWt > stdWt) {
                answer[0].push_back(sortedEdges[i][3]);
            }
            else {
                int forceTakeWt = sortedEdges[i][2];
                UnionFind ufTake(n);
                ufTake.computeUnion(sortedEdges[i][0], sortedEdges[i][1]);
                for (int j = 0; j < m; ++j) {
                    if (i != j &&
                        ufTake.computeUnion(sortedEdges[j][0], sortedEdges[j][1])) {
                        forceTakeWt += sortedEdges[j][2];
                    }
                }
                if (forceTakeWt == stdWt) {
                    answer[1].push_back(sortedEdges[i][3]);
                }
            }
        }

        return answer;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(m, vector<int>(3));

        for (vector<int>& x : edges) {
            for (int& y : x) {
                cin >> y;
            }
        }

        Solution solution;
        vector<vector<int>> answer = solution.findCriticalAndPseudoCriticalEdges(n, edges);
        for (vector<int>& x : answer) {
            for (int& y : x) {
                cout << y << " ";
            }
            cout << endl;
        }
    }
}