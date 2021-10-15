// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>>& matrix, int r, int c) {
        // code here 
        vector<int> res;
        int k = 0, l = 0; // k represents the first row not printed
                          // l represents the first col not printed

        while (k < r && l < c) {
            // Print the kth row
            for (int i = l; i < c; ++i) {
                res.push_back(matrix[k][i]);
            }
            ++k; // Ready to go to next row

            // Print the last col
            for (int i = k; i < r; ++i) {
                res.push_back(matrix[i][c - 1]);
            }
            --c; // Now we need the second last col next time 

            // Print the last row if possible
            if (k < r) {
                for (int i = c - 1; i >= l; --i) {
                    res.push_back(matrix[r - 1][i]);
                }
                --r; // Now we need the second last row next time
            }

            // Print the first col is possible
            if (l < c) {
                for (int i = r - 1; i >= k; --i) {
                    res.push_back(matrix[i][l]);
                }
                ++l; // Now we need the next col next time
            }
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
        int r, c;
        cin >> r >> c;
        vector<vector<int> > matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends