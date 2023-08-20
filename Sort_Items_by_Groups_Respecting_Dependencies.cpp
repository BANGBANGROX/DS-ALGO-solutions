#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
    vector<int> getTopologicalSort(vector<vector<int>>& graph, 
        vector<int>& indegree, int n) {
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            result.push_back(node);
            q.pop();
            for (int child : graph[node]) {
                --indegree[child];
                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        if ((int)result.size() < n) {
            result.clear();
        }

        return result;
    }

public:
    vector<int> sortItems(int n, int m, vector<int>& group,
        vector<vector<int>>& beforeItems) {
        int groupId = m;

        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = groupId;
                ++groupId;
            }
        }

        vector<vector<int>> itemGraph(n);
        vector<vector<int>> groupGraph(groupId);
        vector<int> itemIndegree(n);
        vector<int> groupIndegree(groupId);

        for (int i = 0; i < n; ++i) {
            for (const int& node : beforeItems[i]) {
                itemGraph[node].push_back(i);
                ++itemIndegree[i];
                if (group[node] != group[i]) {
                    groupGraph[group[node]].push_back(group[i]);
                    ++groupIndegree[group[i]];
                }
            }
        }

        vector<int> itemSort = getTopologicalSort(itemGraph, itemIndegree, n);
        vector<int> groupSort = getTopologicalSort(groupGraph, groupIndegree, groupId);

        if (itemSort.empty() || groupSort.empty()) {
            return {};
        }

        unordered_map<int, vector<int>> orderedItems;
        vector<int> answer;

        for (const int& item : itemSort) {
            if (orderedItems.find(group[item]) == orderedItems.end()) {
                orderedItems[group[item]] = {};
            }
            orderedItems[group[item]].push_back(item);
        }

        for (const int& groupInd : groupSort) {
            for (const int& item : orderedItems[groupInd]) {
                answer.push_back(item);
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
        vector<int> group(n);
        vector<vector<int>> beforeItems(n);
        for (int& x : group) {
            cin >> x;
        }
        for (vector<int>& x : beforeItems) {
            int cnt;
            cin >> cnt;
            x = vector<int>(cnt);
            for (int& y : x) {
                cin >> y;
            }
        }

        Solution solution;
        vector<int> answer = solution.sortItems(n, m, group, beforeItems);
        for (const int& x : answer) {
            cout << x << " ";
        }
        cout << endl;
    }
}