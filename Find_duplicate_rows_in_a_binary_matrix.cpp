// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> repeatedRows(vector<vector<int>>& matrix, int m, int n) {
        // Your code here
        map<vector<int>, bool> mp;
        vector<int> res;

        for (int i = 0; i < m; ++i) {
            if (mp.find(matrix[i]) != mp.end()) {
                res.push_back(i);
                continue;
            }
            mp[matrix[i]] = true;
        }

        return res;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<int> > matrix(row);
        for (int i = 0; i < row; i++)
        {
            matrix[i].assign(col, 0);
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends