// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int largestArea(int m, int n, int k, vector<vector<int>>& enemyLocation) {
        //  code here
        vector<int> rows;
        vector<int> cols;
        int largestRow = 0;
        int largestCol = 0;

        if (k == 0) return m * n;

        rows.push_back(0);
        cols.push_back(0);
        rows.push_back(m + 1);
        cols.push_back(n + 1);

        for (vector<int>& points : enemyLocation) {
            rows.push_back(points[0]);
            cols.push_back(points[1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        for (int i = 1; i < k + 2; ++i) {
            largestRow = max(largestRow, rows[i] - rows[i - 1] - 1);
            largestCol = max(largestCol, cols[i] - cols[i - 1] - 1);
        }

        return largestRow * largestCol;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int k;
        cin >> k;
        vector<vector<int>> e(k, vector<int>(2));
        for (int i = 0; i < k; i++)
            cin >> e[i][0] >> e[i][1];
        Solution a;
        cout << a.largestArea(n, m, k, e) << endl;
    }
    return 0;
}  // } Driver Code Ends