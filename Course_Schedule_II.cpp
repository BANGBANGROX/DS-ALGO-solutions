#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses), ans;
        vector<vector<int>> graph(numCourses);
        queue<int> q;

        for (const vector<int>& pair : prerequisites) {
            int u = pair[0], v = pair[1];
            graph[v].push_back(u);
            ++inDeg[u];
        }

        for (int i = 0; i < numCourses; ++i) {
            if (inDeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                ans.push_back(curr);
                q.pop();
                for (int node : graph[curr]) {
                    --inDeg[node];
                    if (inDeg[node] == 0) q.push(node);
                }
            }
        }
        if (ans.size() != numCourses) ans.clear();

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int numCourses, preq;
        cin >> numCourses >> preq;
        vector<vector<int>> prerequesites;
        for (int i = 0; i < preq; ++i) {
            int a, b;
            cin >> a >> b;
            prerequesites.push_back({ a,b });
        }

        Solution obj;
        vector<int> ans = obj.findOrder(numCourses, prerequesites);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}