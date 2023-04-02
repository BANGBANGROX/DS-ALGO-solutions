//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<int> parent;

    int DSUFind(int node) {
        if (parent[node] == node) return node;

        return parent[node] = DSUFind(parent[node]);
    }

    void DSUUnion(int node1, int node2) {
        int p1 = DSUFind(node1);
        int p2 = DSUFind(node2);

        if (p1 == p2) return;

        parent[p1] = p2;
    }

public:
    vector<string> avoidExplosion(vector<vector<int>> &mix, int m,
                                  vector<vector<int>> &danger, int n) {
        parent = vector<int>(m);
        vector<string> ans;

        for (int i = 0; i < m; ++i) {
            parent[i] = i;
        }

        for (vector<int> &currentMix : mix) {
            int a = currentMix[0];
            int b = currentMix[1];
            int pa = DSUFind(a);
            int pb = DSUFind(b);
            bool canMix = true;
            for (vector<int> &currentDanger : danger) {
                int x = currentDanger[0];
                int y = currentDanger[1];
                int px = DSUFind(x);
                int py = DSUFind(y);
                if ((pa == px && pb == py) || (pa == py && pb == px)) {
                    canMix = false;
                    break;
                }
            }
            if (canMix) {
                ans.emplace_back("Yes");
                DSUUnion(a, b);
            }
            else {
                ans.emplace_back("No");
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends