// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool ValidCorner(const vector<vector<int> >& matrix) {
        // Your code goes here
        int m = matrix.size();
        int n = matrix[0].size();
        set<pair<int, int>> onesIndexes;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    onesIndexes.insert({ i,j });
                }
            }
        }

        for (const pair<int, int>& index : onesIndexes) {
            int x = index.first;
            int y = index.second;
            for (int len = 1; x + len < m; ++len) {
                int newX = x + len;
                if (onesIndexes.find({ newX, y }) == onesIndexes.end()) continue;
                for (int bre = 1; y + bre < n; ++bre) {
                    int newY = y + bre;
                    if (onesIndexes.find({ newX, newY }) != onesIndexes.end() &&
                        onesIndexes.find({ x,newY }) != onesIndexes.end()) return true;
                }
            }
        }

        return false;
    }
};

// { Driver Code Starts.
int main()
{
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
        if (ob.ValidCorner(matrix))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}


// } Driver Code Ends
