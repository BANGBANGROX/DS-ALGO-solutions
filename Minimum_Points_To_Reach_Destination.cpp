//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minPoints(vector<vector<int>> points, int m, int n) {
        // Your code goes here
        points[m - 1][n - 1] = min(points[m - 1][n - 1], 0);

        for (int i = m - 2; i >= 0; --i) {
            points[i][n - 1] = min(points[i + 1][n - 1] + points[i][n - 1], 0);
        }

        for (int i = n - 2; i >= 0; --i) {
            points[m - 1][i] = min(points[m - 1][i + 1] + points[m - 1][i], 0);
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                points[i][j] = min(0, points[i][j] + 
                    max(points[i + 1][j], points[i][j + 1]));
            }
        }

        return abs(points[0][0]) + 1;
    }
};


//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];



        Solution ob;
        cout << ob.minPoints(a, m, n) << "\n";

    }
    return 0;
}

// } Driver Code Ends