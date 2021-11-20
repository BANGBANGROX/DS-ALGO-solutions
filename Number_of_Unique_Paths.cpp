// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b) {
        //code here
        vector<vector<int>> grid(a, vector<int>(b));

        grid[a - 1][b - 1] = 1;

        for (int i = b - 2; i > -1; --i) grid[a - 1][i] = 1;
        for (int i = a - 2; i > -1; --i) grid[i][b - 1] = 1;

        for (int i = a - 2; i > -1; --i) {
            for (int j = b - 2; j > -1; --j) {
                grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
            }
        }

        return grid[0][0];
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking dimensions of the matrix
        int a, b;
        cin >> a >> b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a, b) << endl;
    }
}

// } Driver Code Ends