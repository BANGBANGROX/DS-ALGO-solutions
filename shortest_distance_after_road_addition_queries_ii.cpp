#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> answer;
        unordered_map<int, int> tree;

        for (int i = 0; i < n - 1; ++i)
        {
            tree[i] = i + 1;
        }

        for (vector<int> &query : queries)
        {
            int u = query[0];
            int v = query[1];
            if (tree.find(u) == tree.end() || tree[u] >= v)
            {
                answer.push_back(tree.size());
                continue;
            }
            int node = tree[u];
            while (node < v)
            {
                int next = tree[node];
                tree.erase(node);
                node = next;
            }
            tree[u] = v;
            answer.push_back(tree.size());
        }

        return answer;
    }
};

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases-- > 0)
    {
        int n;
        cin >> n;
        int q;
        cin >> q;
        vector<vector<int>> queries(q, vector<int>(2));
        for (vector<int> &query : queries)
        {
            cin >> query[0] >> query[1];
        }

        vector<int> answer = (new Solution())->shortestDistanceAfterQueries(n, queries);
        for (int &x : answer)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}